#ifndef TASKINPUTPANEL_H
#define TASKINPUTPANEL_H

#include <QDialog>

namespace Ui {
class TaskInputPanel;
}

class TaskInputPanel : public QDialog
{
    Q_OBJECT

public:
    explicit TaskInputPanel(QWidget *parent = nullptr);
    ~TaskInputPanel();

signals:
    void inputSignal(int priority, QString const& description);

private slots:
    void inputSlot();
    void cancelSlot();

private:
    Ui::TaskInputPanel *ui;
};

#endif // TASKINPUTPANEL_H
