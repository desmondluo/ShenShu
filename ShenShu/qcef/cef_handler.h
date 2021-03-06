﻿/**
 * @brief CEFHandler的实现, 终极Boss
 */
#ifndef QT_CEF_POC_HANDLER_H_
#define QT_CEF_POC_HANDLER_H_

#include <QtWidgets>
#include "include/cef_client.h"
#include <QMetaType>

enum RightMenu
{
    MENU_ID_USER_OPENLINK = MENU_ID_USER_FIRST + 200,
    MENU_ID_USER_SHOWDEVTOOLS,
};

class QcefHandler :
    public QObject,
    public CefClient,
    public CefLifeSpanHandler,
    public CefDisplayHandler,
    public CefFocusHandler,
    public CefContextMenuHandler
{
    Q_OBJECT
 public:
     explicit QcefHandler();
     /**
      * @brief 获取这个handler对应的browser
      * @return 对应的browser
      */
     CefRefPtr<CefBrowser> GetBrowser();
     /**
      * @brief 获取浏览器的生命周期控制器
      * @return browser 浏览器的生命周期handler
      */
     virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE;
     /**
      * @brief 获取外观的handler
      * @return 外观handler
      */
     virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() OVERRIDE;
     /**
      * brief 获取焦点的handler
      */
     virtual CefRefPtr<CefFocusHandler> GetFocusHandler() OVERRIDE;
    /**
     * @brief 获取右击菜单栏的handler
     */
     virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() OVERRIDE;
     /**
      * @brief 当浏览器被创建时候的回调
      * @param browser 浏览器
      */
     virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
     /**
      * @brief 测试这个是要干嘛
      * @param browser 浏览器
      * @return 是否确认
      */
     virtual bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
     /**
      * @brief 当浏览器将要关闭时候的回调
      * @param browser 浏览器
      */
     virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
    /**
     * @brief 重载当打开新的window
     */
     virtual bool OnBeforePopup(CefRefPtr<CefBrowser> browser,
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
         bool* no_javascript_access) OVERRIDE;
     /**
      * @brief 当图标发生改变
      */
     virtual void OnFaviconURLChange(CefRefPtr<CefBrowser> browser,
         const std::vector<CefString>& icon_urls) OVERRIDE;
     /**
      * @brief 当title发生变化
      */
     virtual void OnTitleChange(CefRefPtr<CefBrowser> browser,
         const CefString& title) OVERRIDE;

    /**
     * @brief 当将要设置焦点(如果后面不想一打开就设置焦点， 这个地方可以设置为false)
     */
     virtual bool OnSetFocus(CefRefPtr<CefBrowser> browser, FocusSource source) OVERRIDE;
    /**
     * @brief 当已经得到焦点
     */
     virtual void OnGotFocus(CefRefPtr<CefBrowser> browser) OVERRIDE;
     /**
      * @brief 当右击的时候, 将要弹出菜单
      */
     virtual void OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
         CefRefPtr<CefFrame> frame,
         CefRefPtr<CefContextMenuParams> params,
         CefRefPtr<CefMenuModel> model) OVERRIDE;
     /**
      * @brief 当运行这个菜单的时候
      */
     virtual bool RunContextMenu(CefRefPtr<CefBrowser> browser,
         CefRefPtr<CefFrame> frame,
         CefRefPtr<CefContextMenuParams> params,
         CefRefPtr<CefMenuModel> model,
         CefRefPtr<CefRunContextMenuCallback> callback) OVERRIDE;
     /**
      * @brief 当菜单栏被点击的时候
      */
     virtual bool OnContextMenuCommand(CefRefPtr<CefBrowser> browser,
         CefRefPtr<CefFrame> frame,
         CefRefPtr<CefContextMenuParams> params,
         int command_id,
         EventFlags event_flags) OVERRIDE;
     virtual void OnContextMenuDismissed(CefRefPtr<CefBrowser> browser,
         CefRefPtr<CefFrame> frame) OVERRIDE;

     /**
      * @brief 是否已经关闭
      * @return 是否已经关闭
      */
     bool IsClosed();
     signals:
    /**
     * @brief 发送icon改变的信号
     */
     void IconUrlChange(QString str);
    /**
     * @brief 编辑框要失去焦点
     */
     void lineRemoveFocus();
    /**
     * @brief 当标题发生改变
     * @param title 标题
     */
     void TitleChange(QString ttitle);
private:
    //! 索引
    int32_t m_index;
    //! CEF的事例
    CefRefPtr<CefBrowser> m_browser;
    //! 是否已经关闭
    bool m_closed;

  IMPLEMENT_REFCOUNTING(QcefHandler);
};

#endif // QT_CEF_POC_HANDLER_H_
