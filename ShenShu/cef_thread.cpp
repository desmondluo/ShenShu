#include "cef_thread.h"
#include "qcef/qcef_app.h"
#include <QDebug>

void CefThread::run()
{
    QcefApp::Instance()->Run();
   // exec();
    int32_t a = 0;
}
