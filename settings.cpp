#include "settings.h"
#include "ui_settings.h"
#include <QDebug>

Settings::Settings(QWidget *parent, QString mConfigureUrl, QString mHostIP ) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setFocus();
    QApplication::setOverrideCursor(Qt::ArrowCursor);

    if(mConfigureUrl.length() != 0)
        ui->TextEdit_Config->setPlainText(mConfigureUrl);

    if( mHostIP.length() != 0 )
        ui->txtHostAddress->setPlainText( mHostIP );

    m_ConfigureUrl = ui->TextEdit_Config->toPlainText();
}

Settings::~Settings()
{
    delete ui;
}

void Settings::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return){
        m_ConfigureUrl = ui->TextEdit_Config->toPlainText();
        m_hostIP = ui->txtHostAddress->toPlainText();
        this->close();
    }
}

QString Settings::getConfigureUrl()
{
    return m_ConfigureUrl;
}

QString Settings::getHostIP()
{
    return m_hostIP;
}

void Settings::on_Button_OK_clicked()
{
    m_ConfigureUrl = ui->TextEdit_Config->toPlainText();
    m_hostIP = ui->txtHostAddress->toPlainText();
    QDialog::accept();
}

void Settings::on_Button_Cancel_clicked()
{
    QApplication::setOverrideCursor(Qt::BlankCursor);
    this->close();
}
