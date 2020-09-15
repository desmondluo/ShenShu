#ifndef QT_CEF_POC_CEFWIDGET_H_
#define QT_CEF_POC_CEFWIDGET_H_

#include <QtWidgets>
#include "include/cef_app.h"
#include "include/cef_browser.h"
#include "qcef/cef_handler.h"

class CefWidget : public QWidget {
  Q_OBJECT
 public:
  CefWidget(QWidget *parent = 0);
  ~CefWidget();

  // If result is non-null, it needs to replace this widget
  QPointer<QWidget> EmbedBrowser(QMainWindow *main_win,
                                 QLineEdit *url_line_edit);
  void LoadUrl(const QString &url);

  void UpdateSize();

 protected:
  void moveEvent(QMoveEvent *event);
  void resizeEvent(QResizeEvent *event);

 private:
  CefRefPtr<QcefHandler> m_handler;
};

#endif // QT_CEF_POC_CEFWIDGET_H_
