
struct Timer{
  unsigned long start;
  unsigned long cur;
  void init();
  void update();
  String now();
  bool after(unsigned long tim);
};



void Timer::init(){
  start=millis();
  cur=start;
  }

void Timer::update(){
  cur=millis();
  }

bool Timer::after(unsigned long tim){
  this->update();
  return tim>(cur-start);
  }

String Timer::now(){
  	this->update();
  	return String(cur,10);
  }