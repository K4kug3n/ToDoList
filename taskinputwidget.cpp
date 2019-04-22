#include "taskinputwidget.h"

#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>

TaskInputWidget::TaskInputWidget(QWidget *parent):
    QWidget{ parent },
    inputButton{ new QPushButton("+") }
{
    setupInterface();
    setupInput();
}

void TaskInputWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p{ this };
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void TaskInputWidget::setupInterface()
{   
    setStyleSheet("QPushButton{ background-color: black; color: white }"
                  "QPushButton::hover{ background-color: grey; color: black }");

    QHBoxLayout * layout{ new QHBoxLayout() };
    layout->addWidget(inputButton);
    setLayout(layout);
}

void TaskInputWidget::setupInput()
{
    QObject::connect(inputButton, &QPushButton::clicked, &inputPanel, &TaskInputPanel::show);
}
