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

    void addTask(size_t id, int priority, QString const& description, bool checked);
    void deleteTask(size_t id);
    void clearTasks();
    void checkTask(size_t id, bool checked);

    ~MainWindow();

signals:
    void inputSignal(int piority, QString const& description);
    void removeSignal(size_t id);
    void checkSignal(size_t id, bool checked);
    void saveSignal(QString const& path);
    void openSignal(QString const& path);

private slots:
    void inputSlot(int priority, QString const& description);
    void removeSlot(size_t id);
    void checkSlot(size_t id, bool checked);
    void saveSlot();
    void openSlot();

private:
    void setupInterface();
    void setupConnections();
    void setupMenu();
    void setupConnection(TaskWidget * widget);

    QVBoxLayout * taskLayout;
    TaskInputWidget * taskInputWidget;
    std::vector<TaskWidget *> taskWidgets;
};

#endif // MAINWINDOW_H
