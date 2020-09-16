/**
 * @file cef_thread.h
 * @brief CEF的专属线程, 用来控制消息循环
 * @auther desmond
 * @date 2020-09-16
 * @copyright desmond
 * @version 1.0
 */
#pragma once
#include <QThread>

/**
 * @brief cef的专属线程
 */
class CefThread: public QThread
{
	Q_OBJECT
public:
	/**
	 * @brief 继承虚函数
	 */
	void run();
};

