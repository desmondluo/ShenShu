#include "cef_widget.h"
#include "qcef/qcef_app.h"

CefWidget::CefWidget(QWidget *parent): QWidget(parent) 
{
	// ��ʼ��һ�������
	m_handler = QcefApp::Instance()->CreateBrowser((CefWindowHandle)winId());
}

CefWidget::~CefWidget() 
{
  if (m_handler) 
  {
	  m_handler->GetBrowser()->GetHost()->CloseBrowser(true);
  }
}

void CefWidget::LoadUrl(const QString &url) 
{
  if (m_handler) 
  {
	  m_handler->GetBrowser()->GetMainFrame()->LoadURL(CefString(url.toStdString()));
  }
}

void CefWidget::moveEvent(QMoveEvent *event) 
{
  this->UpdateSize();
}

void CefWidget::resizeEvent(QResizeEvent *event) 
{
  this->UpdateSize();
}

void CefWidget::UpdateSize() {
	// �����ĵ���һ�´�С
	if (m_handler && m_handler->GetBrowser())
	{
		auto browser_host = m_handler->GetBrowser()->GetHost();
		auto browser_win = browser_host->GetWindowHandle();
		SetWindowPos(browser_win, (HWND)this->winId(), 0, 0,
			this->width(), this->height(),
			SWP_NOZORDER);
		browser_host->NotifyMoveOrResizeStarted();
	}
}
