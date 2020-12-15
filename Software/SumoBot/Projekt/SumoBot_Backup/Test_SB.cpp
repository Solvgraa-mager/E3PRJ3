#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "SPIMaster.h"
#include "AttackSensorIF.h"
#include "MotorstyringIF.h"
#include <string>


 int main(void)
 {   
  
 //Allocations  
  int receiverBufferLength = 8;
  char receiverBuffer[sizeof(receiverBufferLength)];  //Receiver buffer;
  memset(receiverBuffer, 0, receiverBufferLength); //fill receiverBuffer with 0;
  bool attackStatus = 0;
  int count;
  
  //Info for Wifi Connection
  string SSID = "SumoBot";
  string passphrase = "12345678";
  string IPaddress = "192.168.0.1"; //CC_RPI IPaddress

  CentralComputerIF C1(SSID, passphrase, IPaddress, 1); //connect to Wifi og vha TCP til Central Computer. Det sidste parameter er player-number

  AttackSensorIF s1;

  MotorstyringIF motor;

  char sekvens1[] = {'7','7','|','0','\0' };
  while(true)
  {
    C1.getDirSpeed((attackStatus == true ? "1" : "0"), receiverBuffer, receiverBufferLength); //Send attackStatus, Receive dir|speed.
    
    //Her skal være noget kode som opdateret attackStatus ift. om I er blevet attacked
    attackStatus = s1.getAttackStatus();

    motor.setSpeedDir(sekvens1); //byt til recievebuffer
  }

   return 0;
 }