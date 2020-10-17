
/**
 * @file cef_url_line_edit.h
 * @brief cef�ĵ�ַ��
 * @auther desmond
 * @date 2020-10-18
 * @copyright desmond
 * @version 1.0
 */

#pragma once

#ifndef UI_CEF_URL_LINE_EDIT_H_
#define UI_CEF_URL_LINE_EDIT_H_

#include <QLineEdit>

/**
 * @brief CEF�ĵ�ַ�༭��
 */
class CefUrlLineEdit:
    public QLineEdit
{
    Q_OBJECT
public:
    /**
     * @brief ���캯��
     */
    CefUrlLineEdit(QWidget* parent = 0);
    /**
     * @brief ��������
     */
    ~CefUrlLineEdit();
protected:
    /**
     * @brief ����ý���
     * @param �����¼�
     */
    virtual void focusInEvent(QFocusEvent* event) override;
    /**
     * @brief ��ʧȥ����
     * @param �����¼�
     */
    virtual void focusOutEvent(QFocusEvent* event) override;
};
#endif
