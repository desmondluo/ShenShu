/**
 * @brief CEFHandler��ʵ��, �ռ�Boss
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
	 explicit CefHandler(int32_t index);

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
   * @brief ��ȡ���handler������
   * @param  ��õ�����
   */
  int32_t Index();
private:
	//! ����
	int32_t m_index;

  IMPLEMENT_REFCOUNTING(CefHandler);
};

#endif // QT_CEF_POC_HANDLER_H_
