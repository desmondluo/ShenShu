#include "cef_widget.h"
#include "../qcef/cef_handler.h"
#include "../qcef/sh_app.h"

CefWidget::CefWidget(QWidget *parent): QWidget(parent) 
{
    // 初始化一个浏览器
    m_ptr_handler = new QcefHandler();
    SHApp::Instance().CreateBrowser((CefWindowHandle)winId(),m_ptr_handler, "http://baidu.com");
}

CefWidget::~CefWidget() 
{
    m_ptr_handler = nullptr;
}

void CefWidget::LoadUrl(const QString &url) 
{
    if (m_ptr_handler && m_ptr_handler->GetBrowser())
    {
        m_ptr_handler->GetBrowser()->GetMainFrame()->LoadURL(CefString(url.toStdString()));
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
    if (m_ptr_handler && m_ptr_handler->GetBrowser())
    {
        m_ptr_handler->GetBrowser()->GetHost()->CloseBrowser(true);
    }
}

void CefWidget::UpdateSize()
{
    // 基本的调整一下大小
    if (m_ptr_handler && m_ptr_handler->GetBrowser())
    {
        auto browser_host = m_ptr_handler->GetBrowser()->GetHost();
        auto browser_win = browser_host->GetWindowHandle();
        SetWindowPos(browser_win, (HWND)this->winId(), 0, 0, this->width(), this->height(), SWP_NOZORDER);
        browser_host->NotifyMoveOrResizeStarted();
    }
}

bool CefWidget::CefClosed()
{
    if (m_ptr_handler && m_ptr_handler->IsClosed())
    {
        return true;
    }
    return false;
}

CefRefPtr<QcefHandler> CefWidget::GetHandler()
{
    return m_ptr_handler;
}
