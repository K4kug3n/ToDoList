#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

#include "commun.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void addTask(Task const& task);

    ~MainWindow();

private:
    void setupInterface();

    QVBoxLayout * taskLayout;
};

#endif // MAINWINDOW_H
