#include "main_window.h"
#include "qcef/qcef_app.h"
#include "qcef/sh_app.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),
    m_close_times(0),
    m_close_timer(nullptr),
    m_loop_timer(nullptr)
 {
	//TODO: 用定时器启动CEF的UI消息循环, 当CEF被拆到其他线程的时候, 这个就要被删除
	if(startTimer(100) == 0) 
	{
		throw std::runtime_error("Unable to start CEF timer");
	}
    m_loop_timer = new QTimer();
    connect(m_loop_timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
    m_loop_timer->start(10);


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
    if (m_close_timer)
    {
        m_close_timer->stop();
        delete m_close_timer;
    }
    if (m_loop_timer)
    {
        m_loop_timer->stop();
        delete m_loop_timer;
    }
    if (cef_widg_)
    {
        delete cef_widg_;
    }
   
   
}

void MainWindow::timerEvent() 
{
	// 启动消息循环
    if (m_loop_timer->isActive())
    {
        SHApp::Instance().Run();
    }
    else
    {
        int32_t a = 0;
    }
	
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if (m_close_times == 0)
    {
        m_close_times += 1;
        preClose();
        event->ignore();
    }
    else
    {
        event->accept();
    }
}

void MainWindow::preClose()
{
    cef_widg_->DoClose();
    // 设置一个定时器, 准备检查关闭
    m_close_timer = new QTimer(this);

    connect(m_close_timer, SIGNAL(timeout()), this, SLOT(CheckClose()));
    m_close_timer->start(10);
}

void MainWindow::UrlEntered() 
{
    cef_widg_->LoadUrl(url_line_edit_->text());
}

void MainWindow::CheckClose()
{
    if (cef_widg_->CefClosed())
    {
        this->m_close_timer->stop();
        if (m_loop_timer)
        {
            m_loop_timer->stop();
        }
        // SHApp::Instance().Release();
        // 关闭自己
        //this->close();
        
    }
}
