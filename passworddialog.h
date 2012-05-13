#ifndef PASSWORDDIALOG_H
#define PASSWORDDIALOG_H

#include <QDialog>

namespace Ui
{
    class PasswordDialog;
}

class PasswordDialog : public QDialog
{
    Q_OBJECT
public:
    PasswordDialog(QWidget *parent = 0, QString password = " ");
    /** Pointer til brugerflade
      *
      * Benyttes til at få adgang til iHomePasswordDialog.ui, som er en "form".
      */
    Ui::PasswordDialog *ui;

signals:
    /** Sendes når der trykkes "Godkend" på dialogen
      *
      *@param _ok True hvis passwordet er korrekt, false hvis ikke.
      */
    void godkendt(bool _ok);

public slots:
    void on_godkendButton_clicked();

private:
    /** String med det korrekte password
      *
      */
    QString password;

};

#endif // PASSWORDDIALOG_H
