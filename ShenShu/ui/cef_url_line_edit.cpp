#include "cef_url_line_edit.h"
#include <QDebug>
#include <QMouseEvent>

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
}

void CefUrlLineEdit::focusOutEvent(QFocusEvent* event)
{
    QLineEdit::focusOutEvent(event);
}


void CefUrlLineEdit::sloseFocus()
{
    qDebug() << QString::fromLocal8Bit("收到失去焦点的信号, 准备强制失去焦点");
    clearFocus();
}
