#include "sh_app.h"

SHApp* SHApp::m_app = nullptr;

SHApp::SHApp()
{
    // 做一些CEF的全局初始化的东西
    // 初始化高DPI的支持
    CefEnableHighDPISupport();
    // 命令行初始化, 并不打算加入什么初始化命令，如果后面要加的话, 直接这个地方加就好了
    CefMainArgs main_args;
    m_exit = CefExecuteProcess(main_args, nullptr, nullptr);
    if (m_exit < 0)
    {
        // 如果失败的话, 可能是sanbox的问题
        CefSettings settings;
        settings.no_sandbox = true;
        if (!CefInitialize(main_args, settings, nullptr, nullptr))
        {
            throw std::runtime_error("启动CEF进程失败, 错误码:" + std::to_string(m_exit));
            // 直接退出
            exit(m_exit);
        }
    }
}

SHApp::~SHApp()
{
    CefQuitMessageLoop();
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

int32_t SHApp::ExitCode()
{
    return m_exit;
}

void SHApp::CreateBrowser(CefWindowHandle winhandler, CefRefPtr<QcefHandler> cefhandler, std::string url)
{
    CefWindowInfo wininfo;
    CefBrowserSettings settings;
    //settings.multi_threaded_message_loop = true;
    // 第一次并不知道在哪的, 但是这个不重要, 后面一旦外部的UI初始化完毕, 就会主动通知这个UI, 做对应的调整
    wininfo.SetAsChild(winhandler, RECT{ 0, 0, 0, 0 });
    CefBrowserHost::CreateBrowserSync(wininfo, cefhandler, CefString("http://baidu.com"), settings, nullptr, nullptr);
}

