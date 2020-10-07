/**
 * @file cef_widget.h
 * @brief CEF���й����
 * @auther desmond
 * @date 2020-09-16
 * @copyright desmond
 * @version 1.0
 */
#ifndef QT_CEF_POC_CEFWIDGET_H_
#define QT_CEF_POC_CEFWIDGET_H_

#include "qcef/qcef_app.h"

#include <QtWidgets>
/**
 * @brief CEF��UI�й����
 */
class CefWidget: public QWidget {
  Q_OBJECT
 public:
	/**
	 * @brief ���캯��
	 * @param ���ڵ�
	 */
	CefWidget(QWidget *parent = 0);
	/**
	 * @brief ��������
	 */
    ~CefWidget();
	/**
	 * @brief �������µ�url��ʱ��
	 * @param url �µ�url
	 */
    void LoadUrl(const QString &url);
	/**
	 * @brief ����С�����ı��ʱ��
	 */
    void UpdateSize();

 protected:
	/**
	 * @brief ���ƶ���ʱ��
	 * @param �ƶ��¼�
	 */
    void moveEvent(QMoveEvent *event);
	/**
	 * @brief ����С�����ı��ʱ��
	 * @param ��С�ı��¼�
	 */
    void resizeEvent(QResizeEvent *event);
private:
	//! �ڲ��йܵ�cef�����
    CefRefPtr<QCefApp> m_ptr_app;
};

#endif // QT_CEF_POC_CEFWIDGET_H_
