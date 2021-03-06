#include "taskwidget.h"

#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>

TaskWidget::TaskWidget(size_t id, int priority, QString const& description, QWidget *parent)
    : QWidget{ parent },
      id{ id },
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
    emit deleteSignal(id);
}

void TaskWidget::checkSlot(bool checked)
{
    emit checkSignal(id, checked);
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
        checkBox->setCheckState(Qt::CheckState::Checked);
    }
    else
    {
        setStyleSheet("QLabel { color: white }"
                      "TaskWidget{ border-bottom: 1px solid white; background-color: inherit }"
                      "TaskWidget::hover{ background-color: grey; }");
        checkBox->setCheckState(Qt::CheckState::Unchecked);
    }
}

