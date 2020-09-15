/**
 * @brief CEFHandler的实现, 终极Boss
 */
#ifndef QT_CEF_POC_HANDLER_H_
#define QT_CEF_POC_HANDLER_H_

#include <QtWidgets>
#include "include/cef_client.h"

class QcefHandler :
    public CefClient,
    public CefDisplayHandler,
    public CefFocusHandler {
 public:
	 explicit QcefHandler(int32_t index);
	 /**
	  * @brief 外挂一个browser
	  * @param browser 外挂的浏览器
	  */
	 void SetBrower(CefRefPtr<CefBrowser> browser);
	 /**
	  * @brief 获取这个handler对应的browser
	  * @return 对应的browser
	  */
	 CefRefPtr<CefBrowser> GetBrowser();

  virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override {
    return this;
  }

  virtual CefRefPtr<CefFocusHandler> GetFocusHandler() override {
    return this;
  }

  virtual void OnTitleChange(CefRefPtr<CefBrowser> browser,
                             const CefString& title) override;

  virtual void OnAddressChange(CefRefPtr<CefBrowser> browser,
                               CefRefPtr<CefFrame> frame,
                               const CefString& url) override;

  virtual void OnGotFocus(CefRefPtr<CefBrowser> browser) override;
  /**
   * @brief 获取这个handler的索引
   * @param  获得的索引
   */
  int32_t Index();
private:
	//! 索引
	int32_t m_index;
	//! CEF的事例
	CefRefPtr<CefBrowser> m_browser;

  IMPLEMENT_REFCOUNTING(QcefHandler);
};

#endif // QT_CEF_POC_HANDLER_H_
