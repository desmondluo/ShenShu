#pragma once

/**
 * @file qcef_app.h
 * @brief CefApp是用来管理所有browser的管理器, 程序可能有很多个browser, 这里进行统一的管理, 同时负责进程级别的回调消息处理
 * @auther desmond
 * @date 2020-09-14
 * @copyright desmond
 * @version 1.0
 */

#ifndef QCEF_QCEF_APP_H_
#define QCEF_QCEF_APP_H_

#include "include/cef_app.h"

/**
 * @brief 全局浏览器管理器
 */
class QcefApp:
	public CefApp,
	public CefBrowserProcessHandler
{
public:
	/**
	 * @brief 构造函数
	 */
	QcefApp();
	/**
	 * @brief 析构函数
	 */
	virtual ~QcefApp();
	/**
	 * @brief 当初始化完毕的回调
	 */
	virtual void OnContextInitialized();
	/**
	 * @brief 重载获取进程级别重载的类型
	 */
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler();

};

#endif

