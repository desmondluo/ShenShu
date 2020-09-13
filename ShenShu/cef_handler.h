/**
 * @brief CEFHandler的实现, 终极Boss
 */
#ifndef QT_CEF_POC_HANDLER_H_
#define QT_CEF_POC_HANDLER_H_

#include <QtWidgets>
#include "include/cef_client.h"

class CefHandler :
    public CefClient,
    public CefDisplayHandler,
    public CefFocusHandler {
 public:
	 explicit CefHandler();

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

  IMPLEMENT_REFCOUNTING(CefHandler);
};

#endif // QT_CEF_POC_HANDLER_H_
