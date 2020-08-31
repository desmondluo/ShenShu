#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ShenShu.h"

class ShenShu : public QMainWindow
{
    Q_OBJECT

public:
    ShenShu(QWidget *parent = Q_NULLPTR);

private:
    Ui::ShenShuClass ui;
};
