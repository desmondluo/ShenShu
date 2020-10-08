#include "qcef_app.h"

QCefApp::QCefApp(int32_t index):
    m_index(index)
{
    m_ptr_handler = new QcefHandler(m_index);
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
    // ��һ�β���֪�����ĵ�, �����������Ҫ, ����һ���ⲿ��UI��ʼ�����, �ͻ�����֪ͨ���UI, ����Ӧ�ĵ���
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

bool QCefApp::IsClose()
{
    if (m_ptr_handler)
    {
        return m_ptr_handler->IsClosed();
    }
    return true;
}

