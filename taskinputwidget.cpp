#include "taskinputwidget.h"

#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>

TaskInputWidget::TaskInputWidget(QWidget *parent):
    QWidget{ parent },
    inputButton{ new QPushButton("+") }
{
    setupInterface();
    setupConnection();
}

void TaskInputWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p{ this };
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void TaskInputWidget::inputSlot(int priority, const QString &description)
{
    emit inputSignal(priority, description);
}

void TaskInputWidget::setupInterface()
{   
    QHBoxLayout * layout{ new QHBoxLayout() };
    layout->addWidget(inputButton);
    setLayout(layout);

}

void TaskInputWidget::setupConnection()
{
    QObject::connect(inputButton, &QPushButton::clicked, &inputPanel, &TaskInputPanel::show);
    QObject::connect(&inputPanel, &TaskInputPanel::inputSignal, this, &TaskInputWidget::inputSlot);
}
