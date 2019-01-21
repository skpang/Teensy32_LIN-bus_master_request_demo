/*
 *  * This is a Teensy 3.2 LIN-Bus demo using this board:
 * http://skpang.co.uk/catalog/teensy-canbus-and-linbus-breakout-board-include-teensy-32-p-1566.html
 * 
 * It is used to read the status of the Microchip APGRD004 LIN RGB LED.
 * 
 * skpang.co.uk 2019
 * 
 * 
 * 
 * 
 * 
 */
#include "lin-bus.h"

int led = 13;
int lin_cs = 23;
int tx_pin = 1;

lib_bus lin(19200,1);

uint8_t lin_data[8]; 
void setup() 
{
  pinMode(led, OUTPUT);    
  pinMode(lin_cs, OUTPUT); 
  digitalWrite(led, HIGH);   
  digitalWrite(lin_cs, HIGH);    
  
  delay(1000);  
  Serial.begin(11520);            // Configure serial port for debug
  Serial.print("LIN-bus test");

  delay(100);
   
  digitalWrite(led, LOW); 
}

void loop() 
{
    lin.write_request(0x24);
    lin.read_request(lin_data,5);
    
    Serial.print("Read data : ");
    for(uint8_t i =0;i<5;i++)
    {
        Serial.print(lin_data[i],HEX);
        Serial.print(" ");
    }
    Serial.println(" ");

   digitalWrite(led, HIGH);   
   delay(1000); 
   digitalWrite(led, LOW);  
}
