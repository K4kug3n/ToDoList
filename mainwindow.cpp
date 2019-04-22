#include "mainwindow.h"
#include "taskwidget.h"
#include "taskinputwidget.h"

#include <QVBoxLayout>
#include <QSpacerItem>
#include <QScrollArea>
#include <QScrollBar>
#include <QSpacerItem>

#include <QPalette>
#include <QColor>
#include <QRgb>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{ parent },
      taskLayout{ new QVBoxLayout() }
{
    setupInterface();
}

void MainWindow::addTask(Task const& task)
{
    TaskWidget * taskWidget{ new TaskWidget(task.priority, task.description) };
    taskWidget->setFixedHeight(60);
    taskWidget->setMaximumWidth(600);

    int index{taskLayout->count() - 2};
    taskLayout->insertWidget(index, taskWidget);
}

void MainWindow::setupInterface()
{
    QWidget * centralWidget{ new QWidget()};
    centralWidget->setGeometry(geometry());

    QPalette pal{};
    pal.setColor(QPalette::Background, Qt::black);
    centralWidget->setAutoFillBackground(true);
    centralWidget->setPalette(pal);

    TaskInputWidget * inputWidget{new TaskInputWidget() };
    inputWidget->setFixedHeight(60);
    inputWidget->setMaximumWidth(600);
    taskLayout->addWidget(inputWidget);

    taskLayout->addSpacerItem( new QSpacerItem{600, 460} );
    taskLayout->setContentsMargins(0, 0, 0, 0);
    taskLayout->setSpacing(0);

    centralWidget->setLayout(taskLayout);

    QScrollArea * scrollArea{ new QScrollArea() };
    scrollArea->setWidget(centralWidget);
    scrollArea->horizontalScrollBar()->setEnabled(false);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCentralWidget(scrollArea);
}

MainWindow::~MainWindow()
{
}
