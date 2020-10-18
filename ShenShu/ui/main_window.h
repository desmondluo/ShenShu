/**
 * @file main_window.h
 * @brief 整个框架的window
 * @auther desmond
 * @date 2020-09-16
 * @copyright desmond
 * @version 1.0
 */
#ifndef QT_CEF_POC_MAINWINDOW_H_
#define QT_CEF_POC_MAINWINDOW_H_

#include <QtWidgets>
#include <qtimer.h>
#include "cef_widget.h"

/**
 * @brief UI框架
 */
class MainWindow: public QMainWindow {
  Q_OBJECT
public:
    /**
     * @brief 构造函数
     * @param 父节点
     */
    MainWindow(QWidget *parent = 0);
    /**
     * @brief 析构函数
     */
    ~MainWindow();

protected:
    /**
     * @brief 收到关闭事件
     * @param event 事件
     */
    void closeEvent(QCloseEvent* event);
    /**
     * @brief 准备关闭
     */
    void preClose();
    /**
     * @brief 添加一个新的tab
     */
    void addTab();
private:
    QTabWidget* m_tab_widget;
    //! 关闭次数
    int32_t m_close_times;
    //! 关闭定时器
    QTimer* m_close_timer;
    //! CEF的消息循环定时器
    QTimer* m_loop_timer;
private slots:
    /**
     * @brief 检查关闭时候的回调
     */
    void CheckClose();
    /**
     * @brief 定时器触发
     * @param 定时器事件
     */
    void timerEvent();
    /**
     * @brief 关闭一个tab
     * @param index 关闭的索引
     */
    void CloseTab(int32_t index);
};

#endif // QT_CEF_POC_MAINWINDOW_H_
