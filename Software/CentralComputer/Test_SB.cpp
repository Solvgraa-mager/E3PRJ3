#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "SPIMaster.h"
#include <string>



int main(void)
{   
   
    int bufferLength = 8;
    char buffer[bufferLength];  //Receiver buffer;
    memset(buffer, 0, bufferLength);

    string SSID = "SumoBot";
    string passphrase = "12345678";
    string IPaddress = "192.168.0.1"; //CC_RPI IPaddress
    int playerNr = 2;

    string attackStatus = "0";
 
	CentralComputerIF C1(SSID, passphrase, IPaddress, playerNr); //connect to CC

    while(true)
    {

        cout << "AttackStauts = " << attackStatus << endl;

        C1.getDirSpeed(attackStatus, buffer, bufferLength); //Send attackStatus, Receive dir|speed.

        cout << buffer << endl; //dir|speed

    }

  return 0;
}


// int main(void)
// {   
   
//     int bufferLength = 8;
//     char buffer[bufferLength];  //Receiver buffer;
//     memset(buffer, 0, bufferLength);

//     string SSID = "SumoBot";
//     string passphrase = "12345678";
//     string IPaddress = "192.168.0.1"; //CC_RPI IPaddress
//     int playerNr = 1;

//     string attackStatus = "0";

// 	CentralComputerIF C1(SSID, passphrase, IPaddress, playerNr); //connect to CC

//     while(true)
//     {

//         cout << "AttackStauts = ";
//         getlin(cin, attackStatus); //get attackStatus
//         cout << endl;

//         C1.getDirSpeed(attackStatus, buffer, bufferLength); //Send attackStatus, Receive dir|speed.

//         cout << buffer << endl; //dir|speed

//     }

//   return 0;
// }





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




