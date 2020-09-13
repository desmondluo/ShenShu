#include "qcef_app.h"

QcefApp::QcefApp()
{
	// ��һЩCEF��ȫ�ֳ�ʼ���Ķ���
	// ��ʼ����DPI��֧��
	CefEnableHighDPISupport();
	// �����г�ʼ��, �����������ʲô��ʼ������������Ҫ�ӵĻ�, ֱ������ط��Ӿͺ���
	CefMainArgs main_args;
	int32_t excode = CefExecuteProcess(main_args, this, nullptr);
	if (excode < 0)
	{
		// ���ʧ�ܵĻ�, ������sanbox������
		CefSettings settings;
		settings.no_sandbox = true;
		if (!CefInitialize(main_args, settings, this, nullptr))
		{
			throw std::runtime_error("����CEF����ʧ��, ������:" + std::to_string(excode));
			// ֱ���˳�
			exit(excode);
		}
	}
}

QcefApp::~QcefApp()
{
	// �����ر�
	for (int32_t i = 0; i < (int32_t)m_clients.size(); ++i)
	{
		m_clients[i]->Release();
	}
	// ����CEF����Դ
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
	//! ����һ��handler�� ���ҹ�������
	CefRefPtr<CefHandler> handler = new CefHandler(m_clients.size());
	m_clients.resize(m_clients.size() + 1);
	m_clients[m_clients.size() - 1] = handler;
	return handler;
}



