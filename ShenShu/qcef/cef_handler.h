/**
 * @brief CEFHandler��ʵ��, �ռ�Boss
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
	  * @brief ��ȡ���handler��Ӧ��browser
	  * @return ��Ӧ��browser
	  */
	 CefRefPtr<CefBrowser> GetBrowser();
     /**
      * @brief ��ȡ��������������ڿ�����
      * @param browser ���������������handler
      */
     virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE;
     /**
      * @brief �������������ʱ��Ļص�
      * @param browser �����
      */
     virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
     /**
      * @brief ���������Ҫ����
      * @param browser �����
      * @return �Ƿ�ȷ��
      */
     virtual bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
     /**
      * @brief ���������Ҫ�ر�ʱ��Ļص�
      * @param browser �����
      */
     virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
private:
	//! ����
	int32_t m_index;
	//! CEF������
	CefRefPtr<CefBrowser> m_browser;

  IMPLEMENT_REFCOUNTING(QcefHandler);
};

#endif // QT_CEF_POC_HANDLER_H_
