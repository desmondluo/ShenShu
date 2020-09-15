/**
 * @brief CEFHandler��ʵ��, �ռ�Boss
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
	  * @brief ���һ��browser
	  * @param browser ��ҵ������
	  */
	 void SetBrower(CefRefPtr<CefBrowser> browser);
	 /**
	  * @brief ��ȡ���handler��Ӧ��browser
	  * @return ��Ӧ��browser
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
   * @brief ��ȡ���handler������
   * @param  ��õ�����
   */
  int32_t Index();
private:
	//! ����
	int32_t m_index;
	//! CEF������
	CefRefPtr<CefBrowser> m_browser;

  IMPLEMENT_REFCOUNTING(QcefHandler);
};

#endif // QT_CEF_POC_HANDLER_H_
