#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtGui>
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
    QLabel *countLabel;
    QLabel *framesLabel;
    QVBoxLayout *layout;
    QHBoxLayout *imageLayout;
    QHBoxLayout *controlsLayout;
    QGridLayout *preferencesLayout;

    FrameShow *frameShow;
    int count;

    void initializeElements();
    void setupLayout();
    void setSignals();

private slots:
    void on_bExit_clicked();
    void gotNewImage();
};

#endif // MAINWIDGET_H
