<<<<<<< HEAD
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
=======
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

private slots:
    void inputSlot(int priority, QString const& description);

private:
    void setupInterface();
    void setupConnection();

    QPushButton * inputButton;
    TaskInputPanel inputPanel;
};

#endif // TASKINPUTWIDGET_H
>>>>>>> f359a0c0026ba333e7db66123c0441d64f65cd1a
