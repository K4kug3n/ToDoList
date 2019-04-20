#include "mainwindow.h"
#include "taskwidget.h"

#include <QVBoxLayout>
#include <QSpacerItem>
#include <QScrollArea>
#include <QScrollBar>

#include <QPalette>
#include <QColor>
#include <QRgb>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{ parent }
{
    setupInterface();
}

void MainWindow::setupInterface()
{
    QWidget * centralWidget{ new QWidget()};
    centralWidget->setGeometry(geometry());

    QPalette pal{};
    pal.setColor(QPalette::Background, Qt::black);
    centralWidget->setAutoFillBackground(true);
    centralWidget->setPalette(pal);

    QVBoxLayout * layout{ new QVBoxLayout() };

    TaskWidget * task{ new TaskWidget("1", "Finish this") };
    task->setFixedHeight(60);
    task->setMaximumWidth(600);
    layout->addWidget(task);

    TaskWidget * task2{ new TaskWidget("2", "Finish other things") };
    task2->setFixedHeight(60);
    task2->setMaximumWidth(600);
    layout->addWidget(task2);

    TaskWidget * task3{ new TaskWidget("3", "Finish shitty things") };
    task3->setFixedHeight(60);
    task3->setMaximumWidth(600);
    layout->addWidget(task3);


    layout->addSpacerItem(new QSpacerItem{ 600, 460 });
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    centralWidget->setLayout(layout);

    QScrollArea * scrollArea{ new QScrollArea() };
    scrollArea->setWidget(centralWidget);
    scrollArea->horizontalScrollBar()->setEnabled(false);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setCentralWidget(scrollArea);
}

MainWindow::~MainWindow()
{
}
