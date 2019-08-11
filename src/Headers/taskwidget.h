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
    TaskWidget(size_t id, int priority, QString const& description, QWidget *parent = nullptr);
    void updateState(bool checked);

    void paintEvent(QPaintEvent * ) override;

    const size_t id;

signals:
    void deleteSignal(size_t id);
    void checkSignal(size_t id, bool checked);

private slots:
    void removeSlot();
    void checkSlot(bool checked);

private:

    void setupInterface();
    void setupConnections();

    QLabel * priorityLabel;
    QLabel * descriptionLabel;
    QPushButton * deleteButton;
    QCheckBox * checkBox;
};

#endif // TASKWIDGET_H
