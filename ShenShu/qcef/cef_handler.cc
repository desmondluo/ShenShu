#include "cef_handler.h"

CefHandler::CefHandler(int32_t index):
	m_index(index)
{}

void CefHandler::SetBrower(CefRefPtr<CefBrowser> browser)
{
	m_browser = browser;
}

CefRefPtr<CefBrowser> CefHandler::GetBrowser()
{
	return m_browser;
}

void CefHandler::OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString &title) 
{

}

void CefHandler::OnAddressChange(CefRefPtr<CefBrowser> browser,
                                 CefRefPtr<CefFrame> frame,
                                 const CefString &url) {
	if (frame->IsMain() ) 
	{
	}
}

void CefHandler::OnGotFocus(CefRefPtr<CefBrowser> browser) 
{
}
