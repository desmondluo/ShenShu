#include "qcef_app.h"

QCefApp::QCefApp()
{
    m_ptr_handler = new QcefHandler();
}

QCefApp::~QCefApp()
{
}

CefRefPtr<CefBrowserProcessHandler> QCefApp::GetBrowserProcessHandler()
{
    return this;
}

CefRefPtr<CefRenderProcessHandler> QCefApp::GetRenderProcessHandler()
{
    return this;
}


void QCefApp::CreateBrowser(CefWindowHandle winhandler, std::string url)
{
    CefWindowInfo wininfo;
    CefBrowserSettings settings;
    //settings.multi_threaded_message_loop = true;
    // 第一次并不知道在哪的, 但是这个不重要, 后面一旦外部的UI初始化完毕, 就会主动通知这个UI, 做对应的调整
    wininfo.SetAsChild(winhandler, RECT{ 0, 0, 0, 0 });
    CefBrowserHost::CreateBrowserSync(wininfo, m_ptr_handler, CefString("http://baidu.com"), settings, nullptr, nullptr);
}

CefRefPtr<CefBrowser> QCefApp::GetBrowser()
{
    if (m_ptr_handler)
        return m_ptr_handler->GetBrowser();
    else
        return nullptr;
}

CefRefPtr<QcefHandler> QCefApp::GetHandler()
{
    return m_ptr_handler;
}

bool QCefApp::IsClose()
{
    if (m_ptr_handler)
    {
        return m_ptr_handler->IsClosed();
    }
    return true;
}

