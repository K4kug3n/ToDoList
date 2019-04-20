#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>

class TaskWidget : public QWidget
{
    Q_OBJECT

public:
    TaskWidget(QString priority, QString description, QWidget *parent = nullptr);

    void paintEvent(QPaintEvent * ) override;

signals:
    void deleted();
    void edited(int priority, QString description);

private slots:
    void editSlot();
    void deleteSlot();

private:

    void setupInterface();
    void setupButtons();

    QLabel * priority;
    QLabel * description;
    QPushButton * editButton;
    QPushButton * deleteButton;
};

#endif // TASKWIDGET_H
