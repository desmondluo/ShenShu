#include "cef_widget.h"
#include <Windows.h>
#include "include/cef_client.h"
#include "cef_handler.h"

QPointer<QWidget> CefWidget::EmbedBrowser(QMainWindow *main_win,
                                          QLineEdit *url_line_edit) {
	CefWindowInfo win_info;
    win_info.SetAsChild((CefWindowHandle) winId(),
                      RECT { 0, 0, width(), height() });
	CefBrowserSettings settings;
    CefRefPtr<CefHandler> handler(new CefHandler());
    browser_ = CefBrowserHost::CreateBrowserSync(win_info,
                                               handler,
                                               CefString("http://baidu.com"),
                                               settings,
                                               nullptr,
                                               nullptr);
    return nullptr;
}

void CefWidget::UpdateSize() {
  // 基本的调整一下大小
  if (browser_) {
    auto browser_host = browser_->GetHost();
    auto browser_win = browser_host->GetWindowHandle();
    SetWindowPos(browser_win, (HWND) this->winId(), 0, 0,
                 this->width(), this->height(),
                 SWP_NOZORDER);
    browser_host->NotifyMoveOrResizeStarted();
  }
}
