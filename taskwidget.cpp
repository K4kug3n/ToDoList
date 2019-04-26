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
      editButton{ new QPushButton("Edit") },
      deleteButton{ new QPushButton("Delete") },
      checkBox{ new QCheckBox() }
{
    setupConnection();
    setupInterface();
}

void TaskWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p{ this };
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

//void TaskWidget::editSlot()
//{
//    emit editSignal(2, "Things");
//}

void TaskWidget::removeSlot()
{
    emit deleteSignal(priority, description);
}

void TaskWidget::checkSlot(int state)
{

    bool checked;
    if(state == 0)
    {
        checked = false;
    }
    else
    {
        checked = true;
    }

    updateState(checked);
}

void TaskWidget::setupInterface()
{
    updateState(false);

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

void TaskWidget::setupConnection()
{
    //QObject::connect(editButton, &QPushButton::clicked, this, &TaskWidget::editSlot);
    QObject::connect(deleteButton, &QPushButton::clicked, this, &TaskWidget::removeSlot);
    QObject::connect(checkBox, &QCheckBox::stateChanged, this, &TaskWidget::checkSlot);
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
