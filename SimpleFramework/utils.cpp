#include "utils.h"

Utils::Utils()
{
}

/* static */
void Utils::delay(const int n)
{
    QTime dieTime = QTime::currentTime().addMSecs(n);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
