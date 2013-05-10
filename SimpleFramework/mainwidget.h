#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtGui>
#include <opencvgl.h>
#include <frameshow.h>

class MainWidget : public QWidget
{
    Q_OBJECT
    
public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

private:
    QPushButton *bExit;
    QLabel *image;
    QLabel *preferences;
    QVBoxLayout *layout;
    QHBoxLayout *imageLayout;
    QHBoxLayout *controlsLayout;

    FrameShow *frameShow;
    OpenCVGL *cvGLWidget;

    void initializeElements();
    void setupLayout();
    void setSignals();

private slots:
    void on_bExit_clicked();
    void gotNewImage();
};

#endif // MAINWIDGET_H
