#define GPRMC_TERM "$GPRMC,"    //定义要解析的指令，因为这条指令包含定位和时间信息

struct GPS{
  Storage store;
  char nmeaSentence[68];
  String latitude;    //纬度
  String longitude;   //经度
  String lndSpeed;    //速度
  String gpsTime;     //UTC时间，本初子午线经度0度的时间，和北京时间差8小时
  String beiJingTime;   //北京时间
  String parseGprmcLat(String s);
  String getBeiJingTime(String s);
  String parseGprmcLon(String s);
  String parseGprmcSpeed(String s);
  String parseGprmcTime(String s);
  void init();
  void read();
  void write(String curtime);
  };


void GPS::init(){
  this->store.open("GPS.log");
  }


void GPS::read(){
  for (unsigned long start = millis(); millis() - start < 1000;){  //一秒钟内不停扫描GPS信息
    while (Serial.available()){  //串口获取到数据开始解析
      char c = Serial.read();  //读取一个字节获取的数据
      if(c=='$'){
        Serial.readBytesUntil('*', nmeaSentence, 67);
        }
    }
  }
  latitude = parseGprmcLat(nmeaSentence); //获取纬度值
  longitude = parseGprmcLon(nmeaSentence);//获取经度值
  lndSpeed = parseGprmcSpeed(nmeaSentence);//获取速度值
  gpsTime = parseGprmcTime(nmeaSentence);//获取GPS时间
  }


void GPS::write(String curtime){
  this->read();
  this->store.write("time : "+curtime);
  this->store.write("latitude: " + latitude);
  this->store.write("longitude: " + longitude);
  this->store.write("Speed (knots): " + lndSpeed);
  this->store.write("gpsTime: " + gpsTime);
  this->store.write("beiJingTime: " + beiJingTime);
  }


String GPS::getBeiJingTime(String s){
  int hour = s.substring(0,2).toInt();
  int minute = s.substring(2,4).toInt();
  int second = s.substring(4,6).toInt();

  hour += 8;

  if(hour > 24){
    hour -= 24;
  }
  s = String(hour) + String(minute) + String(second);
  return s;
}

String GPS::parseGprmcLat(String s){
  int pLoc = 0; //paramater location pointer
  int lEndLoc = 0; //lat parameter end location
  int dEndLoc = 0; //direction parameter end location
  String lat;
  /*make sure that we are parsing the GPRMC string. 
   Found that setting s.substring(0,5) == "GPRMC" caused a FALSE.
   There seemed to be a 0x0D and 0x00 character at the end. */
  if(s.substring(0,4) == "GPRM"){
    //Serial.println(s);
    for(int i = 0; i < 5; i++){
      if(i < 3) {
        pLoc = s.indexOf(',', pLoc+1);
      }
      if(i == 3){
        lEndLoc = s.indexOf(',', pLoc+1);
        lat = s.substring(pLoc+1, lEndLoc);
      }
      else{
        dEndLoc = s.indexOf(',', lEndLoc+1);
        lat = lat + " " + s.substring(lEndLoc+1, dEndLoc);
      }
    }
    return lat; 
  }
}


String GPS::parseGprmcLon(String s){
  int pLoc = 0; //paramater location pointer
  int lEndLoc = 0; //lat parameter end location
  int dEndLoc = 0; //direction parameter end location
  String lon;

  /*make sure that we are parsing the GPRMC string. 
   Found that setting s.substring(0,5) == "GPRMC" caused a FALSE.
   There seemed to be a 0x0D and 0x00 character at the end. */
  if(s.substring(0,4) == "GPRM"){
    //Serial.println(s);
    for(int i = 0; i < 7; i++){
      if(i < 5) {
        pLoc = s.indexOf(',', pLoc+1);
      }
      if(i == 5){
        lEndLoc = s.indexOf(',', pLoc+1);
        lon = s.substring(pLoc+1, lEndLoc);
      }
      else{
        dEndLoc = s.indexOf(',', lEndLoc+1);
        lon = lon + " " + s.substring(lEndLoc+1, dEndLoc);
      }
    }
    return lon; 
  }
}


String GPS::parseGprmcSpeed(String s){
  int pLoc = 0; //paramater location pointer
  int lEndLoc = 0; //lat parameter end location
  int dEndLoc = 0; //direction parameter end location
  String lndSpeed;

  /*make sure that we are parsing the GPRMC string. 
   Found that setting s.substring(0,5) == "GPRMC" caused a FALSE.
   There seemed to be a 0x0D and 0x00 character at the end. */
  if(s.substring(0,4) == "GPRM"){
    //Serial.println(s);
    for(int i = 0; i < 8; i++){
      if(i < 7) {
        pLoc = s.indexOf(',', pLoc+1);
      }
      else{
        lEndLoc = s.indexOf(',', pLoc+1);
        lndSpeed = s.substring(pLoc+1, lEndLoc);
      }
    }
    return lndSpeed; 
  }
}

String GPS::parseGprmcTime(String s){
  int pLoc = 0; //paramater location pointer
  int lEndLoc = 0; //lat parameter end location
  int dEndLoc = 0; //direction parameter end location
  String gpsTime;

  /*make sure that we are parsing the GPRMC string. 
   Found that setting s.substring(0,5) == "GPRMC" caused a FALSE.
   There seemed to be a 0x0D and 0x00 character at the end. */
  if(s.substring(0,4) == "GPRM"){
    //Serial.println(s);
    for(int i = 0; i < 2; i++){
      if(i < 1) {
        pLoc = s.indexOf(',', pLoc+1);
      }
      else{
        lEndLoc = s.indexOf(',', pLoc+1);
        gpsTime = s.substring(pLoc+1, lEndLoc);
      }
    }
    return gpsTime; 
  }
}
