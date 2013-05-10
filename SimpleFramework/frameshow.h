#ifndef FRAMESHOW_H
#define FRAMESHOW_H

#include <QThread>
#include <opencv2/opencv.hpp>
#include <QImage>

class FrameShow : public QThread
{
    Q_OBJECT
public:
    explicit FrameShow(QObject *parent = 0);
    QImage out;
    QImage outThresh;
    QImage outGray;

private:
    cv::Mat img;
    cv::Mat thresh;
    cv::Mat gray;
    cv::VideoCapture cap;
protected:
    void run();
    
signals:
    void newImage();
    
public slots:
    
};

#endif // FRAMESHOW_H
