#include "frameshow.h"

FrameShow::FrameShow(QObject *parent) :
    QThread(parent)
{
    start();
}



void FrameShow::run()
{
    cap.open("/home/mati/Projects/videos/bbb.avi");
    rate = cap.get(CV_CAP_PROP_FPS);
    int d = 1000/rate;
    for(;;)
    {
        cap >> img;
        out = QImage((const unsigned char*)(img.data),img.cols,img.rows,img.step,QImage::Format_RGB888);
        Utils::delay(d);
        emit newImage();
    }
}

QImage FrameShow::getCapturedImage()
{
    return out;
}
