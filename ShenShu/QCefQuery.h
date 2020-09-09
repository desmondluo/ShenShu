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
	 * @brief ���캯��
	 */
	QCefQuery();
	/**
	 * @brief ���캯��
	 */
	QCefQuery(QString req, int64_t query);
	/**
	 * @brief ��������
	 * @param pther ��һ��CefQuery
	 */
	QCefQuery(const QCefQuery& other);
	/**
	 * @brief ��ֵ����
	 * @param other ��һ��CefQuery
	 */
	QCefQuery& operator=(const QCefQuery& other);
	/**
	 * @brief ��������
	 */
	~QCefQuery();
	/**
	 * @brief �����ַ
	 */
	const QString request() const;
	/**
	 * @brief ����id
	 */
	const int64_t id() const;
	/**
	 * @brief ������
	 * @return ���
	 */
	const QString response() const;
	/**
	 * @brief ���
	 */
	const bool result() const;
	/**
	 * @brief ������
	 */
	const int error() const;
	/**
	 * @brief ����������
	 * @param success �Ƿ�����ɹ�
	 * @param response ������
	 * @param error ������
	 */
	void setResponseResult(bool success, const QString& response, int32_t error = 0);
private:
	//! ����id
	int64_t m_id;
	//! �������
	QString m_request;
	//! ������
	mutable QString m_response;
	//! �Ƿ�����ɹ�
	mutable bool m_result;
	//! �����Ĵ���
	mutable int32_t m_error;
	//! ����id
	static int32_t m_typeid;

};

