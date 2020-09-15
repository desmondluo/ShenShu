/**
 * @file main_window.h
 * @brief ������ܵ�window
 * @auther desmond
 * @date 2020-09-16
 * @copyright desmond
 * @version 1.0
 */
#ifndef QT_CEF_POC_MAINWINDOW_H_
#define QT_CEF_POC_MAINWINDOW_H_

#include <QtWidgets>
#include "cef_widget.h"

/**
 * @brief UI���
 */
class MainWindow: public QMainWindow {
  Q_OBJECT
public:
	/**
	 * @brief ���캯��
	 * @param ���ڵ�
	 */
	MainWindow(QWidget *parent = 0);
	/**
	 * @brief ��������
	 */
	~MainWindow();

protected:
	/**
	 * @brief ��ʱ������
	 * @param ��ʱ���¼�
	 */
    void timerEvent(QTimerEvent *event);
private:
	//! CEF��UI�й���
	CefWidget *cef_widg_;
	//! ����ĵ�ַ��
	QLineEdit *url_line_edit_;
	//! ����layout
	QGridLayout *layout;
private slots:
	/**
	 * @brief ��url������ʱ��Ļص�
	 */
	void UrlEntered();
};

#endif // QT_CEF_POC_MAINWINDOW_H_
