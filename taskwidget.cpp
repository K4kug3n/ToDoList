#include "taskwidget.h"

#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>

TaskWidget::TaskWidget(int priority, QString const& description, QWidget *parent)
    : QWidget{ parent },
      priority{ priority },
      description{ description },
      priorityLabel{ new QLabel(QString::number(priority)) },
      descriptionLabel{ new QLabel(description) },
      deleteButton{ new QPushButton("Delete") },
      checkBox{ new QCheckBox() }
{
    setupConnections();
    setupInterface();
}

void TaskWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p{ this };
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void TaskWidget::removeSlot()
{
    emit deleteSignal(priority, description);
}

void TaskWidget::checkSlot(bool checked)
{
    emit checkSignal(priority, description, checked);
}

void TaskWidget::setupInterface()
{
    updateState(false);

    QHBoxLayout * optionLayout{ new QHBoxLayout() };
    optionLayout->addWidget(checkBox);
    optionLayout->addWidget(deleteButton);

    QHBoxLayout * centralLayout{ new QHBoxLayout() };
    centralLayout->addWidget(priorityLabel);
    centralLayout->addWidget(descriptionLabel);
    centralLayout->addLayout(optionLayout);
    this->setLayout(centralLayout);
}

void TaskWidget::setupConnections()
{
    QObject::connect(deleteButton, &QPushButton::clicked, this, &TaskWidget::removeSlot);
    QObject::connect(checkBox, &QCheckBox::toggled, this, &TaskWidget::checkSlot);
}

void TaskWidget::updateState(bool checked)
{
    if(checked)
    {
        setStyleSheet("QLabel { color: white }"
                      "TaskWidget{ border-bottom: 1px solid white; background-color: green }");
    }
    else
    {
        setStyleSheet("QLabel { color: white }"
                      "TaskWidget{ border-bottom: 1px solid white; background-color: inherit }"
                      "TaskWidget::hover{ background-color: grey; }");
    }
}

