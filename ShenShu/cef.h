#ifndef QT_CEF_POC_CEF_H_
#define QT_CEF_POC_CEF_H_

#include "include/cef_app.h"
/**
 * @brief CEF事例
 */
class Cef {

public:
	/**
	 * @brief 构造函数
	 * @param argc 参数数量
	 * @param argv 参数
	 */
	Cef(int argc, char *argv[]);
	/**
	 * @brief 析构函数
	 */
	~Cef();
	/**
	 * @brief 是否初始化失败
	 * @param 初始化失败参数
	 */
	int EarlyExitCode();
	/**
	 * @brief 消息循环启动
	 */
	void Tick();
 private:
	//! 如果启动失败的话的， 失败码
	int early_exit_code_;
	//! CEF的启动参数
	cef_main_args_t MainArgs(int argc, char *argv[]);
};

#endif // QT_CEF_POC_CEF_H_
