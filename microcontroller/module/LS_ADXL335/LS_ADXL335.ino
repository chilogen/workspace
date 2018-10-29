//LingShun Lab
        
const int xpin = A1;                  // x-axis 
const int ypin = A2;                  // y-axis
const int zpin = A3;                  // z-axis

const String XHEADER = "X: ";
const String YHEADER = "Y: ";
const String ZHEADER = "Z: ";
const String TAB = "\t";

void setup()
{
   //设置波特率
    Serial.begin(9600);
}

void loop()
{
    //读取模拟口的数据，直接串口输出观察
    Serial.print(XHEADER + analogRead(xpin) + TAB);
    Serial.print(YHEADER + analogRead(ypin) + TAB);
    Serial.print(ZHEADER + analogRead(zpin));
    Serial.println();
    delay(200);
}
