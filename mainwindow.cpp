#include "mainwindow.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QSpacerItem>

#include <QPalette>
#include <QColor>
#include <QRgb>

//#include <iostream>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{ parent },
      taskLayout{ new QVBoxLayout() },
      taskInputWidget{new TaskInputWidget() }
{
    setupInterface();
    setupConnection();
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

void MainWindow::setupConnection()
{
    QObject::connect(taskInputWidget, &TaskInputWidget::inputSignal, this, &MainWindow::inputSlot);
}

void MainWindow::setupConnection(TaskWidget * widget)
{
    QObject::connect(widget, &TaskWidget::deleteSignal, this, &MainWindow::removeSlot);
}

MainWindow::~MainWindow()
{
}

void MainWindow::inputSlot(int priority, const QString &description)
{
    //std::cout << "Input slot actived (window)" << std::endl;

    emit inputSignal(priority, description);
}

void MainWindow::removeSlot(int priority, const QString &description)
{
    //std::cout << "Remove slot actived (window)" << std::endl;

    emit removeSignal(priority, description);
}
