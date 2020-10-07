#include "sh_app.h"

SHApp* SHApp::m_app = nullptr;

SHApp::SHApp()
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
        settings.no_sandbox = true;
        if (!CefInitialize(main_args, settings, nullptr, nullptr))
        {
            throw std::runtime_error("启动CEF进程失败, 错误码:" + std::to_string(excode));
            // 直接退出
            exit(excode);
        }
    }
}

SHApp::~SHApp()
{
	CefShutdown();
}

void SHApp::Release()
{
    delete m_app;
    m_app = nullptr;
}

SHApp& SHApp::Instance()
{
	if (SHApp::m_app == nullptr)
	{
        SHApp::m_app = new SHApp();
	}
	return *m_app;
}


void SHApp::Run()
{
    CefDoMessageLoopWork();
}
