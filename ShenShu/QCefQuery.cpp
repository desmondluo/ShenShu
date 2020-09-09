#include "QCefQuery.h"

QCefQuery::QCefQuery():
	m_id(-1),
	m_result(false),
	m_error(0)
{}

QCefQuery::QCefQuery(QString req, int64_t query):
	m_id(query),
	m_request(req),
	m_error(01)
{}

QCefQuery::QCefQuery(const QCefQuery& other)
{
	m_request = other.m_request;
	m_id = other.m_id;
	m_response = other.m_response;
	m_error = other.m_error;
	m_result = other.m_result;
}

QCefQuery& QCefQuery::operator=(const QCefQuery& other)
{
	m_request = other.m_request;
	m_id = other.m_id;
	m_response = other.m_response;
	m_error = other.m_error;
	m_result = other.m_result;
	return *this;
}

QCefQuery::~QCefQuery()
{}

const QString QCefQuery::request() const
{
	return m_request;
}

const int64_t QCefQuery::id() const
{
	return m_id;
}

const QString QCefQuery::response() const
{
	return m_response;
}

const bool QCefQuery::result() const
{
	return m_result;
}

const int QCefQuery::error() const
{
	return m_error;
}

void QCefQuery::setResponseResult(bool success, const QString& response, int error /*= 0*/)
{
	m_result = success;
	m_response = response;
	m_error = error;
}



