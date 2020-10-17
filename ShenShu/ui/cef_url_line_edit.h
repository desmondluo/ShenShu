
/**
 * @file cef_url_line_edit.h
 * @brief cef的地址口
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
 * @brief CEF的地址编辑框
 */
class CefUrlLineEdit:
    public QLineEdit
{
    Q_OBJECT
public:
    /**
     * @brief 构造函数
     */
    CefUrlLineEdit(QWidget* parent = 0);
    /**
     * @brief 析构函数
     */
    ~CefUrlLineEdit();
protected:
    /**
     * @brief 当获得焦点
     * @param 焦点事件
     */
    virtual void focusInEvent(QFocusEvent* event) override;
    /**
     * @brief 当失去焦点
     * @param 焦点事件
     */
    virtual void focusOutEvent(QFocusEvent* event) override;
};
#endif
