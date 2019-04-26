#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QCheckBox>

class TaskWidget : public QWidget
{
    Q_OBJECT

public:
    TaskWidget(int priority, QString const& description, QWidget *parent = nullptr);

    void paintEvent(QPaintEvent * ) override;

    const int priority;
    const QString description;

signals:
    void deleteSignal(int priority, QString const& description);
    void editSignal(int priority, QString description);

private slots:
    //void editSlot();
    void removeSlot();
    void checkSlot(int state);

private:

    void setupInterface();
    void setupConnection();
    void updateState(bool checked);

    QLabel * priorityLabel;
    QLabel * descriptionLabel;
    QPushButton * editButton;
    QPushButton * deleteButton;
    QCheckBox * checkBox;
};

#endif // TASKWIDGET_H
