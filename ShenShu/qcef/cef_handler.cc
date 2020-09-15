#include "cef_handler.h"

QcefHandler::QcefHandler(int32_t index):
	m_index(index)
{}

void QcefHandler::SetBrower(CefRefPtr<CefBrowser> browser)
{
	m_browser = browser;
}

CefRefPtr<CefBrowser> QcefHandler::GetBrowser()
{
	return m_browser;
}

void QcefHandler::OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString &title) 
{

}

void QcefHandler::OnAddressChange(CefRefPtr<CefBrowser> browser,
                                 CefRefPtr<CefFrame> frame,
                                 const CefString &url) {
	if (frame->IsMain() ) 
	{
	}
}

void QcefHandler::OnGotFocus(CefRefPtr<CefBrowser> browser) 
{
}