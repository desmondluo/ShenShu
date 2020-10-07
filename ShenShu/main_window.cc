#include "main_window.h"
#include "qcef/qcef_app.h"
#include "qcef/sh_app.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent) 
 {
	//TODO: 用定时器启动CEF的UI消息循环, 当CEF被拆到其他线程的时候, 这个就要被删除
	if(startTimer(10) == 0) 
	{
		throw std::runtime_error("Unable to start CEF timer");
	}

	// Common settings
	setWindowTitle("ShenShu");
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);
	resize(1024, 768);
	cef_widg_ = new CefWidget(parent);

    url_line_edit_ = new QLineEdit;
    //url_line_edit_->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    connect(url_line_edit_, SIGNAL(returnPressed()), this, SLOT(UrlEntered()));

    auto layout = new QGridLayout;
    layout->addWidget(url_line_edit_, 0, 0);
    layout->addWidget(cef_widg_, 1, 0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->setRowStretch(0, 0);
    layout->setRowStretch(1, 1);
    auto frame = new QFrame;
    frame->setLayout(layout);
    setCentralWidget(frame);
}

MainWindow::~MainWindow() 
{
    int32_t a = 0;
}

void MainWindow::timerEvent(QTimerEvent*) 
{
	// 启动消息循环
	 SHApp::Instance().Run();
}

void MainWindow::UrlEntered() 
{
    cef_widg_->LoadUrl(url_line_edit_->text());
}
