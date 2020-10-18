/**
 * @file cef_widget.h
 * @brief CEF的托管组件
 * @auther desmond
 * @date 2020-09-16
 * @copyright desmond
 * @version 1.0
 */
#ifndef QT_CEF_POC_CEFWIDGET_H_
#define QT_CEF_POC_CEFWIDGET_H_
#include <include/cef_app.h>

#include "../qcef/cef_handler.h"

class CefTab;

#include <QtWidgets>
/**
 * @brief CEF的UI托管组件
 */
class CefWidget: public QWidget {
  Q_OBJECT
 public:
    /**
     * @brief 构造函数
    * @param 父节点
     */
    CefWidget(QWidget *parent = 0);
    /**
     * @brief 构造函数
     * @param parent 父节点
     * @param url 初始化地址
     */
    CefWidget(QWidget* parent, QString url);
    /**
     * @brief 析构函数
     */
    ~CefWidget();
    /**
     * @brief 当加载新的url的时候
     * @param url 新的url
     */
    void LoadUrl(const QString &url);
    /**
     * @brief 当大小发生改变的时候
     */
    void UpdateSize();
    /**
     * @brief 关闭
     */
    void DoClose();
    /**
     * @brief CEF是否已经关闭
     */
    bool CefClosed();
    /**
     * @brief 获取这个CEF对应的handler
     * return 这个cef对应的handler
     */
    CefRefPtr<QcefHandler> GetHandler();
 protected:
    /**
     * @brief 当移动的时候
     * @param 移动事件
     */
    void moveEvent(QMoveEvent *event);
    /**
     * @brief 当大小发生改变的时候
     * @param 大小改变事件
     */
    void resizeEvent(QResizeEvent *event);
private:
    //! 内部托管的cef浏览器
    CefRefPtr<QcefHandler> m_ptr_handler;
};

#endif // QT_CEF_POC_CEFWIDGET_H_
