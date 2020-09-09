#pragma once

#include <cstdint>
#include <QtCore/qglobal.h>
#include <QString>
#include <QPointer>
#include <QMetaType>

class QCefQuery
{
public:
	/**
	 * @brief 构造函数
	 */
	QCefQuery();
	/**
	 * @brief 构造函数
	 */
	QCefQuery(QString req, int64_t query);
	/**
	 * @brief 析构函数
	 * @param pther 另一个CefQuery
	 */
	QCefQuery(const QCefQuery& other);
	/**
	 * @brief 赋值构造
	 * @param other 另一个CefQuery
	 */
	QCefQuery& operator=(const QCefQuery& other);
	/**
	 * @brief 析构函数
	 */
	~QCefQuery();
	/**
	 * @brief 请求地址
	 */
	const QString request() const;
	/**
	 * @brief 请求id
	 */
	const int64_t id() const;
	/**
	 * @brief 请求结果
	 * @return 结果
	 */
	const QString response() const;
	/**
	 * @brief 结果
	 */
	const bool result() const;
	/**
	 * @brief 错误吗
	 */
	const int error() const;
	/**
	 * @brief 设置请求结果
	 * @param success 是否请求成功
	 * @param response 请求结果
	 * @param error 错误码
	 */
	void setResponseResult(bool success, const QString& response, int32_t error = 0);
private:
	//! 请求id
	int64_t m_id;
	//! 请求参数
	QString m_request;
	//! 请求结果
	mutable QString m_response;
	//! 是否请求成功
	mutable bool m_result;
	//! 发生的错误
	mutable int32_t m_error;
	//! 类型id
	static int32_t m_typeid;

};

