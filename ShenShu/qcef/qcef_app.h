#pragma once

/**
 * @file qcef_app.h
 * @brief ����CEF�������handler, ������CefHander��Ӧ, ÿ��APP�����һ��handler
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
     * @brief ���캯��
     * @param index ����
     */
    QCefApp(int32_t index);
    /**
     * @brief ��������
     */
    ~QCefApp();
    /**
     * @brief ��ȡ�������handler
     */
    virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE;
    /**
     * @brief ��ȡ��Ⱦ��handler
     */
    virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() OVERRIDE;
    /**
     * @brief ���������
     * @param winhandler cef�йܵ�handler
     * @param url ��һ�γ�ʼ����ϵ�url
     */
    void CreateBrowser(CefWindowHandle winhandler, std::string url);
    /**
     * @brief ��ȡ�����
     * @return ��ȡ���������
     */
    CefRefPtr<CefBrowser> GetBrowser();
private:
    //! ����
    int32_t m_index;
    //! ��Ӧ��handler
    CefRefPtr<QcefHandler> m_ptr_handler;
private:
    IMPLEMENT_REFCOUNTING(QCefApp);
};

#endif

