
// Include Libraries
#include "Arduino.h"
#include "PIR.h"
#include "Fan.h"
#include "DHT.h"


// Pin Definitions
#define PIR_PIN_SIG	2
#define PCFAN_PIN_COIL1	1
#define PULLPUSHSOLENOID_PIN_SIG	4
#define DHT_PIN_DATA	0
#define MQ5_3V3_PIN_AOUT	12
#define MQ8_3V3_PIN_AOUT	13



// Global variables and defines

// object initialization
PIR pir(PIR_PIN_SIG);
Fan PCFan(PCFAN_PIN_COIL1);
DHT dht(DHT_PIN_DATA);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    pinMode(PULLPUSHSOLENOID_PIN_SIG, OUTPUT);
    dht.begin();
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // Infrared PIR Motion Sensor Module - Test Code
    bool pirVal = pir.read();
    Serial.print(F("Val: ")); Serial.println(pirVal);

    }
    else if(menuOption == '2') {
    // PC Fan 12V - Test Code
    // The PC Fan will turn on for 2000ms and off for 4000ms (4 sec)
    PCFan.on(); // 1. turns on
    delay(2000);       // 2. waits 2000 milliseconds (2 sec).
    PCFan.off();// 3. turns off
    delay(4000);       // 4. waits 4000 milliseconds (4 sec).

    }
    else if(menuOption == '3') {
    // Solenoid Push-Pull - 5v (Small) - Test Code
    digitalWrite(PULLPUSHSOLENOID_PIN_SIG, HIGH); //Turn Solenoid on. 
    delay(1000);  //waits 1000 milliseconds (1 sec). change the value in the brackets (1000) for a longer or shorter delay in milliseconds.
    digitalWrite(PULLPUSHSOLENOID_PIN_SIG, LOW); //Turn Solenoid off. 
    delay(1000);  //waits 1000 milliseconds (1 sec). change the value in the brackets (1000) for a longer or shorter delay in milliseconds.
    }
    else if(menuOption == '4') {
    // DHT22/11 Humidity and Temperature Sensor - Test Code
    // Reading humidity in %
    float dhtHumidity = dht.readHumidity();
    // Read temperature in Celsius, for Fahrenheit use .readTempF()
    float dhtTempC = dht.readTempC();
    Serial.print(F("Humidity: ")); Serial.print(dhtHumidity); Serial.print(F(" [%]\t"));
    Serial.print(F("Temp: ")); Serial.print(dhtTempC); Serial.println(F(" [C]"));

    }
    else if(menuOption == '5')
    {
    // Disclaimer: The LPG, Natural and Coal Gas Sensor - MQ-5 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    else if(menuOption == '6')
    {
    // Disclaimer: The Hydrogen Gas Sensor - MQ-8 is in testing and/or doesn't have code, therefore it may be buggy. Please be kind and report any bugs you may find.
    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Infrared PIR Motion Sensor Module"));
    Serial.println(F("(2) PC Fan 12V"));
    Serial.println(F("(3) Solenoid Push-Pull - 5v (Small)"));
    Serial.println(F("(4) DHT22/11 Humidity and Temperature Sensor"));
    Serial.println(F("(5) LPG, Natural and Coal Gas Sensor - MQ-5"));
    Serial.println(F("(6) Hydrogen Gas Sensor - MQ-8"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing Infrared PIR Motion Sensor Module"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing PC Fan 12V"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing Solenoid Push-Pull - 5v (Small)"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing DHT22/11 Humidity and Temperature Sensor"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing LPG, Natural and Coal Gas Sensor - MQ-5 - note that this component doesn't have a test code"));
    		else if(c == '6') 
    			Serial.println(F("Now Testing Hydrogen Gas Sensor - MQ-8 - note that this component doesn't have a test code"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/