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

signals:
    void deleted();
    void edited(int priority, QString description);

private slots:
    void editSlot();
    void deleteSlot();

private:

    void setupInterface();
    void setupButtons();

    QLabel * priorityLabel;
    QLabel * descriptionLabel;
    QPushButton * editButton;
    QPushButton * deleteButton;
    QCheckBox * checkBox;
};

#endif // TASKWIDGET_H
