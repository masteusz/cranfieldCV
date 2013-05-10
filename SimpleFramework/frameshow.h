#ifndef FRAMESHOW_H
#define FRAMESHOW_H

#include <QThread>
#include <opencv2/opencv.hpp>
#include <QImage>
#include <utils.h>


class FrameShow : public QThread
{
    Q_OBJECT
public:
    explicit FrameShow(QObject *parent = 0);
    QImage out;

private:
    cv::Mat img;
    cv::VideoCapture cap;
    double rate;
protected:
    void run();
    
signals:
    void newImage();
    
public slots:
    
};

#endif // FRAMESHOW_H
