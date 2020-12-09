#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "SPIMaster.h"
#include <string>


 int main(void)
 {   
   
  int receiverBufferLength = 8;
  char receiverBuffer[receiverBufferLength];  //Receiver buffer;
  memset(receiverBuffer, 0, receiverBufferLength); //fill receiverBuffer with 0;
   
  
  string SSID = "SumoBot";
  string passphrase = "12345678";
  string IPaddress = "192.168.0.1"; //CC_RPI IPaddress

  string attackStatus = "0";

  int playerNr;
  cout << "Enter player Nr: "; cin >> playerNr; cout << endl;

 	CentralComputerIF C1(SSID, passphrase, IPaddress, playerNr); //connect to CC

  int count;

  while(true)
  {
    C1.getDirSpeed(attackStatus, receiverBuffer, receiverBufferLength); //Send attackStatus, Receive dir|speed.
    
    if (count == 10)
      attackStatus = "1";
    else
      attackStatus = "0";
    count ++;
  }

   return 0;
 }





//***************************TEST A2********************
//   Wifi W2;
//     TCPClient TCPC;

//     string IPaddress = "192.168.0.1";
//     int port = 54001;
//     string attackStatus = "0";
//     int bufferLength = 7;
//     char buffer[bufferLength];


//     W2.connectToWifi("SumoBot","12345678");

//     TCPC.connectToServer(IPaddress, port);

//     TCPC.receiveMsg(buffer, bufferLength);

//     cout << buffer << endl;
    
//     TCPC.sendMsg(attackStatus);

//     cout << "press any key to disconnect" << endl;
//     cin.get();

// 	return 0;




