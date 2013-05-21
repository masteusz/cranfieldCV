#include "frameshow.h"

FrameShow::FrameShow(QObject *parent) :
    QThread(parent)
{
    start();
    isThreadStopped = true;
}



void FrameShow::run()
{
    cap.open("/home/mati/Projects/videos/bbb.avi");
    rate = cap.get(CV_CAP_PROP_FPS);
    int d = 1000/rate;
    while(!isThreadStopped)
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

void FrameShow::stopThread()
{
    isThreadStopped = true;
}

void FrameShow::startThread()
{
    isThreadStopped = false;
    start();
}
