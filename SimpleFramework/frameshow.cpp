#include "frameshow.h"

FrameShow::FrameShow(QObject *parent) :
    QThread(parent)
{
    start();
}

void FrameShow::run()
{
    cap.open("/home/mati/Projects/videos/bbb.avi");
    //cap.set(CV_CAP_PROP_FRAME_WIDTH,800);
    //cap.set(CV_CAP_PROP_FRAME_HEIGHT,600);
    for(;;)
    {
        cap >> img;
        out = QImage((const unsigned char*)(img.data),img.cols,img.rows,img.step,QImage::Format_RGB888);
        emit newImage();
    }
}
