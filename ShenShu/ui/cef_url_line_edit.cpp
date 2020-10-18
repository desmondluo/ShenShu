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
    qDebug() << QString::fromLocal8Bit("�յ�ʧȥ������ź�, ׼��ǿ��ʧȥ����");
    clearFocus();
}
