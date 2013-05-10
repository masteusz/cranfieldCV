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
    framesLabel = new QLabel("Frames:");
    countLabel = new QLabel();
    preferences = new QLabel("Preferences be here!");
    layout = new QVBoxLayout();
    imageLayout = new QHBoxLayout();
    controlsLayout = new QHBoxLayout();
    preferencesLayout = new QGridLayout();
    frameShow = new FrameShow();
    count = 0;
}

void MainWidget::setupLayout()
{
    preferencesLayout->addWidget(framesLabel,0,0);
    preferencesLayout->addWidget(countLabel,0,1);

    controlsLayout->addWidget(bExit);
    imageLayout->addWidget(image);
    imageLayout->addLayout(preferencesLayout);
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
    countLabel->setText(QString::number(count));
    image->setPixmap(QPixmap::fromImage(frameShow->getCapturedImage()));
    count++;
}

MainWidget::~MainWidget()
{

}


