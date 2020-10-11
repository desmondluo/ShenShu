#pragma once

/**
 * @file file_download.h
 * @brief �ļ�������
 * @auther desmond
 * @date 2020-10-11
 * @copyright desmond
 * @version 1.0
 */


#ifndef UTIL_FILE_DOWNLOAD_H_
#define UTIL_FILE_DOWNLOAD_H_

#include <QObject>
#include <QByteArray>
#include <QtNetwork/QtNetwork>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

/**
 * @brief �ļ�������
 */
class FileDownload:
    public QObject
{
    Q_OBJECT
public:
    /**
     * @brief ���캯��
     * @param fileurl �ļ���ַ
     * @param parent ���ڵ�
     */
    explicit  FileDownload(QUrl fileurl, QObject *parent);
    /*
     * @brief ���캯��
     * @param parent ���ڵ�
     */
    explicit  FileDownload(QObject* parent);
    /**
     * @brief ��ʼһ���µ��ļ�����
     * @param fileurl �ļ���ַ
     */
    void StartDownload(QUrl fileurl);
    /**
     * @brief ��������
     */
    virtual ~FileDownload();
    /**
     * @brief ���صõ�������
     */
    QByteArray DownloadData() const;
signals:
    /**
     * @brief �ļ��������֮�󷢳����ź�
     */
    void Finished();
private slots:
    /**
     * @brief �ļ��������
     */
    void FileDownloaded(QNetworkReply* reply);
private:
    QNetworkRequest m_request;
    //! ������
    QNetworkAccessManager m_web_ctrl;
    //! ������ɴ�ŵ�����
    QByteArray m_data;
};

#endif

