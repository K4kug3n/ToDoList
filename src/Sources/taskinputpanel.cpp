#include "taskinputpanel.h"
#include "ui_taskinputpanel.h"

TaskInputPanel::TaskInputPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskInputPanel)
{
    ui->setupUi(this);
}

TaskInputPanel::~TaskInputPanel()
{
    delete ui;
}

void TaskInputPanel::inputSlot()
{
    emit inputSignal(ui->prioritySpin->value(), ui->descriptionEdit->text());
    close();
}

void TaskInputPanel::cancelSlot()
{
    close();
}
