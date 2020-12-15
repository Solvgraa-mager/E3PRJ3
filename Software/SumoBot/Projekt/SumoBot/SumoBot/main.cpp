#include <string>
#include "CentralComputerIF.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "MotorstyringIF.h"
#include "SPIMaster.h"
#include "AttackSensorIF.h"
#include "UC1.h"

 int main(void)
 {   
	//Info for Wifi Connection
   string SSID = "SumoBot";
   string passphrase = "12345678";
   string IPaddress = "192.168.0.1"; //CC_RPI IPaddress
   string MAC = "b827eb7e8cc5"; // MAC adress for my RPI
   int playerNr = 1; //Spiller nummer

   UC1 SumoPlayer1(SSID, passphrase, IPaddress, MAC, playerNr);

   SumoPlayer1.run();

   return 0;
 }