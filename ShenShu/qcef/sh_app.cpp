#include "sh_app.h"

SHApp* SHApp::m_app = nullptr;

SHApp::SHApp()
{
    // ��һЩCEF��ȫ�ֳ�ʼ���Ķ���
    // ��ʼ����DPI��֧��
    CefEnableHighDPISupport();
    // �����г�ʼ��, �����������ʲô��ʼ������������Ҫ�ӵĻ�, ֱ������ط��Ӿͺ���
    CefMainArgs main_args;
    int32_t excode = CefExecuteProcess(main_args, nullptr, nullptr);
    if (excode < 0)
    {
        // ���ʧ�ܵĻ�, ������sanbox������
        CefSettings settings;
        settings.no_sandbox = true;
        if (!CefInitialize(main_args, settings, nullptr, nullptr))
        {
            throw std::runtime_error("����CEF����ʧ��, ������:" + std::to_string(excode));
            // ֱ���˳�
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
