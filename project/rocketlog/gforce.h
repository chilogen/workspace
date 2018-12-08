

const int xpin = A0;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis
const int zpin = A2;                  // z-axis (only on 3-axis models)
const float bound = 0.2;

#define ON_GROPUND 0
#define FLYING 1
#define FLAMOUT 2
#define FINISH 3


struct Gforce{
   Storage store;
   int stage;
   float gx,gy,gz,g;
   void init();
   void read(int mode);
   void write(String curtime);
   bool reachedAP();
   bool launched();
};


void Gforce::init(){
  this->store.open("Gforce.log");
  stage=0;
  }



void Gforce::read(int mode){
   int x=analogRead(xpin);
   int y=analogRead(ypin);
   int z=analogRead(zpin);

   float gx0=316,gy0=323,gz0=318;

   float scale=63;

   if(mode){
     gx0=gy0=gz0=320;
     scale=60;
     }

   gx=((float)x-gx0)/scale;
   gy=((float)y-gy0)/scale;
   gz=((float)z-gz0)/scale;
   g=sqrt(gx*gx+gy*gy+gz*gz);
   }

void Gforce::write(String curtime){
  this->read(0);
  String gxstr(gx,3),gystr(gy,3),gzstr(gz,3),gstr(g,3);
  this->store.write("time : "+curtime);
  this->store.write("gx : " + gxstr);
  this->store.write("gy : " + gystr);
  this->store.write("gz : " + gzstr);
  this->store.write("g  : " + gstr);
  }


bool Gforce::reachedAP(){
   static int indicate = 0;
   static bool res=false;
   this->read(0);

   switch (stage){
   	case ON_GROPUND:{
   		if(fabs(g-1)>bound) indicate++;
   		if(indicate>2){
   			stage++;
   			indicate=0;
   		}
   		break;
   	}
   	case FLYING:{
   		if(fabs(g-1)<bound) indicate++;
   		if(indicate>2){
   			stage++;
   			indicate=0;
   		}
   		break;
   	}
   	case FLAMOUT:{

   		break;
   	}
   }
   if(stage==FLAMOUT&&fabs(g-1)<bound) res=true;

   return res;
}

bool Gforce::launched(){
	this->read(0);
	static bool res=false;
	static int indicate=0;
	if(fabs(g-1)>bound){
		indicate++;
	}
	if(fabs(g-1)<bound){
		indicate=0;
	}
	if(indicate>5)res=true;
	return res;
  }
