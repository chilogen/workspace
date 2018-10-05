    #include "opencv2/video/tracking.hpp"  
    #include "opencv2/imgproc/imgproc.hpp"  
    #include "opencv2/highgui/highgui.hpp"  
    #include <iostream>  
    #include <ctype.h>  
    using namespace cv;  
    using namespace std;  
      
    //定义一些全局变量  
    bool LBdown = false;  
    int trackCount = 0;  //跟踪计数  
    Mat image;  
    Rect selection;  
    Point origin;  
      
    //函数声明  
    void onMouse( int event, int x, int y, int, void* );  
    void help();  
      
      
    int main( )  
    {  
        help();  
      
        int vmin = 10, vmax = 256, smin = 30;  
        int hbinNum = 16;  
        float hranges[] = {0,180};  
        const float* phranges = hranges;  
        bool backprojMode = false;  
      
        VideoCapture capture(0);      //读取摄像头  
      
        if( !capture.isOpened() )  
        {         
            cout << "***Could not initialize capturing...***\n";  
            return -1;  
        }  
    
        namedWindow( "MeanShift Tracking", 0 );  
        setMouseCallback( "MeanShift Tracking", onMouse, 0 );//消息响应机制  
        createTrackbar( "Vmin", "MeanShift Tracking", &vmin, 256, 0 );//createTrackbar函数的功能是在对应的窗口创建滑动条，滑动条Vmin,vmin表示滑动条的值，最大为256  
        createTrackbar( "Vmax", "MeanShift Tracking", &vmax, 256, 0 );//最后一个参数为0代表没有调用滑动拖动的响应函数  
        createTrackbar( "Smin", "MeanShift Tracking", &smin, 256, 0 );//vmin,vmax,smin初始值分别为10,256,30  
      
        bool paused = false;  
        Mat frame,hsv,hue,mask,hist,histimg = Mat::zeros(200, 320, CV_8UC3), backproj;;  
        Rect trackWindow;  
      
        while (1)  
        {     
            if( !paused )//没有暂停,不停地显示当前图片  
            {  
                capture>>frame;  
                if(frame.empty())  
                    break;  
            }  
      
            frame.copyTo(image);  
      
            if(!paused)  
            {  
                if(trackCount > 0)  
                {  
                    cvtColor(image, hsv, CV_BGR2HSV);  
                    //通过inRange限制s和v分量范围，滤除一些干扰  
                    inRange(hsv, Scalar(0, smin, min(vmin,vmax)),Scalar(180, 256, max(vmin, vmax)), mask);  
                    int ch[] = {0, 0};  
                    hue.create(hsv.size(), hsv.depth());//hue初始化为与hsv大小深度一样的矩阵  
                    mixChannels(&hsv, 1, &hue, 1, ch, 1);//将hsv第一个通道(也就是色调)的数复制到hue中  
                      
                    //=========起始帧进行初始化,即画出目标直方图==============================  
                    if(trackCount == 1)     
                    {  
                        histimg = Scalar::all(0);    //重新选择目标就将histimg清零  
                        //计算直方图及归一化  
                        Mat roi(hue, selection), maskroi(mask, selection);//mask保存的hsv的最小值  
                        calcHist(&roi, 1, 0, maskroi, hist, 1, &hbinNum, &phranges);  
                        normalize(hist, hist, 0, 255, CV_MINMAX);   //将hist归一化到0~255      

                        //----------------------------------------------------------------------  
                        trackCount ++;  
                        trackWindow = selection;  //trackWindow也就是目标窗口，用于meanShift()迭代                    
                    }  
      
                    //===============后续帧跟踪=================  
                    //计算反向投影，调用meanshift()方法进行跟踪  
                    calcBackProject(&hue, 1, 0, hist, backproj, &phranges);//计算直方图的反向投影，计算hue图像0通道直方图hist的反向投影，并让入backproj中  
                    backproj &= mask;  
                    meanShift(backproj, trackWindow, TermCriteria( CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1 ));  
      
                    if( backprojMode )  
                        cvtColor( backproj, image, CV_GRAY2BGR );  
                    rectangle(image,Point(trackWindow.x,trackWindow.y),Point(trackWindow.x+trackWindow.width,trackWindow.y+trackWindow.height),Scalar(0,0,255),1,CV_AA);  
      
                    trackCount++;  
                    cout<<"trackCount="<<trackCount<<endl;  
                }  
            }  
      
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
      
    void help()  
    {  
        cout << "\n\nHot keys: \n"  
            "\tESC - quit the program\n"         
            "\tb - switch to/from backprojection view\n"         
            "\tp - pause video\n"  
            "To initialize tracking, select the object with mouse\n";  
    }  