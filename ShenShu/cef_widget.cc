#include "cef_widget.h"
#include "qcef/qcef_app.h"

CefWidget::CefWidget(QWidget *parent): QWidget(parent) 
{
	// 初始化一个浏览器
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
