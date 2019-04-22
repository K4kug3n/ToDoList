#include "taskinputpanel.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

#include <QStyleOption>
#include <QPainter>

TaskInputPanel::TaskInputPanel(QWidget *parent):
    QMainWindow{ parent },
    descriptionEdit{ new QLineEdit() },
    spinBox{ new QSpinBox() },
    validButton{ new QPushButton("Enter") }

{
    setupInterface();
}

void TaskInputPanel::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p{ this };
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void TaskInputPanel::inputSlot()
{
    emit inputValided(spinBox->value(), descriptionEdit->text());
}

void TaskInputPanel::setupInterface()
{
    setStyleSheet("QLabel{ color: white }"
                  "TaskInputPanel{ background-color: black }"
                  "QPushButton{ background-color: black; color: white }");

    QLabel * priorityLabel{ new QLabel("Priority : ") };
    spinBox->setRange(0, 99);
    QHBoxLayout * priorityLayout{ new QHBoxLayout() };
    priorityLayout->addWidget(priorityLabel);
    priorityLayout->addWidget(spinBox);

    QLabel * descriptionLabel{ new QLabel("Description : ") };

    QVBoxLayout * centralLayout{ new QVBoxLayout() };
    centralLayout->addLayout(priorityLayout);
    centralLayout->addWidget(descriptionLabel);
    centralLayout->addWidget(descriptionEdit);
    centralLayout->addWidget(validButton);

    QWidget * centralWidget{ new QWidget() };
    centralWidget->setLayout(centralLayout);
    setCentralWidget(centralWidget);
}

void TaskInputPanel::setupInput()
{
    QObject::connect(validButton, &QPushButton::clicked, this, &TaskInputPanel::inputSlot);
}
