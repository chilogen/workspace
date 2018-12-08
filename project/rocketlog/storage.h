#include <SD.h>
#include <SPI.h>

struct Storage{
  File dataFile;
  void open(String filename);
  void write(String buf);
  };
  


void Storage::open(String filename){
  dataFile = SD.open(filename, FILE_WRITE);
  }

void Storage::write(String buf){
  dataFile.println(buf);
  }
  