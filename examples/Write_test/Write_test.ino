/*
  Modified SD datalogger test.

  This example shows how to write data to SD card via SPI interface.

  SD card has to be formatted to FAT32 format with sector size up to 4096.

  What's the difference? You can pass the SPIClass object as an argument 
  while using method "begin" of SD class. The second argument is still 
  CS pin name:

      SD.begin(SPI_x, ChipSelect_pin);

  It is used standart SPI and CS pin PA4 in the example.
  
  created  24 Mar 2025

  by unflesh
*/

#include <SPI.h>
#include <SD_everySPI.h>
#include <Wire.h>

/* To create a new SPIClass object with modified pins:
 * const int MOSIpin = ;
 * const int MISOpin = ;
 * const int SCLKpin = ;
 * const int chipSelect = ;
 *
 * SPIClass SPI_x(MOSIpin, MISOpin, SCLKpin); */

const int chipSelect = PA4;

void setup() {
  Serial.begin(115200, SERIAL_8E1);

  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(SPI, chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
}

void loop() {
  // make a string for assembling the data to log:
  String dataString = "Hi, I'm IntroStrat!\n";

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
  delay(1000);           // wait 1 second for the next loop
}
