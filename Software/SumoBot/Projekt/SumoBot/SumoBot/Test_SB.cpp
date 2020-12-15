#include <string>
#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "MotorstyringIF.h"
#include "SPIMaster.h"
#include "AttackSensorIF.h"

 int main(void)
 {   
  
 //Allocations  
  // int receiverBufferLength = 8;
  // char receiverBuffer[sizeof(receiverBufferLength)];  //Receiver buffer;
  // memset(receiverBuffer, 0, receiverBufferLength); //fill receiverBuffer with 0;
  // bool attackStatus = 0;
  // int count;
  
  //Info for Wifi Connection
  // string SSID = "SumoBot";
  // string passphrase = "12345678";
  // string IPaddress = "192.168.0.1"; //CC_RPI IPaddress
  // string MAC = "b827eb7e8cc5"; // MAC adress for my RPI

  // CentralComputerIF C1(SSID, passphrase, IPaddress, MAC, 1); //connect to Wifi og vha TCP til Central Computer. Det sidste parameter er player-number

  // AttackSensorIF s1;

  MotorstyringIF motor;

  char sekvens1[] = {'-','3','7','|','0','\0' };
  char sekvens2[] = {'4','4','|','5','0','\0' };
  char sekvens3[] = {'-','7','5','|','-','9','0','\0' };
  char sekvens4[] = {'3','0','|','0','\0' };
  char sekvens5[] = {'5','0','|','9','0','\0' };
  char sekvens6[] = {'-','7','7','|','-','5','5','\0' };
  while(true)
  {
   // C1.getDirSpeed((attackStatus == true ? "1" : "0"), receiverBuffer, receiverBufferLength); //Send attackStatus, Receive dir|speed.
    
    //Her skal v�re noget kode som opdateret attackStatus ift. om I er blevet attacked
   // attackStatus = s1.getAttackStatus();

    motor.setSpeedDir(sekvens1); //byt til recievebuffer
    delay(1000);
    motor.setSpeedDir(sekvens2);
    delay(1000);
    motor.setSpeedDir(sekvens3);
    delay(1000);
    motor.setSpeedDir(sekvens4);
    delay(1000);
    motor.setSpeedDir(sekvens5);
    delay(1000);
    motor.setSpeedDir(sekvens6);
    delay(1000);
  }

   return 0;
 }