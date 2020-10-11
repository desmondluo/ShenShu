#include "sh_app.h"

SHApp* SHApp::m_app = nullptr;

SHApp::SHApp()
{
    // ��һЩCEF��ȫ�ֳ�ʼ���Ķ���
    // ��ʼ����DPI��֧��
    CefEnableHighDPISupport();
    // �����г�ʼ��, �����������ʲô��ʼ������������Ҫ�ӵĻ�, ֱ������ط��Ӿͺ���
    CefMainArgs main_args;
    m_exit = CefExecuteProcess(main_args, nullptr, nullptr);
    if (m_exit < 0)
    {
        // ���ʧ�ܵĻ�, ������sanbox������
        CefSettings settings;
        settings.no_sandbox = true;
        if (!CefInitialize(main_args, settings, nullptr, nullptr))
        {
            throw std::runtime_error("����CEF����ʧ��, ������:" + std::to_string(m_exit));
            // ֱ���˳�
            exit(m_exit);
        }
    }
}

SHApp::~SHApp()
{
    CefQuitMessageLoop();
	CefShutdown();
    int32_t a = 0;
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