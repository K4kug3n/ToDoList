#include "taskwidget.h"

#include <QHBoxLayout>
#include <QStyleOption>
#include <QPainter>

TaskWidget::TaskWidget(QString priority, QString description, QWidget *parent)
    : QWidget{ parent },
      priority{ new QLabel(priority) },
      description{ new QLabel(description) },
      editButton{ new QPushButton("Edit") },
      deleteButton{ new QPushButton("Delete") }
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

    QHBoxLayout * buttonLayout{ new QHBoxLayout() };
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(deleteButton);

    QHBoxLayout * centralLayout{ new QHBoxLayout() };
    centralLayout->addWidget(priority);
    centralLayout->addWidget(description);
    centralLayout->addLayout(buttonLayout);
    this->setLayout(centralLayout);
}

void TaskWidget::setupButtons()
{
    QObject::connect(editButton, &QPushButton::click, this, &TaskWidget::editSlot);
    QObject::connect(deleteButton, &QPushButton::click, this, &TaskWidget::deleteSlot);
}
