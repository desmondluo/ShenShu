#include "qcef_app.h"

CefRefPtr<QcefApp> QcefApp::m_app = nullptr;

QcefApp::QcefApp()
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
        settings.multi_threaded_message_loop = true;
		settings.no_sandbox = true;
		if (!CefInitialize(main_args, settings, nullptr, nullptr))
		{
			throw std::runtime_error("����CEF����ʧ��, ������:" + std::to_string(excode));
			// ֱ���˳�
			exit(excode);
		}
	}
}

QcefApp::~QcefApp()
{
	//CefBrowserHost::CloseBrowser(true);
	// �����ر�
	for (int32_t i = 0; i < (int32_t)m_clients.size(); ++i)
	{
		m_clients[i]->GetBrowser()->GetHost()->CloseBrowser(false);
		//m_clients[i]->Release();
	}
    //CefQuitMessageLoop();
	// ����CEF����Դ
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
	//! ����һ��handler�� ���ҹ�������
	CefRefPtr<QcefHandler> handler = new QcefHandler(m_clients.size());
	m_clients.resize(m_clients.size() + 1);
	m_clients[m_clients.size() - 1] = handler;
	//! ���������
	CefWindowInfo wininfo;
	CefBrowserSettings settings;
    //settings.multi_threaded_message_loop = true;
	// ��һ�β���֪�����ĵ�, �����������Ҫ, ����һ���ⲿ��UI��ʼ�����, �ͻ�����֪ͨ���UI, ����Ӧ�ĵ���
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
