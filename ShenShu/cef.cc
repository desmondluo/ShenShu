#include "cef.h"

Cef::Cef(int argc, char *argv[]) {
	// 执行一些初始化动作
	// 支持高dpi
	CefEnableHighDPISupport();
	// 启动参数
    CefMainArgs main_args(this->MainArgs(argc, argv));
	// 执行初始化
	early_exit_code_ = CefExecuteProcess(main_args, NULL, NULL);
	// 如果初始化失败
	if (early_exit_code_ < 0) 
	{
		CefSettings settings;
		settings.no_sandbox = true;
		// 初始化
		if (!CefInitialize(main_args, settings, NULL, NULL)) 
		{
			throw std::runtime_error("Unable to initialize CEF");
		}
	}
}

Cef::~Cef() 
{
	if (early_exit_code_ < 0)
	{
		// 释放资源
		CefShutdown();
	}
}

int Cef::EarlyExitCode() 
{
	return early_exit_code_;
}

void Cef::Tick() {
  CefDoMessageLoopWork();
}
