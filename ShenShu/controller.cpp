#include "controller.h"
#include "main_window.h"

Controller::Controller(int32_t argc, char* argv[]):
    m_qt_app(argc, argv)
{
    
}

Controller::~Controller()
{

}

void Controller::ManagerLoop()
{
    MainWindow win(nullptr);
    m_cef_thread.start();
    win.show();
    win.activateWindow();
    win.raise();

    m_qt_app.exec();
    m_cef_thread.quit();
}
