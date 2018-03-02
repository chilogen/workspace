/*
ans1:
127
52
117
93
ans2:

*/

    #include "opencv2/video/tracking.hpp"  
    #include "opencv2/imgproc/imgproc.hpp"  
    #include "opencv2/highgui/highgui.hpp"  
    #include <iostream>  
    #include <ctype.h>  
    using namespace cv;  
    using namespace std;  
      
    //定义一些全局变量  
    bool LBdown = true;  
    int trackCount = 0;  //跟踪计数  
    Mat image;  
    Rect selection;  
    Point origin;  
      
    //函数声明  
    void onMouse( int event, int x, int y, int, void* );  
      
    int main( )  
    {  
      
        int vmin = 10, vmax = 256, smin = 30;  
        int hbinNum = 16;  
        float hranges[] = {0,180};  
        const float* phranges = hranges;  
        bool backprojMode = false;  
      
        namedWindow( "MeanShift Tracking", 0 );  
        setMouseCallback( "MeanShift Tracking", onMouse, 0 );//消息响应机制  
      
        bool paused = false;  
        Mat frame,hsv,hue,mask,hist,histimg = Mat::zeros(200, 320, CV_8UC3), backproj;;  
        Rect trackWindow;  
      
      	image=imread("../img/1.bmp");
        while (1)  
        {       
            imshow( "MeanShift Tracking",image);  
      
            int c = waitKey(30);  
            switch (c)  
            {     
            //注意按键区分大小写  
            case 27:              //esc   退出程序  
                return 0;  
            case 98:              //'b'  反向投影模型交替  
                backprojMode = !backprojMode;  
                break;  
            case 112:             //"p" 暂停跟踪交替  
                paused = !paused;  
                break;        
            } 
            if(trackCount==1)	cout<<selection.x<<endl<<selection.y<<endl<<selection.width<<endl<<selection.height<<endl;
        }  
    }  
      
    void onMouse( int event, int x, int y, int, void* )  
    {  
        if( LBdown )//只有当鼠标左键按下去时才有效，然后通过if里面代码就可以确定所选择的矩形区域selection了  
        {  
            selection.x = MIN(x, origin.x);//矩形左上角顶点坐标  
            selection.y = MIN(y, origin.y);  
            selection.width = abs(x - origin.x);//矩形宽  
            selection.height = abs(y - origin.y);//矩形高  
            selection &= Rect(0, 0, image.cols, image.rows);//用于确保所选的矩形区域在图片范围内  
            rectangle( image, selection,Scalar(0,0,255), 1, 8 );  
            imshow( "MeanShift Tracking",image);  
        }  
      
        switch( event )  
        {  
        case CV_EVENT_LBUTTONDOWN:  
            origin = Point(x,y);  
            selection = Rect(x,y,0,0);//鼠标刚按下去时初始化了一个矩形区域  
            LBdown = true;  
            //trackCount = 0;  
            break;  
        case CV_EVENT_LBUTTONUP:  
            LBdown = false;       
            if( selection.area()>0 )  
                trackCount = 1;     
            //cout<<"selection="<<selection<<endl;  
            break;  
        }  
    }  