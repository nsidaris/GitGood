#include "login.h"
#include "ui_login.h"

/*!
   * \file login.cpp
   * \brief  Source file for login class
   *
   * This file contains all of the definitions of the login class
   */
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    isValid = false;
}

Login::~Login()
{
    delete ui;
}

void Login::on_buttonBox_accepted()
{
   if(ui->pwEdit->text().trimmed() == "cs1d")
   {
       isValid = true;
   }
   ui->pwEdit->clear();

    this->close();
}

void Login::on_buttonBox_rejected()
{
    isValid = false;
     ui->pwEdit->clear();
    this->close();
}
bool Login::getValid()
{
    if(isValid)
    {
        isValid = false;
        return true;
    }
    else
    {
        return false;
    }
}
