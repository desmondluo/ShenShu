#pragma once

/**
 * @file qcef_app.h
 * @brief 单个CEF浏览器的handler, 跟单个CefHander对应, 每个APP会持有一个handler
 * @auther desmond
 * @date 2020-10-07
 * @copyright desmond
 * @version 1.0
 */


#ifndef QCEF_QCEF_APP_H_
#define QCEF_QCEF_APP_H_

#include <string>
#include "include/cef_app.h"
#include "include/cef_browser_process_handler.h"
#include "include/cef_render_process_handler.h"
#include "cef_handler.h"

class QCefApp:
    public CefApp,
    public CefBrowserProcessHandler,
    public CefRenderProcessHandler
{
public:
    /**
     * @brief 构造函数
     * @param index 索引
     */
    QCefApp(int32_t index);
    /**
     * @brief 析构函数
     */
    ~QCefApp();
    /**
     * @brief 获取浏览器的handler
     */
    virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE;
    /**
     * @brief 获取渲染的handler
     */
    virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() OVERRIDE;
    /**
     * @brief 创建浏览器
     * @param winhandler cef托管的handler
     * @param url 第一次初始化完毕的url
     */
    void CreateBrowser(CefWindowHandle winhandler, std::string url);
    /**
     * @brief 获取浏览器
     * @return 获取到的浏览器
     */
    CefRefPtr<CefBrowser> GetBrowser();
    /**
     * @brief 是否已经关闭
     * @return 是否已经关闭
     */
    bool IsClose();
private:
    //! 索引
    int32_t m_index;
    //! 对应的handler
    CefRefPtr<QcefHandler> m_ptr_handler;
private:
    IMPLEMENT_REFCOUNTING(QCefApp);
};

#endif

