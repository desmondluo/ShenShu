#pragma once
#include <qwidget.h>
#include <include/cef_client.h>
class QCefClient :
	public QWidget,
	public CefClient
{
	Q_OBJECT
};

