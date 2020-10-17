#include "cef_url_line_edit.h"
#include <QDebug>

CefUrlLineEdit::CefUrlLineEdit(QWidget* parent):
    QLineEdit(parent)
{
}

CefUrlLineEdit::~CefUrlLineEdit()
{
}

void CefUrlLineEdit::focusInEvent(QFocusEvent* event)
{
    QLineEdit::focusInEvent(event);
    qDebug() << QString::fromLocal8Bit("得到焦点");
}

void CefUrlLineEdit::focusOutEvent(QFocusEvent* event)
{
    QLineEdit::focusOutEvent(event);
    qDebug() << QString::fromLocal8Bit("失去焦点");
}
