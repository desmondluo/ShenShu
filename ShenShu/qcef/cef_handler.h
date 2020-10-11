/**
 * @brief CEFHandler的实现, 终极Boss
 */
#ifndef QT_CEF_POC_HANDLER_H_
#define QT_CEF_POC_HANDLER_H_

#include <QtWidgets>
#include "include/cef_client.h"

class QcefHandler :
    public CefClient,
    public CefLifeSpanHandler {
 public:
     explicit QcefHandler(int32_t index);
     /**
      * @brief 获取这个handler对应的browser
      * @return 对应的browser
      */
     CefRefPtr<CefBrowser> GetBrowser();
     /**
      * @brief 获取浏览器的生命周期控制器
      * @param browser 浏览器的生命周期handler
      */
     virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE;
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
      * @brief 是否已经关闭
      * @return 是否已经关闭
      */
     bool IsClosed();
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
