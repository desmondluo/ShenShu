#include "qcef_app.h"

QcefApp::QcefApp()
{

}

QcefApp::~QcefApp()
{

}

void QcefApp::OnContextInitialized()
{

}

CefRefPtr<CefBrowserProcessHandler> QcefApp::GetBrowserProcessHandler()
{
	return this;
}



