#ifndef TASKINPUTWIDGET_H
#define TASKINPUTWIDGET_H

#include "taskinputpanel.h"

#include <QWidget>
#include <QPushButton>

class TaskInputWidget : public QWidget
{
Q_OBJECT

public:
    TaskInputWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent * ) override;

signals:
    void inputSignal(int priority, QString const& description);

public slots:
    void showInputPanel();

private slots:
    void inputSlot(int priority, QString const& description);

private:
    void setupInterface();
    void setupConnections();

    QPushButton * inputButton;
    TaskInputPanel inputPanel;
};

#endif // TASKINPUTWIDGET_H
