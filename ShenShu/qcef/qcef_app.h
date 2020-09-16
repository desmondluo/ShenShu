#pragma once

/**
 * @file qcef_app.h
 * @brief CefApp��������������browser�Ĺ�����, ��������кܶ��browser, �������ͳһ�Ĺ���, ͬʱ������̼���Ļص���Ϣ����
 * @auther desmond
 * @date 2020-09-14
 * @copyright desmond
 * @version 1.0
 */

#ifndef QCEF_QCEF_APP_H_
#define QCEF_QCEF_APP_H_

#include "include/cef_app.h"
#include "cef_handler.h"

/**
 * @brief ȫ�������������, ���browser��������ʵ��tab�Ĺ���
 */
class QcefApp:
	public CefApp,
	public CefBrowserProcessHandler,
    public CefRenderProcessHandler
{
public:
	/**
	 * @brief ���캯��
	 */
	QcefApp();
	/**
	 * @brief ��������
	 */
	virtual ~QcefApp();
	/**
	 * @brirf ȫ�ֵ���, �κεط����Ի�ȡ���app, �����������Ҫ��֤�Լ��ľ����̰߳�ȫ
	 */
	static CefRefPtr<QcefApp> Instance();
	/**
	 * @brief ����ʼ����ϵĻص�
	 */
	virtual void OnContextInitialized();
	/**
	 * @brief ���ػ�ȡ���̼������ص�����
	 */
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler();
    virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefDictionaryValue> extra_info);
	/**
	 * @brief ����һ���µ�brower
	 * @param winhandler �йܵ�һ��windows ui hwd
	 * @return �½���һ��brower
	 */
	CefRefPtr<QcefHandler> CreateBrowser(CefWindowHandle winhandler);
	/**
	 * @brief ��ʼCEF����Ϣѭ��
	 */
	virtual void Run();
    /**
     * @brief �˳���Ϣѭ��
     */
    virtual void Stop();
private:
	//! ��ͬ���ҳ��
	std::vector<CefRefPtr<QcefHandler>> m_clients;
	//! ����
	static CefRefPtr<QcefApp> m_app;
	//! ��������
	IMPLEMENT_REFCOUNTING(QcefApp);
};

#endif

