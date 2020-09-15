#include <QApplication>
#include "main_window.h"
#include "qcef/qcef_app.h"

int main(int argc, char *argv[]) {
	// ��ʼ��һ���Լ�
	QcefApp::Instance();
	QApplication app(argc, argv);

	MainWindow win(nullptr);
	win.show();
	win.activateWindow();
	win.raise();

	return app.exec();
}