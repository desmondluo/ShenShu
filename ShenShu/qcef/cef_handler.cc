#include "cef_handler.h"

#include "include/wrapper/cef_helpers.h"

QcefHandler::QcefHandler():
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

CefRefPtr<CefDisplayHandler> QcefHandler::GetDisplayHandler()
{
    return this;
}

CefRefPtr<CefFocusHandler> QcefHandler::GetFocusHandler()
{
    return this;
}

void QcefHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
    m_browser = browser;
}

bool QcefHandler::DoClose(CefRefPtr<CefBrowser> browser)
{
    return false;
}

void QcefHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser)
{
    m_closed = true;
}

bool QcefHandler::OnBeforePopup(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame, 
    const CefString& target_url,
    const CefString& target_frame_name,
    WindowOpenDisposition target_disposition, 
    bool user_gesture,
    const CefPopupFeatures& popupFeatures,
    CefWindowInfo& windowInfo,
    CefRefPtr<CefClient>& client,
    CefBrowserSettings& settings,
    CefRefPtr<CefDictionaryValue>& extra_info, 
    bool* no_javascript_access)
{
    switch (target_disposition)
    {
    case WOD_NEW_FOREGROUND_TAB:
    case WOD_NEW_BACKGROUND_TAB:
    case WOD_NEW_POPUP:
    case WOD_NEW_WINDOW:
        browser->GetMainFrame()->LoadURL(target_url);
        return true; //cancel create
    }
    return false;
}

void QcefHandler::OnFaviconURLChange(CefRefPtr<CefBrowser> browser, const std::vector<CefString>& icon_urls)
{
    CEF_REQUIRE_UI_THREAD();

    if (icon_urls.size() > 0)
    {
        emit IconUrlChange(QString::fromStdString(icon_urls[0].ToString()));
    }
}

bool QcefHandler::IsClosed()
{
    return m_closed;
}
