#include "cef_handler.h"

CefHandler::CefHandler() {}

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
