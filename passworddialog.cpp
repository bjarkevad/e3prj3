#include "passworddialog.h"
#include "ui_passworddialog.h"

/** Constructor
  *
  * Indstiller brugerfladen, og sætter password til _password.
  *@param parent Sætter dialogens parent, det gøres for at associere den med den klasse den bliver kaldt fra.
  *@param _password Det korrekte password, som er indstillet i MainWindow.
  */
PasswordDialog::PasswordDialog(QWidget *parent, QString _password) :
    QDialog(parent), ui(new Ui::PasswordDialog)
{
	//gem det korrekte password fra MainWindow
    password = _password;
	//indstil brugerfladen
    ui->setupUi(this);
}

/** Event der kaldes når der trykkes på Godkend.
  *
  * Der bliver tjekket om det indtastede password er korrekt. Hvis dette er tilfældet sendes signalet godkendt(true), ellers sendes godkendt(false).
  */
void PasswordDialog::on_godkendButton_clicked()
{
	//Hvis det indtastede kodeord er korrekt, bliver godkendt(true) sendt...
    if(ui->passwordLine->text() == password)
        emit godkendt(true);
	//Ellers sendes godkendt(false)
    else
        emit godkendt(false);
}

