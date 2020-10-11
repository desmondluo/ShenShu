#pragma once

/**
 * @file file_download.h
 * @brief 文件下载器
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
 * @brief 文件下载器
 */
class FileDownload:
    public QObject
{
    Q_OBJECT
public:
    /**
     * @brief 构造函数
     * @param fileurl 文件地址
     * @param parent 父节点
     */
    explicit  FileDownload(QUrl fileurl, QObject *parent);
    /*
     * @brief 构造函数
     * @param parent 父节点
     */
    explicit  FileDownload(QObject* parent);
    /**
     * @brief 开始一个新的文件下载
     * @param fileurl 文件地址
     */
    void StartDownload(QUrl fileurl);
    /**
     * @brief 析构函数
     */
    virtual ~FileDownload();
    /**
     * @brief 下载得到的数据
     */
    QByteArray DownloadData() const;
signals:
    /**
     * @brief 文件下载完成之后发出的信号
     */
    void Finished();
private slots:
    /**
     * @brief 文件下载完成
     */
    void FileDownloaded(QNetworkReply* reply);
private:
    QNetworkRequest m_request;
    //! 下载器
    QNetworkAccessManager m_web_ctrl;
    //! 下载完成存放的数据
    QByteArray m_data;
};

#endif

