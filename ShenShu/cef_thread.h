/**
 * @file cef_thread.h
 * @brief CEF��ר���߳�, ����������Ϣѭ��
 * @auther desmond
 * @date 2020-09-16
 * @copyright desmond
 * @version 1.0
 */
#pragma once
#include <QThread>

/**
 * @brief cef��ר���߳�
 */
class CefThread: public QThread
{
	Q_OBJECT
public:
	/**
	 * @brief �̳��麯��
	 */
	void run();
};

