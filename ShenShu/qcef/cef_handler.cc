#include "cef_handler.h"

QcefHandler::QcefHandler(int32_t index):
	m_index(index),
    m_browser(nullptr),
    m_closed(false)
{}

CefRefPtr<CefBrowser> QcefHandler::GetBrowser()
{
	return m_browser;
}

CefRefPtr<CefLifeSpanHandler> QcefHandler::GetLifeSpanHandler()
{
    return this;
}

void QcefHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
    m_browser = browser;
}

bool QcefHandler::DoClose(CefRefPtr<CefBrowser> browser)
{
    printf("收到执行关闭的回调\n");
    return false;
}

void QcefHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser)
{
    printf("收到关闭前的回调\n");
    m_closed = true;
}

bool QcefHandler::IsClosed()
{
    return m_closed;
}
