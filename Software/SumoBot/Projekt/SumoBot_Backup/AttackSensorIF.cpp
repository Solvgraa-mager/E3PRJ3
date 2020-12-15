#include "AttackSensorIF.h"

AttackSensorIF::AttackSensorIF()
{
    int fd, error;
    char attack_buf[attack_buf_SIZE];
    memset(attack_buf, 0, attack_buf_SIZE); //fills attack_buf med 0'er.

    fd = open("/dev/ATTACK", O_RDONLY);
    if (fd < 0)
    {
        cout << "Could not read ATTACK-node" << endl;
    }
    error = read(fd, attack_buf, sizeof(attack_buf));
    if (error < 0)
        cout << "Could not read ATTACK-node" << endl;

    sscanf(attack_buf, "%d", &attackStatus_); //Kalibrering of attackstatus. Konverterer char array om til int.

    close(fd);
}

AttackSensorIF::~AttackSensorIF()
{
}

bool AttackSensorIF::getAttackStatus()
{
    int fd, error;
    int temp_attackStatus;
    char attack_buf[attack_buf_SIZE];
    memset(attack_buf, 0, attack_buf_SIZE);

    fd = open("/dev/ATTACK", O_RDONLY);
    if (fd < 0)
    {
        cout << "Could not open ATTACK-node" << endl;
    }
    error = read(fd, attack_buf, sizeof(attack_buf));
    if (error < 0)
        cout << "Could not read ATTACK-node" << endl;

    sscanf(attack_buf, "%d", &temp_attackStatus);

    if(temp_attackStatus != attackStatus_)
    {
        attackStatus_ = temp_attackStatus;

        close(fd); // closes the attackNode

        return true;
    }
    else
    {
        close(fd); // closes the attackNode

        return false;
    }
}