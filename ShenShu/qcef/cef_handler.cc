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

CefRefPtr<CefContextMenuHandler> QcefHandler::GetContextMenuHandler()
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

void QcefHandler::OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString& title)
{
    CEF_REQUIRE_UI_THREAD();
    QString qtitle(QString::fromUtf8(title.ToString().data(), title.ToString().length()));

    emit TitleChange(qtitle);
}

bool QcefHandler::OnSetFocus(CefRefPtr<CefBrowser> browser, FocusSource source)
{
    return false;
}

void QcefHandler::OnGotFocus(CefRefPtr<CefBrowser> browser)
{
    CEF_REQUIRE_UI_THREAD();

    // 发送要line失去焦点
    emit lineRemoveFocus();
}

void QcefHandler::OnBeforeContextMenu(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
    CefRefPtr<CefContextMenuParams> params, CefRefPtr<CefMenuModel> model)
{
    // 不管怎么样, 先清空以前的东西
    model->Remove(MENU_ID_PRINT);
    model->Remove(MENU_ID_VIEW_SOURCE);

    if ((params->GetTypeFlags() & (CM_TYPEFLAG_PAGE | CM_TYPEFLAG_FRAME)) != 0) {
        // Add a separator if the menu already has items.
        if (model->GetCount() > 0)
        {
            model->RemoveAt(2);
            model->Remove(MENU_ID_BACK);
            model->Remove(MENU_ID_FORWARD);
            //model->Clear();
            //model->AddSeparator();
            model->AddItem(MENU_ID_USER_SHOWDEVTOOLS, L"开发者工具"); //"&Show DevTools");
        }
    }
}

bool QcefHandler::RunContextMenu(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
    CefRefPtr<CefContextMenuParams> params, CefRefPtr<CefMenuModel> model,
    CefRefPtr<CefRunContextMenuCallback> callback)
{
    return false;
}

bool QcefHandler::OnContextMenuCommand(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
                                       CefRefPtr<CefContextMenuParams> params, int command_id, EventFlags event_flags)
{
    return true;
}

void QcefHandler::OnContextMenuDismissed(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame)
{
    int32_t a = 0;
}

bool QcefHandler::IsClosed()
{
    return m_closed;
}
