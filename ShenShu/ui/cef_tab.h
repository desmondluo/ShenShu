/**
 * @file cef_tab.h
 * @brief ����cef��tab
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
     * @brief ���캯��
     * @param parent ���ڵ�
     */
    CefTab(QTabWidget* parent);
    /**
     * @brief ��������
     */
    ~CefTab();
    /**
     * @brief ׼���ر�
     */
    void DoClose();
    /**
     * @brief �Ƿ��Ѿ��ر�
     * @return �Ƿ��Ѿ��ر�
     */
    bool Closed();
public slots:
    /**
     * @brief �����»س�����ʱ��
     */
    void UrlEntered();
    /**
     * @brief ��icon�������
     */
    void IconDownloadFinisned();
    /**
 * @brief �ı�ico
 */
    void ChangeIcon(QString fileurl);
private:
    //! ���ڵ��tab
    QTabWidget* m_parent;
    //! �ڲ���cef���
    CefWidget* m_cef_widget;
    //! �ڲ��ܵĵ�ַ��
    QLineEdit* m_url_line;
private:
    FileDownload m_icon_download;
};

#endif

