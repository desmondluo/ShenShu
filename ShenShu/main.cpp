#include <QApplication>
#include "main_window.h"
#include "qcef/sh_app.h"


int main(int argc, char *argv[]) {
    SHApp::Instance();
	QApplication app(argc, argv);

	MainWindow win(nullptr);
	win.show();
	win.activateWindow();
    win.raise();
    return app.exec();
}