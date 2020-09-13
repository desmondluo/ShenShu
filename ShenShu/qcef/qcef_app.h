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

/**
 * @brief ȫ�������������
 */
class QcefApp:
	public CefApp,
	public CefBrowserProcessHandler
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
	 * @brief ����ʼ����ϵĻص�
	 */
	virtual void OnContextInitialized();
	/**
	 * @brief ���ػ�ȡ���̼������ص�����
	 */
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler();

};

#endif

