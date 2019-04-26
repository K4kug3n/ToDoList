#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <vector>

#include "taskwidget.h"
#include "taskinputwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void addTask(int priority, QString const& description);
    void deleteTask(int priority, QString const& description);

    ~MainWindow();

signals:
    void inputSignal(int piority, QString const& description);
    void removeSignal(int piority, QString const& description);

private slots:
    void inputSlot(int priority, QString const& description);
    void removeSlot(int priority, QString const& description);

private:
    void setupInterface();
    void setupConnection();
    void setupConnection(TaskWidget * widget);

    QVBoxLayout * taskLayout;
    TaskInputWidget * taskInputWidget;
    std::vector<TaskWidget *> taskWidgets;
};

#endif // MAINWINDOW_H
