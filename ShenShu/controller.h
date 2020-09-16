/**
 * @file controller.h
 * @brief ȫ�ֿ�����, ����UI�߳�, CEF�̵߳�
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
	 * @brief ���캯���� �������
	 * @param argc ��������
	 * @param argv ����
	 */
	Controller(int32_t argc, char* argv[]);
	/**
	 * @brief ��������
	 */
	~Controller();
	/**
	 * @brief ��������
	 */
	void ManagerLoop();
	/**
	 * @brief ����CEF����Ϣѭ��
	 */
	void CefLoop();
private:
	//! QT��UI����, Ҳ�����̵߳�����
	QApplication m_qt_app;
	//! CEF�߳�
	CefThread m_cef_thread;
};

