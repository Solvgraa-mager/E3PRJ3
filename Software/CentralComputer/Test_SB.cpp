#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "SPIMaster.h"
#include <string>


 int main(void)
 {   
  
 //Allocations  
  int receiverBufferLength = 8;
  char receiverBuffer[receiverBufferLength];  //Receiver buffer;
  memset(receiverBuffer, 0, receiverBufferLength); //fill receiverBuffer with 0;
  bool attackStatus;
  int count;
  
  //Info for Wifi Connection
  string SSID = "SumoBot";
  string passphrase = "12345678";
  string IPaddress = "192.168.0.1"; //CC_RPI IPaddress

  CentralComputerIF C1(SSID, passphrase, IPaddress, 1); //connect to Wifi og vha TCP til Central Computer. Det sidste parameter er player-number

  while(true)
  {
    C1.getDirSpeed((attackStatus == true ? "1" : "0"), receiverBuffer, receiverBufferLength); //Send attackStatus, Receive dir|speed.
    
    //Her skal være noget kode som opdateret attackStatus ift. om I er blevet attacked

    //Her skal være noget kode som skiller receiveBuffer ad. Eksempel på receiveBuffer "30|-45"
    //fscanf("%i|%i", speed, direction)

     //Her skal være noget kode som får motoren til at køre jf speed og dir
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




