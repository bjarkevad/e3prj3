#include "changepassworddialog.h"
#include "ui_changepassworddialog.h"

/** Constructor
  *
  * Indstiller brugerfladen, og opretter forbindelse mellem ok-knappen og validatePassword eventet.
  *@param parent Sætter dialogens parent, det gøres for at associere den med den klasse den bliver kaldt fra.
  *@param _oldPass Det password der skal ændres.
  */
ChangePasswordDialog::ChangePasswordDialog(QWidget *parent, QString _oldPass): QDialog(parent), ui(new Ui::ChangePasswordDialog)
{	
	//Indstiller brugerfladen
    ui->setupUi(this);
	
	//Når der trykkes ok, køres validatePassword()
    connect(ui->okButton, SIGNAL(clicked()),
            this, SLOT(validatePassword()));
	//Det gamle password gemmes i _oldPass
    oldPass = _oldPass;
}
/** Evaluerings funktion.
  *
  * Funktionen sender det indtastede nye password igennem newPassword signalet, hvis alle data er indtastet korrekt.\n
  * Ellers skrives "Fejl" på dialogen.
  */
void ChangePasswordDialog::validatePassword()
{
	//Hvis oldPass er indtastet korrekt, og det nye password er indtaste ens i begge linjer...
    if(ui->oldLine->text() == oldPass && ui->newLine1->text() == ui->newLine2->text() && ui->newLine1->text().length() < 9)
    {	
	//Det nye password sendes med newPassword(QString)
        emit newPassword(ui->newLine1->text());
	//Luk dialogen
        accept();
    }
	//...ellers skrives en fejl ud på dialogen
    else
        ui->errorLabel->setText("Fejl!");
}
