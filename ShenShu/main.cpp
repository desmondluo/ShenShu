#include <QApplication>
#include "main_window.h"
#include "qcef/sh_app.h"


int main(int argc, char *argv[]) {
    SHApp::Instance();
	QApplication* app = new QApplication(argc, argv);

	MainWindow win(nullptr);
	win.show();
	win.activateWindow();
    win.raise();
    app->exec();
    delete app;
    SHApp::Instance().Release();
    exit(0);

}