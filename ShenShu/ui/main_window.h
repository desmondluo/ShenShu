﻿/**
 * @file main_window.h
 * @brief 整个框架的window
 * @auther desmond
 * @date 2020-09-16
 * @copyright desmond
 * @version 1.0
 */
#ifndef QT_CEF_POC_MAINWINDOW_H_
#define QT_CEF_POC_MAINWINDOW_H_

#include <QtWidgets>
#include <qtimer.h>
#include "cef_widget.h"

/**
 * @brief UI框架
 */
class MainWindow: public QMainWindow {
  Q_OBJECT
public:
	/**
	 * @brief 构造函数
	 * @param 父节点
	 */
	MainWindow(QWidget *parent = 0);
	/**
	 * @brief 析构函数
	 */
	~MainWindow();

protected:
    /**
     * @brief 收到关闭事件
     * @param event 事件
     */
    void closeEvent(QCloseEvent* event);
    /**
     * @brief 准备关闭
     */
    void preClose();
private:
	//! CEF的UI托管体
	CefWidget *cef_widg_;
	//! 上面的地址栏
	QLineEdit *url_line_edit_;
	//! 整体layout
	QGridLayout *layout;
    //! 关闭次数
    int32_t m_close_times;
    //! 关闭定时器
    QTimer* m_close_timer;
    //! CEF的消息循环定时器
    QTimer* m_loop_timer;
private slots:
	/**
	 * @brief 当url被输入时候的回调
	 */
	void UrlEntered();
    /**
     * @brief 检查关闭时候的回调
     */
    void CheckClose();
    /**
     * @brief 定时器触发
     * @param 定时器事件
     */
    void timerEvent();
};

#endif // QT_CEF_POC_MAINWINDOW_H_