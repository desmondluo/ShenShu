#pragma once

/**
 * @file sh_app.h
 * @brief SHApp是用来管理所有browser的管理器, 程序可能有很多个browser, 这里进行统一的管理, 同时负责进程级别的回调消息处理
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
 * @brief 全局浏览器管理器, 多个browser，有助于实现tab的功能
 */
class SHApp
{
public:
	/**
	 * @brief 构造函数
	 */
    SHApp();
	/**
	 * @brief 析构函数
	 */
	virtual ~SHApp();
    /**
     * @brief 释放自身
     */
    void Release();
	/**
	 * @brirf 全局单例, 任何地方可以获取这个app, 所以这个里面要保证自己的绝对线程安全
	 */
	static SHApp& Instance();
	/**
	 * @brief 开始CEF的消息循环
	 */
	virtual void Run();
    /**
     * @brief 退出码
     */
    int32_t ExitCode();
private:
	//! 自身
    static SHApp* m_app;
    //! 子进程, close之前会有一次进程进入, 是要退出的
    int32_t m_exit;
};

#endif

