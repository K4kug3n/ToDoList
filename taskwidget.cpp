#include "taskwidget.h"

#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>

TaskWidget::TaskWidget(int priority, QString const& description, QWidget *parent)
    : QWidget{ parent },
      priorityLabel{ new QLabel(QString::number(priority)) },
      descriptionLabel{ new QLabel(description) },
      editButton{ new QPushButton("Edit") },
      deleteButton{ new QPushButton("Delete") },
      checkBox{ new QCheckBox() }
{
    setupInterface();
    setupButtons();
}

void TaskWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p{ this };
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void TaskWidget::editSlot()
{
    emit edited(2, "Things");
}

void TaskWidget::deleteSlot()
{
    emit deleted();
}

void TaskWidget::setupInterface()
{
    setStyleSheet("QLabel { color: white }"
                  "TaskWidget{ border-bottom: 1px solid white }"
                  "TaskWidget::hover{ background-color: grey; }");

    editButton->resize(50, 50);
    deleteButton->resize(50, 50);

    QHBoxLayout * optionLayout{ new QHBoxLayout() };
    optionLayout->addWidget(checkBox);
    optionLayout->addWidget(editButton);
    optionLayout->addWidget(deleteButton);

    QHBoxLayout * centralLayout{ new QHBoxLayout() };
    centralLayout->addWidget(priorityLabel);
    centralLayout->addWidget(descriptionLabel);
    centralLayout->addLayout(optionLayout);
    this->setLayout(centralLayout);
}

void TaskWidget::setupButtons()
{
    QObject::connect(editButton, &QPushButton::clicked, this, &TaskWidget::editSlot);
    QObject::connect(deleteButton, &QPushButton::clicked, this, &TaskWidget::deleteSlot);
}
