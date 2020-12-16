#include <linux/gpio.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/module.h>

#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/sched.h>


#define ATTACK_MAJOR 57
#define ATTACK_MINOR 1
#define NO_MINORS 1
#define Attack_GPIO 16

static int devno;
static struct cdev my_cdev;
static int IRQline;
struct file_operations my_fops;
static int interrupts = 0; //Global varibel, reseted

static DECLARE_WAIT_QUEUE_HEAD(wq);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR("Gruppe6");
MODULE_DESCRIPTION("Interrupt_Driver_SumoBot");

//Interrupt Handler

static irqreturn_t mygpio_isr(int irq, void *dev_id) {
	interrupts++;
    printk(KERN ALERT "Interrupt accured, global varible incremented by 1");
  return IRQ_HANDLED;
}

static int mygpio_init(void)
 {
    int error;
    // Request GPIO
    error = gpio_request(Attack_GPIO, "Attack_driver");
    if (error < 0)
        {
        printk("error in GPIO request\n");
        goto error_pgio_request;
        }

    // Set GPIO direction (in or out)
    error = gpio_direction_input(Attack_GPIO);
    if (error < 0)
    {
        printk("error in direction\n");
        goto error_gpio_direction_input;
    }
    // Make device no
    devno = MKDEV(ATTACK_MAJOR, ATTACK_MINOR);

     // Register Device
    error = register_chrdev_region(devno, NO_MINORS, "Attack_driver");
    if (error < 0)
    {
        printk("error in char dev register\n");
        goto error_register_chrdev_region;
    }
    // Cdev Init
    cdev_init(&my_cdev, &my_fops);

    // Add Cdev
    error = cdev_add(&my_cdev, devno, NO_MINORS);
    if (error < 0)
    {
        printk("error in addding cdev\n");
        goto error_dev_add;
    }

    //Requester IRQ linje
    IRQline = gpio_to_irq(Attack_GPIO);
    printk("IRQline to request: %i\n", IRQline);

    error = request_irq(IRQline, mygpio_isr, IRQF_TRIGGER_FALLING, "GpioInt", NULL);

    printk("IRQline requested: %i \nrequest_isr returned: %i\n", IRQline, error);

    return 0;

    error_dev_add:
    cdev_del(&my_cdev);

    error_register_chrdev_region:
    unregister_chrdev_region(devno, NO_MINORS);

    error_gpio_direction_input:
    gpio_free(Attack_GPIO);

    error_pgio_request:

    return -1;

 }

static void mygpio_exit(void)
 {
    // Delete Cdev
    cdev_del(&my_cdev);

    // Unregister Device
    unregister_chrdev_region(devno, NO_MINORS);

    // Free GPIO
    gpio_free(Attack_GPIO);

    //Release ISRLine
    free_irq(IRQline, NULL);
 }


  int mygpio_open(struct inode *inode, struct file *filep)
 {
 int major, minor;

 major = MAJOR(inode->i_rdev);
 minor = MINOR(inode->i_rdev);
 printk("Opening MyGpio Device [major], [minor]: %i, %i\n", major, minor);
 return 0;

 }

 int mygpio_release(struct inode *inode, struct file *filep)
 {
 int minor, major;
 major = MAJOR(inode->i_rdev);
 minor = MINOR(inode->i_rdev);
 printk("Closing/Releasing MyGpio Device [major], [minor]: %i, %i\n", major, minor);

 return 0;
 }

ssize_t mygpio_read(struct file *filep, char __user *buf, size_t count, loff_t *f_pos)
 {
 	char my_buf[1024] = {0};
    int my_buf_length = sizeof(interrupts);
    size_t readStatus = 0;

    my_buf_length = my_buf_length > count ? count : my_buf_length;

    sprintf(my_buf, "%i", interrupts);

    readStatus = copy_to_user(buf, my_buf, my_buf_length);

    return my_buf_length;
 }


module_init(mygpio_init);
module_exit(mygpio_exit);

struct file_operations my_fops = {
    .open = mygpio_open,
    .release = mygpio_release,
    .read = mygpio_read,
};