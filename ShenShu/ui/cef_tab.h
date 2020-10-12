/**
 * @file cef_tab.h
 * @brief 单个cef的tab
 * @auther desmond
 * @date 2020-09-16
 * @copyright desmond
 * @version 1.0
 */

#pragma once
#ifndef UI_CEF_TAB_H_
#define UI_CEF_TAB_H

#include <QtWidgets/QtWidgets>
#include "cef_widget.h"
#include "../util/file_download.h"



class CefTab:
    public QFrame
{
    Q_OBJECT
public:
    /**
     * @brief 构造函数
     * @param parent 父节点
     */
    CefTab(QTabWidget* parent);
    /**
     * @brief 析构函数
     */
    ~CefTab();
    /**
     * @brief 准备关闭
     */
    void DoClose();
    /**
     * @brief 是否已经关闭
     * @return 是否已经关闭
     */
    bool Closed();
public slots:
    /**
     * @brief 当按下回车键的时候
     */
    void UrlEntered();
    /**
     * @brief 当icon下载完成
     */
    void IconDownloadFinisned();
    /**
 * @brief 改变ico
 */
    void ChangeIcon(QString fileurl);
private:
    //! 父节点的tab
    QTabWidget* m_parent;
    //! 内部的cef结点
    CefWidget* m_cef_widget;
    //! 内不能的地址栏
    QLineEdit* m_url_line;
private:
    FileDownload m_icon_download;
};

#endif

