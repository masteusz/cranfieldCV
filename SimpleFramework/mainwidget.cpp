#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    initializeElements();
    setupLayout();
    setSignals();
}

void MainWidget::initializeElements()
{
    bExit = new QPushButton("Quit");
    image = new QLabel("image!");
    preferences = new QLabel("Preferences be here!");
    layout = new QVBoxLayout();
    imageLayout = new QHBoxLayout();
    controlsLayout = new QHBoxLayout();
    cvGLWidget = new OpenCVGL();
    cvGLWidget->setFixedSize(640,480);
    frameShow = new FrameShow();
}

void MainWidget::setupLayout()
{
    controlsLayout->addWidget(bExit);
    imageLayout->addWidget(cvGLWidget);
    imageLayout->addWidget(preferences);
    layout->addLayout(imageLayout);
    layout->addLayout(controlsLayout);
    this->setLayout(layout);
}

void MainWidget::setSignals()
{
    connect(bExit,SIGNAL(clicked()),this,SLOT(on_bExit_clicked()));
    connect(frameShow,SIGNAL(newImage()),this,SLOT(gotNewImage()));
}

void MainWidget::on_bExit_clicked()
{
    qDebug("Bye!");
    QApplication::quit();
}

void MainWidget::gotNewImage()
{
    qDebug("Got new image!");
    //cvGLWidget->renderImage(frameShow->out);
}

MainWidget::~MainWidget()
{

}


