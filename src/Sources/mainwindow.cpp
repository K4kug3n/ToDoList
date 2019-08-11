#include "mainwindow.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QScrollBar>

#include <QMenuBar>
#include <QFileDialog>

#include <algorithm>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{ parent },
      taskLayout{ new QVBoxLayout() },
      taskInputWidget{new TaskInputWidget() }
{
    setupInterface();
    setupConnections();
    setupMenu();
}

void MainWindow::addTask(size_t id, int priority, QString const& description, bool checked)
{
    TaskWidget * taskWidget{ new TaskWidget(id, priority, description) };
    taskWidget->setFixedHeight(60);
    taskWidget->setMaximumWidth(620);

    int index{ static_cast<int>(taskWidgets.size()) };
    taskLayout->insertWidget(index, taskWidget);

    taskWidget->updateState(checked);
    setupConnection(taskWidget);

    taskWidgets.push_back(taskWidget);
}

void MainWindow::deleteTask(size_t id)
{
    const auto tasks_it = std::find_if(taskWidgets.begin(), taskWidgets.end(),
                [id](TaskWidget * t) { return (t->id == id); });

    taskLayout->removeWidget(*tasks_it);
    (*tasks_it)->deleteLater();

    taskWidgets.erase(tasks_it);
}

void MainWindow::checkTask(size_t id, bool checked)
{
    const auto tasks_it = std::find_if(taskWidgets.begin(), taskWidgets.end(),
                [id](TaskWidget * t) { return (t->id == id); });

    (*tasks_it)->updateState(checked);
}

void MainWindow::setupInterface()
{
    QWidget * centralWidget{ new QWidget()};
    centralWidget->setGeometry(geometry());

    QPalette pal{};
    pal.setColor(QPalette::Background, Qt::black);
    centralWidget->setAutoFillBackground(true);
    centralWidget->setPalette(pal);

    taskInputWidget->setFixedHeight(60);
    taskInputWidget->setMaximumWidth(620);


    taskLayout->setAlignment(Qt::AlignTop);
    taskLayout->setContentsMargins(0, 0, 0, 0);
    taskLayout->setSpacing(0);
    taskLayout->addWidget(taskInputWidget);

    centralWidget->setLayout(taskLayout);

    QScrollArea * scrollArea{ new QScrollArea() };
    scrollArea->setWidget(centralWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->horizontalScrollBar()->setEnabled(false);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCentralWidget(scrollArea);
}

void MainWindow::setupConnections()
{
    QObject::connect(taskInputWidget, &TaskInputWidget::inputSignal, this, &MainWindow::inputSlot);
}

void MainWindow::setupMenu()
{
    QMenu * fileMenu{ menuBar()->addMenu("&File") };

    QAction * saveAction{ new QAction("&Save", this) };
    fileMenu->addAction(saveAction);
    QObject::connect(saveAction, &QAction::triggered, this, &MainWindow::saveSlot);
    QAction * openAction{ new QAction("&Open", this) };
    fileMenu->addAction(openAction);
    QObject::connect(openAction, &QAction::triggered, this, &MainWindow::openSlot);

    QAction * quitAction{ new QAction("&Quit", this) };
    fileMenu->addAction(quitAction);
    QObject::connect(quitAction, &QAction::triggered, this, &QMainWindow::close);

    QMenu * editMenu{ menuBar()->addMenu("&Edit") };
    QAction * addAction{ new QAction("&Add Task", this) };
    editMenu->addAction(addAction);
    QObject::connect(addAction, &QAction::triggered, taskInputWidget, &TaskInputWidget::showInputPanel);
}

void MainWindow::setupConnection(TaskWidget * widget)
{
    QObject::connect(widget, &TaskWidget::deleteSignal, this, &MainWindow::removeSlot);
    QObject::connect(widget, &TaskWidget::checkSignal, this, &MainWindow::checkSlot);
}

MainWindow::~MainWindow()
{
}

void MainWindow::inputSlot(int priority, const QString &description)
{
    emit inputSignal(priority, description);
}

void MainWindow::removeSlot(size_t id)
{
    emit removeSignal(id);
}

void MainWindow::checkSlot(size_t id, bool checked)
{
    emit checkSignal(id, checked);
}

void MainWindow::saveSlot()
{
    const QString filePath{ QFileDialog::getSaveFileName(this, tr("Save File"),
                                                         QDir::currentPath(),
                                                         tr("XML files (*.xml)")) };
    emit saveSignal(filePath);
}

void MainWindow::openSlot()
{
    const QString filePath{ QFileDialog::getOpenFileName(this, tr("Open File"),
                                         QDir::currentPath(),
                                         tr("XML files (*.xml)")) };

    emit openSignal(filePath);
}
