#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class Settings;
}

class MainWindow;

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0, QString mConfigureUrl = "", QString mHostIP = "");
    ~Settings();

public:
    QString getConfigureUrl();
    QString getHostIP();
protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_Button_OK_clicked();

    void on_Button_Cancel_clicked();

private:
    Ui::Settings *ui;
    QString m_ConfigureUrl;
    QString m_hostIP;
};

#endif // SETTINGS_H
