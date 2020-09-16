#include "qcef_app.h"

CefRefPtr<QcefApp> QcefApp::m_app = nullptr;

QcefApp::QcefApp()
{
	// 做一些CEF的全局初始化的东西
	// 初始化高DPI的支持
	CefEnableHighDPISupport();
	// 命令行初始化, 并不打算加入什么初始化命令，如果后面要加的话, 直接这个地方加就好了
	CefMainArgs main_args;
	int32_t excode = CefExecuteProcess(main_args, nullptr, nullptr);
	if (excode < 0)
	{
		// 如果失败的话, 可能是sanbox的问题
		CefSettings settings;
        settings.multi_threaded_message_loop = true;
		settings.no_sandbox = true;
		if (!CefInitialize(main_args, settings, nullptr, nullptr))
		{
			throw std::runtime_error("启动CEF进程失败, 错误码:" + std::to_string(excode));
			// 直接退出
			exit(excode);
		}
	}
}

QcefApp::~QcefApp()
{
	//CefBrowserHost::CloseBrowser(true);
	// 挨个关闭
	for (int32_t i = 0; i < (int32_t)m_clients.size(); ++i)
	{
		m_clients[i]->GetBrowser()->GetHost()->CloseBrowser(false);
		//m_clients[i]->Release();
	}
    //CefQuitMessageLoop();
	// 回收CEF的资源
	CefShutdown();
}

CefRefPtr<QcefApp> QcefApp::Instance()
{
	if (QcefApp::m_app == nullptr)
	{
		QcefApp::m_app = new QcefApp();
	}
	return m_app;
}

void QcefApp::OnContextInitialized()
{
	
}

CefRefPtr<CefBrowserProcessHandler> QcefApp::GetBrowserProcessHandler()
{
	return this;
}

void QcefApp::OnBrowserCreated(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefDictionaryValue> extra_info)
{
    int32_t a = 0;
}

CefRefPtr<QcefHandler> QcefApp::CreateBrowser(CefWindowHandle winhandler)
{
	//! 创建一个handler， 并且管理起来
	CefRefPtr<QcefHandler> handler = new QcefHandler(m_clients.size());
	m_clients.resize(m_clients.size() + 1);
	m_clients[m_clients.size() - 1] = handler;
	//! 创建浏览器
	CefWindowInfo wininfo;
	CefBrowserSettings settings;
    //settings.multi_threaded_message_loop = true;
	// 第一次并不知道在哪的, 但是这个不重要, 后面一旦外部的UI初始化完毕, 就会主动通知这个UI, 做对应的调整
	wininfo.SetAsChild(winhandler, RECT{ 0, 0, 0, 0 });
	CefRefPtr<CefBrowser> browser = CefBrowserHost::CreateBrowserSync(wininfo, handler, CefString("http://baidu.com"), settings, nullptr, nullptr);
	handler->SetBrower(browser);
	return handler;
}

void QcefApp::Run()
{
    CefDoMessageLoopWork();
   // CefRunMessageLoop();
}

void QcefApp::Stop()
{
    CefQuitMessageLoop();
}
