#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

/*!
 * \brief The Login class
 *
 * A separate window to get the admin login password
 */
class Login : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Login
     *
     * Constructor
     * \param parent
     */
    explicit Login(QWidget *parent = 0);
    /*!
      \brief Destructor
      */
    ~Login();

    /*!
     * \brief getValid
     *
     * Returns whether or not the password was correct
     * \return t/f password is correct
     */
    bool getValid();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Login *ui;
    bool isValid; //determines if the password is okay
};

#endif // LOGIN_H
