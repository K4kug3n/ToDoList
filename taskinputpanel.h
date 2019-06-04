#ifndef TASKINPUTPANEL_H
#define TASKINPUTPANEL_H

#include <QMainWindow>
#include <QSpinBox>
#include <QLineEdit>
#include <QPushButton>

class TaskInputPanel : public QMainWindow
{
    Q_OBJECT
public:
    TaskInputPanel(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent * ) override;

signals:
    void inputSignal(int priority, QString const& description);


private slots:
    void inputSlot();

private:
    void setupInterface();
    void setupConnections();

    QLineEdit * descriptionEdit;
    QSpinBox * spinBox;
    QPushButton * validButton;
};

#endif // TASKINPUTPANEL_H
