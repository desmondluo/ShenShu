#include "cef_tab.h"
#include "../qcef/cef_handler.h"

CefTab::CefTab(QTabWidget* parent):
    m_parent(parent),
    m_icon_download(parent)
{
    // 初始化CEF的组件
    m_cef_widget = new CefWidget(this);
    m_url_line = new CefUrlLineEdit;
    // 连接信号
    connect(m_url_line, SIGNAL(returnPressed()), this, SLOT(UrlEntered()));
    auto layout = new QGridLayout;
    layout->addWidget(m_url_line);
    layout->addWidget(m_cef_widget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->setRowStretch(0, 0);
    layout->setRowStretch(1, 1);
    setLayout(layout);
    
    bool success = connect(m_cef_widget->GetHandler().get(), &QcefHandler::IconUrlChange, this, &CefTab::ChangeIcon);
    connect(&m_icon_download, SIGNAL(Finished()), this, SLOT(IconDownloadFinisned()));
}

CefTab::~CefTab()
{
}

void CefTab::DoClose()
{
    m_cef_widget->DoClose();
}

bool CefTab::Closed()
{
    return m_cef_widget->CefClosed();
}

void CefTab::ChangeIcon(QString fileurl)
{
    m_icon_download.StartDownload(fileurl);
}

void CefTab::IconDownloadFinisned()
{
    QPixmap image;
    image.loadFromData(m_icon_download.DownloadData());
    int32_t index = m_parent->indexOf(this);
    m_parent->setTabIcon(index, QIcon(image));
}

void CefTab::UrlEntered()
{
    m_cef_widget->LoadUrl(m_url_line->text());
}
