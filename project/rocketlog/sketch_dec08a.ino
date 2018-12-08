#include "storage.h"
#include "motor.h"
#include "gps.h"
#include "gforce.h"
#include "timer.h"

GPS gy61;
Motor em08ma2;
Gforce adxl335;
Timer dida;

#define deploy_parachute_delay 1000
unsigned long launch_time=-1;

void setup(){
  
  Serial.begin(9600);
  if (!SD.begin(53)) {
    return;
  }
  adxl335.init();
  gy61.init();
  em08ma2.init(9);
  dida.init();
}

void loop(){   //主循环
        
        dida.update();;
        adxl335.write(String(dida.cur,10));
        gy61.write(String(dida.cur,10));


//code block for deploy chute
        
        //scheme one
        //deploy parachute after reached AP
        if(adxl335.reachedAP()){
          //deploy chute
          }

        //scheme two
        //deploy parachute after launch using timer
        //more reliable,need to test with other module for delay(change indicate bound)
        if(adxl335.launched()){
          if(launch_time!=-1&&dida.after(launch_time + deploy_parachute_delay)){
            //deploy chute
          }
          if(launch_time==-1){
            launch_time=dida.cur;
            }
          }  
} 
