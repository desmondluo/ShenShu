#include "cef.h"

Cef::Cef(int argc, char *argv[]) {
	// ִ��һЩ��ʼ������
	// ֧�ָ�dpi
	CefEnableHighDPISupport();
	// ��������
    CefMainArgs main_args(this->MainArgs(argc, argv));
	// ִ�г�ʼ��
	early_exit_code_ = CefExecuteProcess(main_args, NULL, NULL);
	// �����ʼ��ʧ��
	if (early_exit_code_ < 0) 
	{
		CefSettings settings;
		settings.no_sandbox = true;
		// ��ʼ��
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
		// �ͷ���Դ
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
