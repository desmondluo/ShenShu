#include "file_download.h"

FileDownload::FileDownload(QUrl fileurl, QObject* parent):
    QObject(parent)
{
    connect(&m_web_ctrl, SIGNAL(finished(QNetworkReply*)), this, SLOT(FileDownloaded(QNetworkReply*)));
    QNetworkRequest request(fileurl);
    m_web_ctrl.get(request);
}

FileDownload::FileDownload(QObject* parent):
    QObject(parent)
{
    connect(&m_web_ctrl, SIGNAL(finished(QNetworkReply*)), this, SLOT(FileDownloaded(QNetworkReply*)));
}

void FileDownload::StartDownload(QUrl fileurl)
{
   // m_web_ctrl.
    m_request.setUrl(fileurl);
    m_web_ctrl.get(m_request);
}

FileDownload::~FileDownload()
{
}

QByteArray FileDownload::DownloadData() const
{
    return m_data;
}

void FileDownload::FileDownloaded(QNetworkReply* reply)
{
    m_data = reply->readAll();
    reply->deleteLater();
    emit Finished();
}
