#ifndef TASKINPUTWIDGET_H
#define TASKINPUTWIDGET_H

#include "taskinputpanel.h"

#include <QWidget>
#include <QPushButton>

class TaskInputWidget : public QWidget
{
public:
    TaskInputWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent * ) override;
private:
    void setupInterface();
    void setupInput();

    QPushButton * inputButton;
    TaskInputPanel inputPanel;
};

#endif // TASKINPUTWIDGET_H
