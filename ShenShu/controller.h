/**
 * @file controller.h
 * @brief 全局控制器, 控制UI线程, CEF线程等
 * @auther desmond
 * @date 2020-09-16
 * @copyright desmond
 * @version 1.0
 */
#pragma once

#include <QApplication>
#include <QThread>
#include "cef_thread.h"

class Controller: QObject
{
	Q_OBJECT
public:
	/**
	 * @brief 构造函数， 传入入参
	 * @param argc 参数个数
	 * @param argv 参数
	 */
	Controller(int32_t argc, char* argv[]);
	/**
	 * @brief 析构函数
	 */
	~Controller();
	/**
	 * @brief 程序起来
	 */
	void ManagerLoop();
	/**
	 * @brief 启动CEF的消息循环
	 */
	void CefLoop();
private:
	//! QT的UI事例, 也是主线程的事例
	QApplication m_qt_app;
	//! CEF线程
	CefThread m_cef_thread;
};

