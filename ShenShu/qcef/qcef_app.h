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
#include "cef_handler.h"

/**
 * @brief 全局浏览器管理器, 多个browser，有助于实现tab的功能
 */
class QcefApp:
	public CefApp,
	public CefBrowserProcessHandler,
    public CefRenderProcessHandler
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
	 * @brirf 全局单例, 任何地方可以获取这个app, 所以这个里面要保证自己的绝对线程安全
	 */
	static CefRefPtr<QcefApp> Instance();
	/**
	 * @brief 当初始化完毕的回调
	 */
	virtual void OnContextInitialized();
	/**
	 * @brief 重载获取进程级别重载的类型
	 */
	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler();
    virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefDictionaryValue> extra_info);
	/**
	 * @brief 创建一个新的brower
	 * @param winhandler 托管的一个windows ui hwd
	 * @return 新建的一个brower
	 */
	CefRefPtr<QcefHandler> CreateBrowser(CefWindowHandle winhandler);
	/**
	 * @brief 开始CEF的消息循环
	 */
	virtual void Run();
    /**
     * @brief 退出消息循环
     */
    virtual void Stop();
private:
	//! 不同浏览页面
	std::vector<CefRefPtr<QcefHandler>> m_clients;
	//! 自身
	static CefRefPtr<QcefApp> m_app;
	//! 定义引用
	IMPLEMENT_REFCOUNTING(QcefApp);
};

#endif

