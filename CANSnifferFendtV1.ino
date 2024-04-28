/*  
 *  CANBox for Fendt 
 *  2024  Bacom Software
 *  V1.0
 *  www.bacom.be  info@bacom.be
 */

#include <mcp_can.h>   
#include <SPI.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];

#define CAN0_INT 2                // Interrupt an pin 2
MCP_CAN CAN0(10);                 // Chip Select an pin 10

void setup()
{
  Serial.begin(115200);

  // Set to 250KBPS for SCR/S4 , 500KBPS for Fendt ONE
  
  if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK)    
    Serial.println("MCP2515 Initialized Successfully!");
  else
    Serial.println("Error Initializing MCP2515...");
  
  CAN0.setMode(MCP_NORMAL);         
  pinMode(CAN0_INT, INPUT);                                     
  Serial.println("");
  Serial.println("Listening to Fendt K-BUS...");
}

void loop()
{
  unsigned long currentTimeMicros = micros();

  if(!digitalRead(CAN0_INT))                                 
  {
    CAN0.readMsgBuf(&rxId, &len, rxBuf);          
    // special characters are added to split package in the windows software    
      Serial.print("&");
      Serial.print(rxId, HEX);                               
      Serial.print("$");       
      Serial.print("K");   
      Serial.print(rxBuf[1],HEX);      
      Serial.print(" ");                                     
      Serial.print(rxBuf[2],HEX);    
      Serial.print(" ");                                     
      Serial.print(rxBuf[3],HEX);    
      Serial.print(" ");                                     
      Serial.print(rxBuf[4],HEX);    
      Serial.print(" ");                                     
      Serial.print(rxBuf[5],HEX);    
      Serial.print(" ");                                     
      Serial.print(rxBuf[6],HEX);    
      Serial.println("Z");                                      
  
 
  }
delay(10);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
