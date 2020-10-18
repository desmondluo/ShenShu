#include "main_window.h"
#include "../qcef/sh_app.h"
#include "cef_tab.h"
#include <QTabWidget>


MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),
    m_close_times(0),
    m_close_timer(nullptr),
    m_loop_timer(nullptr)
 {
    //TODO: 用定时器启动CEF的UI消息循环, 当CEF被拆到其他线程的时候, 这个就要被删除
    if(startTimer(10) == 0) 
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

    m_tab_widget = new QTabWidget;
    m_tab_widget->setTabsClosable(true);
    // 设置关闭
    connect(m_tab_widget, &QTabWidget::tabCloseRequested, this, &MainWindow::CloseTab);
    // 添加右边的添加新tab按钮
    QToolButton *tb = new QToolButton();
    tb->setText("+");
    tb->setAutoRaise(true);
    connect(tb, &QToolButton::clicked, this,&MainWindow::addTab);
    m_tab_widget->addTab(new QLabel(QString::fromLocal8Bit("通过点击+添加新的页面")), QString());
    m_tab_widget->setTabEnabled(0, false);
    m_tab_widget->tabBar()->setTabButton(0, QTabBar::RightSide, tb);
    // 添加几个测试的tab
    //CefTab* firsttab = new CefTab(m_tab_widget);
    //m_tab_widget->addTab(firsttab, QString::fromLocal8Bit("测试1"));

    //CefTab* secondtab = new CefTab(m_tab_widget);
    //m_tab_widget->addTab(secondtab, QString::fromLocal8Bit("测试2"));

    //CefTab* thirdtab = new CefTab(m_tab_widget);
    //m_tab_widget->addTab(thirdtab, QString::fromLocal8Bit("测试3"));


    QString path = QDir::currentPath() + "/resource/images/ShenShu256.ico";
    QIcon icon(path);
    setWindowIcon(icon);
    // 设置qss
    setCentralWidget(m_tab_widget);
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
}

void MainWindow::timerEvent() 
{
    // 启动消息循环
    if (m_loop_timer->isActive())
    {
        SHApp::Instance().Run();
    }
}

void MainWindow::CloseTab(int32_t index)
{
    if (index == -1)
    {
        return;
    }
    CefTab* tab = static_cast<CefTab*>(m_tab_widget->widget(index));
    if (!tab)
    {
        return;
    }
    tab->DoClose();
    m_tab_widget->removeTab(index);
    delete tab;
    tab = nullptr;
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
        // 强制退出
        PostQuitMessage(0);
    }
}

void MainWindow::preClose()
{
    for(int32_t i = 0; i < m_tab_widget->count(); ++i)
    {
        QString str = m_tab_widget->widget(i)->metaObject()->className();
        if (str != "CefTab")
        {
            continue;
        }
        CefTab* tab = static_cast<CefTab*>(m_tab_widget->widget(i));
        tab->DoClose();
    }
    // 设置一个定时器, 准备检查关闭
    m_close_timer = new QTimer(this);

    connect(m_close_timer, SIGNAL(timeout()), this, SLOT(CheckClose()));
    m_close_timer->start(10);
}

void MainWindow::addTab()
{
    CefTab* tab = new CefTab(m_tab_widget);
    m_tab_widget->addTab(tab, QString::fromLocal8Bit("测试1"));
    m_tab_widget->setCurrentIndex(m_tab_widget->count() - 1);
}

void MainWindow::CheckClose()
{
    bool allclosed = true;
    for (int32_t i = 0; i < m_tab_widget->count(); ++i)
    {
        QString str = m_tab_widget->widget(i)->metaObject()->className();
        if (str != "CefTab")
        {
            continue;
        }
        CefTab* tab = static_cast<CefTab*>(m_tab_widget->widget(i));
        if (tab->Closed() == false)
        {
            allclosed = false;
        }
    }

    if (allclosed)
    {
        this->m_close_timer->stop();
        if (m_loop_timer)
        {
            m_loop_timer->stop();
        }
        this->close();
    }
}
