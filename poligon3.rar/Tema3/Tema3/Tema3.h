#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tema3.h"

class Tema3 : public QMainWindow
{
    Q_OBJECT

public:
    Tema3(QWidget *parent = nullptr);
    ~Tema3();

private:
    Ui::Tema3Class ui;
};
