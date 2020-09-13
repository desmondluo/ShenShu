#include "qcef_app.h"

QcefApp::QcefApp()
{
	// 做一些CEF的全局初始化的东西
	// 初始化高DPI的支持
	CefEnableHighDPISupport();
	// 命令行初始化, 并不打算加入什么初始化命令，如果后面要加的话, 直接这个地方加就好了
	CefMainArgs main_args;
	int32_t excode = CefExecuteProcess(main_args, this, nullptr);
	if (excode < 0)
	{
		// 如果失败的话, 可能是sanbox的问题
		CefSettings settings;
		settings.no_sandbox = true;
		if (!CefInitialize(main_args, settings, this, nullptr))
		{
			throw std::runtime_error("启动CEF进程失败, 错误码:" + std::to_string(excode));
			// 直接退出
			exit(excode);
		}
	}
}

QcefApp::~QcefApp()
{
	// 挨个关闭
	for (int32_t i = 0; i < (int32_t)m_clients.size(); ++i)
	{
		m_clients[i]->Release();
	}
	// 回收CEF的资源
	CefShutdown();
}

void QcefApp::OnContextInitialized()
{
	
}

CefRefPtr<CefBrowserProcessHandler> QcefApp::GetBrowserProcessHandler()
{
	return this;
}

CefRefPtr<CefHandler> QcefApp::CreateBrowser()
{
	//! 创建一个handler， 并且管理起来
	CefRefPtr<CefHandler> handler = new CefHandler(m_clients.size());
	m_clients.resize(m_clients.size() + 1);
	m_clients[m_clients.size() - 1] = handler;
	return handler;
}



