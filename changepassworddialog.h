#ifndef CHANGEPASSWORDDIALOG_H
#define CHANGEPASSWORDDIALOG_H
#include <QDialog>

namespace Ui
{
class ChangePasswordDialog;
}

class ChangePasswordDialog: public QDialog
{
    Q_OBJECT
public:
    ChangePasswordDialog(QWidget *parent, QString _oldPass);
    /** Pointer til brugerflade
      *
      * Benyttes til at få adgang til iHomeChangePasswordDialog.ui, som er en "form".
      */
    Ui::ChangePasswordDialog *ui;
private slots:
    void validatePassword();
signals:
    /** Sendes når passwordet bliver ændret.
      *
      * @param _password Det nye password.
      */
    void newPassword(QString _password);
private:
    /** Bruges til at verificere at brugeren har indtastet det gamle password korrekt.
      *
      */
    QString oldPass;
};

#endif // CHANGEPASSWORDDIALOG_H
