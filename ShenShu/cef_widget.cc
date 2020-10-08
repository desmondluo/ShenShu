#include "cef_widget.h"
#include "qcef/qcef_app.h"

CefWidget::CefWidget(QWidget *parent): QWidget(parent) 
{
	// 初始化一个浏览器
    m_ptr_app = new QCefApp(0);
    m_ptr_app->CreateBrowser((CefWindowHandle)winId(), "http://baidu.com");
	//m_handler = QcefApp::Instance()->CreateBrowser((CefWindowHandle)winId());
}

CefWidget::~CefWidget() 
{
    m_ptr_app = nullptr;
}

void CefWidget::LoadUrl(const QString &url) 
{
    if (m_ptr_app && m_ptr_app->GetBrowser())
    {
        m_ptr_app->GetBrowser()->GetMainFrame()->LoadURL(CefString(url.toStdString()));
    }
}

void CefWidget::moveEvent(QMoveEvent *event) 
{
    this->UpdateSize();
}

void CefWidget::resizeEvent(QResizeEvent *event) 
{
    this->UpdateSize();
}

void CefWidget::DoClose()
{
    if (m_ptr_app && m_ptr_app->GetBrowser())
    {
        m_ptr_app->GetBrowser()->GetHost()->CloseBrowser(true);
    }
}

void CefWidget::UpdateSize()
{
    // 基本的调整一下大小
    if (m_ptr_app && m_ptr_app->GetBrowser())
    {
        auto browser_host = m_ptr_app->GetBrowser()->GetHost();
        auto browser_win = browser_host->GetWindowHandle();
        SetWindowPos(browser_win, (HWND)this->winId(), 0, 0, this->width(), this->height(), SWP_NOZORDER);
        browser_host->NotifyMoveOrResizeStarted();
    }
}

bool CefWidget::CefClosed()
{
    if (m_ptr_app && m_ptr_app->IsClose())
    {
        return true;
    }
    return false;
}
