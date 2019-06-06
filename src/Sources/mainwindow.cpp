#include "mainwindow.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QScrollBar>

#include <QPalette>
#include <QColor>
#include <QRgb>

#include <QMenuBar>

#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{ parent },
      taskLayout{ new QVBoxLayout() },
      taskInputWidget{new TaskInputWidget() }
{
    setupInterface();
    setupConnections();
    setupMenu();
}

void MainWindow::addTask(int priority, QString const& description)
{
    TaskWidget * taskWidget{ new TaskWidget(priority, description) };
    taskWidget->setFixedHeight(60);
    taskWidget->setMaximumWidth(620);

    int index{ static_cast<int>(taskWidgets.size()) };
    taskLayout->insertWidget(index, taskWidget);

    setupConnection(taskWidget);

    taskWidgets.push_back(taskWidget);
}

void MainWindow::deleteTask(int priority, QString const& description)
{
    const auto tasks_it = std::find_if(taskWidgets.begin(), taskWidgets.end(),
                [priority, description](auto t) { return (priority == t->priority && description == t->description); });

    taskLayout->removeWidget(*tasks_it);
    (*tasks_it)->deleteLater();

    taskWidgets.erase(tasks_it);
}

void MainWindow::checkTask(int priority, const QString &description, bool checked)
{
    const auto tasks_it = std::find_if(taskWidgets.begin(), taskWidgets.end(),
                [priority, description](auto t) { return (priority == t->priority && description == t->description); });

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

void MainWindow::removeSlot(int priority, const QString &description)
{
    emit removeSignal(priority, description);
}

void MainWindow::checkSlot(int priority, const QString &description, bool checked)
{
    emit checkSignal(priority, description, checked);
}

void MainWindow::saveSlot()
{
    emit saveSignal();
}

void MainWindow::openSlot()
{
    emit openSignal();
}