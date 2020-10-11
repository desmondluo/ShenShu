#include <QApplication>
#include "ui/main_window.h"
#include "qcef/sh_app.h"


int main(int argc, char *argv[]) {
    if (SHApp::Instance().ExitCode() >= 0)
    {
        return SHApp::Instance().ExitCode();
    }
    
	QApplication app(argc, argv);
	MainWindow win(nullptr);
	win.show();
	win.activateWindow();
    win.raise();
    int32_t ret = app.exec();
    SHApp::Instance().Release();
    return ret;
}