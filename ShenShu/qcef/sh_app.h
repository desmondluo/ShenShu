#pragma once

/**
 * @file sh_app.h
 * @brief SHApp��������������browser�Ĺ�����, ��������кܶ��browser, �������ͳһ�Ĺ���, ͬʱ������̼���Ļص���Ϣ����
 * @auther desmond
 * @date 2020-09-14
 * @copyright desmond
 * @version 1.0
 */

#ifndef QCEF_SH_APP_H_
#define QCEF_SH_APP_H_

#include "include/cef_app.h"
#include "cef_handler.h"

/**
 * @brief ȫ�������������, ���browser��������ʵ��tab�Ĺ���
 */
class SHApp
{
public:
	/**
	 * @brief ���캯��
	 */
    SHApp();
	/**
	 * @brief ��������
	 */
	virtual ~SHApp();
    /**
     * @brief �ͷ�����
     */
    void Release();
	/**
	 * @brirf ȫ�ֵ���, �κεط����Ի�ȡ���app, �����������Ҫ��֤�Լ��ľ����̰߳�ȫ
	 */
	static SHApp& Instance();
	/**
	 * @brief ��ʼCEF����Ϣѭ��
	 */
	virtual void Run();
    /**
     * @brief �˳���
     */
    int32_t ExitCode();
private:
	//! ����
    static SHApp* m_app;
    //! �ӽ���, close֮ǰ����һ�ν��̽���, ��Ҫ�˳���
    int32_t m_exit;
};

#endif

