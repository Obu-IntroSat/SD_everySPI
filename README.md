# SD_everySPI
Modified SD library with function to choose SPI that SD card is connected to.

## Differences with standard Arduino SD library:

You can choose desired SPI which SD card is connected to. In case to choose SPI you should pass the SPIClass object as the first argument to the method *begin*:

SD.begin(SPI_x, chipSelectPin); 
  - SPI_x - SPIClass object 
  - chipSelectPin - CS pin attached to SD card
