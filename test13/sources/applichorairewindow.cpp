#include "applichorairewindow.h"
#include "ui_applichorairewindow.h"
#include "unistd.h"
#include <QDesktopWidget>
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;
using namespace planning;

ApplicHoraireWindow::ApplicHoraireWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::ApplicHoraireWindow)
{
    ui->setupUi(this);
    ::close(2);

    // Configuration de la table des professeurs
    ui->tableWidgetProfesseurs->setColumnCount(3);
    ui->tableWidgetProfesseurs->setRowCount(0);
    QStringList labelsTableProfesseurs;
    labelsTableProfesseurs << "id"
                           << "Nom"
                           << "Prenom";
    ui->tableWidgetProfesseurs->setHorizontalHeaderLabels(labelsTableProfesseurs);
    ui->tableWidgetProfesseurs->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetProfesseurs->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetProfesseurs->horizontalHeader()->setVisible(true);
    ui->tableWidgetProfesseurs->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableWidgetProfesseurs->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetProfesseurs->verticalHeader()->setVisible(false);
    ui->tableWidgetProfesseurs->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des groupes
    ui->tableWidgetGroupes->setColumnCount(2);
    ui->tableWidgetGroupes->setRowCount(0);
    QStringList labelsTableGroupes;
    labelsTableGroupes << "id"
                       << "Nom";
    ui->tableWidgetGroupes->setHorizontalHeaderLabels(labelsTableGroupes);
    ui->tableWidgetGroupes->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableWidgetGroupes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetGroupes->horizontalHeader()->setVisible(true);
    ui->tableWidgetGroupes->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableWidgetGroupes->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetGroupes->verticalHeader()->setVisible(false);
    ui->tableWidgetGroupes->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des locaux
    ui->tableWidgetLocaux->setColumnCount(2);
    ui->tableWidgetLocaux->setRowCount(0);
    QStringList labelsTableLocaux;
    labelsTableLocaux << "id"
                      << "Nom";
    ui->tableWidgetLocaux->setHorizontalHeaderLabels(labelsTableLocaux);
    ui->tableWidgetLocaux->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetLocaux->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetLocaux->horizontalHeader()->setVisible(true);
    ui->tableWidgetLocaux->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableWidgetLocaux->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetLocaux->verticalHeader()->setVisible(false);
    ui->tableWidgetLocaux->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des cours
    ui->tableWidgetCourss->setColumnCount(8);
    ui->tableWidgetCourss->setRowCount(0);
    QStringList labelsTableCourss;
    labelsTableCourss << "code"
                      << "Jour"
                      << "Heure"
                      << "Duree"
                      << "Local"
                      << "Intitule"
                      << "Professeur"
                      << "Groupes";
    ui->tableWidgetCourss->setHorizontalHeaderLabels(labelsTableCourss);
    ui->tableWidgetCourss->setSelectionMode(QAbstractItemView::NoSelection);
    //ui->tableWidgetCourss->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetCourss->horizontalHeader()->setVisible(true);
    ui->tableWidgetCourss->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableWidgetCourss->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetCourss->verticalHeader()->setVisible(false);
    ui->tableWidgetCourss->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Pour faire joli
    ui->pushButtonAjouterProfesseur->setStyleSheet("background-color: lightgreen");
    ui->pushButtonAjouterGroupe->setStyleSheet("background-color: lightgreen");
    ui->pushButtonAjouterLocal->setStyleSheet("background-color: lightgreen");
    ui->pushButtonSupprimerProfesseur->setStyleSheet("background-color: orange");
    ui->pushButtonSupprimerGroupe->setStyleSheet("background-color: orange");
    ui->pushButtonSupprimerLocal->setStyleSheet("background-color: orange");
    ui->pushButtonPlanifier->setStyleSheet("background-color: lightblue");
    ui->pushButtonSelectionner->setStyleSheet("background-color: lightblue");

    // On fixe la taille et la position de la fenetre
    setFixedSize(1070, 647);
    move((QApplication::desktop()->width() - width()) / 2, (QApplication::desktop()->height() - height()) / 2);

    // Tests a supprimer ------------------------------------------------
    // addTupleTableProfessors("1;Wagner;Jean-Marc");
    // addTupleTableProfessors("4;Leonard;Anne");
    // addTupleTableProfessors("6;Quettier;Patrick");

    // addTupleTableGroups("4;INFO2_D201");
    // addTupleTableGroups("6;INFO2_I201");
    // addTupleTableGroups("7;INFO2_R201");
    // addTupleTableGroups("9;INFO2_D202");
    // addTupleTableGroups("10;INFO2_R202");

    // addTupleTableClassrooms("23;AN");
    // addTupleTableClassrooms("25;LP03");
    // addTupleTableClassrooms("29;LE0");

    // addTupleTableCourses("1;Lundi;8h30;2h00;AN;Théorie C++;Wagner Jean-Marc;INFO2 D201,INFO2 D202");
    // addTupleTableCourses("3;Mardi;10h30;1h30;AN;Théorie UNIX;Quettier Patrick;INFO2 R201,INFO2 R202");
    // addTupleTableCourses("4;Jeudi;13h30;2h00;LE0;Labo C++;Leonard Anne;INFO2 I201");
    // -------------------------------------------------------------------
}

ApplicHoraireWindow::~ApplicHoraireWindow()
{
    delete ui;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des professeurs /////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::addTupleTableProfessors(const string &tuple)
{
    // Parsing du tuple recu
    istringstream ss(tuple);
    string token;

    string id, lastName, firstName;
    getline(ss, id, ';');
    getline(ss, lastName, ';');
    getline(ss, firstName, ';');

    // Ajout dans la table
    int nbLignes = ui->tableWidgetProfesseurs->rowCount();
    nbLignes++;
    ui->tableWidgetProfesseurs->setRowCount(nbLignes);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(QString::fromStdString(id));
    ui->tableWidgetProfesseurs->setItem(nbLignes - 1, 0, item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setText(QString::fromStdString(lastName));
    ui->tableWidgetProfesseurs->setItem(nbLignes - 1, 1, item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setText(QString::fromStdString(firstName));
    ui->tableWidgetProfesseurs->setItem(nbLignes - 1, 2, item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::clearTableProfessors()
{
    ui->tableWidgetProfesseurs->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getIndexProfessorSelection() const
{
    QModelIndexList liste = ui->tableWidgetProfesseurs->selectionModel()->selectedRows();
    if (liste.size() == 0)
        return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des groupes /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::addTupleTableGroups(const string &tuple)
{
    // Parsing du tuple recu
    istringstream ss(tuple);
    string token;

    string id, name;
    getline(ss, id, ';');
    getline(ss, name, ';');

    // Ajout possible
    int nbLignes = ui->tableWidgetGroupes->rowCount();
    nbLignes++;
    ui->tableWidgetGroupes->setRowCount(nbLignes);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(QString::fromStdString(id));
    ui->tableWidgetGroupes->setItem(nbLignes - 1, 0, item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setText(QString::fromStdString(name));
    ui->tableWidgetGroupes->setItem(nbLignes - 1, 1, item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::clearTableGroups()
{
    ui->tableWidgetGroupes->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
list<int> ApplicHoraireWindow::getIndexesGroupsSelection() const
{
    QModelIndexList liste = ui->tableWidgetGroupes->selectionModel()->selectedRows();
    list<int> result;
    for (int i = 0; i < liste.size(); i++)
        result.push_back(liste.at(i).row());
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des locaux //////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::addTupleTableClassrooms(const string &tuple)
{
    // Parsing du tuple recu
    istringstream ss(tuple);
    string token;

    string id, name;
    getline(ss, id, ';');
    getline(ss, name, ';');

    // Ajout possible
    int nbLignes = ui->tableWidgetLocaux->rowCount();
    nbLignes++;
    ui->tableWidgetLocaux->setRowCount(nbLignes);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(QString::fromStdString(id));
    ui->tableWidgetLocaux->setItem(nbLignes - 1, 0, item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setText(QString::fromStdString(name));
    ui->tableWidgetLocaux->setItem(nbLignes - 1, 1, item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::clearTableClassrooms()
{
    ui->tableWidgetLocaux->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getIndexClassroomSelection() const
{
    QModelIndexList liste = ui->tableWidgetLocaux->selectionModel()->selectedRows();
    if (liste.size() == 0)
        return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des professeurs /////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::addTupleTableCourses(const string &tuple)
{
    // Parsing du tuple recu
    istringstream ss(tuple);
    string token;

    string code, day, hour, duration, classroom, title, professor, groups;
    getline(ss, code, ';');
    getline(ss, day, ';');
    getline(ss, hour, ';');
    getline(ss, duration, ';');
    getline(ss, classroom, ';');
    getline(ss, title, ';');
    getline(ss, professor, ';');
    getline(ss, groups, ';');

    // Ajout possible
    int nbLignes = ui->tableWidgetCourss->rowCount();
    nbLignes++;
    ui->tableWidgetCourss->setRowCount(nbLignes);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(QString::fromStdString(code));
    ui->tableWidgetCourss->setItem(nbLignes - 1, 0, item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setText(QString::fromStdString(day));
    ui->tableWidgetCourss->setItem(nbLignes - 1, 1, item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setText(QString::fromStdString(hour));
    ui->tableWidgetCourss->setItem(nbLignes - 1, 2, item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setText(QString::fromStdString(duration));
    ui->tableWidgetCourss->setItem(nbLignes - 1, 3, item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setText(QString::fromStdString(classroom));
    ui->tableWidgetCourss->setItem(nbLignes - 1, 4, item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setText(QString::fromStdString(title));
    ui->tableWidgetCourss->setItem(nbLignes - 1, 5, item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setText(QString::fromStdString(professor));
    ui->tableWidgetCourss->setItem(nbLignes - 1, 6, item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    item->setText(QString::fromStdString(groups));
    ui->tableWidgetCourss->setItem(nbLignes - 1, 7, item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::clearTableCourses()
{
    ui->tableWidgetCourss->setRowCount(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions permettant d'afficher des boites de dialogue /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::dialogMessage(const string &title, const string &message)
{
    QMessageBox::information(this, QString::fromStdString(title), QString::fromStdString(message));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::dialogError(const string &title, const string &message)
{
    QMessageBox::critical(this, QString::fromStdString(title), QString::fromStdString(message));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicHoraireWindow::dialogInputText(const string &title, const string &question)
{
    return QInputDialog::getText(this, QString::fromStdString(title), QString::fromStdString(question)).toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::dialogInputInt(const string &title, const string &question)
{
    return QInputDialog::getInt(this, QString::fromStdString(title), QString::fromStdString(question));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicHoraireWindow::dialogInputFileForLoad(const string &question)
{
    QString fileName = QFileDialog::getOpenFileName(this, QString::fromStdString(question), "", "Tous les fichiers (*.*)");
    return fileName.toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicHoraireWindow::dialogInputFileForSave(const string &question)
{
    QString fileName = QFileDialog::getSaveFileName(this, QString::fromStdString(question), "", "Tous les fichiers (*.*)");
    return fileName.toStdString();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles aux widgets de la fenetre /////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicHoraireWindow::getProfessorLastName() const
{
    return ui->lineEditNomProfesseur->text().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setProfessorLastName(const string &lastName)
{
    ui->lineEditNomProfesseur->setText(QString::fromStdString(lastName));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicHoraireWindow::getProfessorFirstName() const
{
    return ui->lineEditPrenomProfesseur->text().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setProfessorFirstName(const string &firstName)
{
    ui->lineEditPrenomProfesseur->setText(QString::fromStdString(firstName));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicHoraireWindow::getGroupName() const
{
    return ui->lineEditNumeroGroupe->text().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::clearGroupName()
{
    ui->lineEditNumeroGroupe->setText("");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicHoraireWindow::getClassroomName() const
{
    return ui->lineEditNomLocal->text().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setClassroomName(const string &name)
{
    ui->lineEditNomLocal->setText(QString::fromStdString(name));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicHoraireWindow::getDaySelection() const
{
    return ui->comboBoxJour->currentText().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getHourStart() const
{
    if (ui->lineEditHeuresDebut->text().toStdString() == "")
        return -1;
    return stoi(ui->lineEditHeuresDebut->text().toStdString());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::clearHourStart()
{
    ui->lineEditHeuresDebut->setText("");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getMinuteStart() const
{
    if (ui->lineEditMinutesDebut->text().toStdString() == "")
        return -1;
    return stoi(ui->lineEditMinutesDebut->text().toStdString());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::clearMinuteStart()
{
    ui->lineEditMinutesDebut->setText("");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getDuration() const
{
    if (ui->lineEditDuree->text().toStdString() == "")
        return -1;
    return stoi(ui->lineEditDuree->text().toStdString());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::clearDuration()
{
    ui->lineEditDuree->setText("");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
string ApplicHoraireWindow::getTitle() const
{
    return ui->lineEditIntitule->text().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setTitle(const string &title)
{
    ui->lineEditIntitule->setText(QString::fromStdString(title));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ApplicHoraireWindow::isDayChecked() const
{
    return ui->checkBoxJour->isChecked();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setDayChecked(bool b)
{
    ui->checkBoxJour->setChecked(b);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ApplicHoraireWindow::isProfessorChecked() const
{
    return ui->checkBoxProfesseur->isChecked();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setProfessorChecked(bool b)
{
    ui->checkBoxProfesseur->setChecked(b);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ApplicHoraireWindow::isGroupChecked() const
{
    return ui->checkBoxGroupe->isChecked();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setGroupChecked(bool b)
{
    ui->checkBoxGroupe->setChecked(b);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ApplicHoraireWindow::isClassroomChecked() const
{
    return ui->checkBoxLocal->isChecked();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setClassroomChecked(bool b)
{
    ui->checkBoxLocal->setChecked(b);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonAjouterProfesseur_clicked()
{
    cout << "Clic sur bouton Ajouter Professeur" << endl;

    string ProfLastName = getProfessorLastName();
    string ProfFirstName = getProfessorFirstName();

    auto &Timetable = Timetable::getInstance();

    if (ProfLastName.empty() || ProfFirstName.empty())
    {
        dialogError("Chaine Vide", "Vous ne pouvez pas entré de chaine vide \n");
        return;
    }

    if (Timetable.addProfessor(ProfLastName, ProfFirstName))
    {
        MiseAJourTableProfesseur(Timetable);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonAjouterGroupe_clicked()
{
    cout << "Clic sur bouton Ajouter Groupe" << endl;

    string GroupName = getGroupName();

    auto &Timetable = Timetable::getInstance();

    if (GroupName.empty())
    {
        dialogError("Chaine Vide Group", "Vous ne pouvez pas entré de chaine vide \n");
        return;
    }

    if (Timetable.addGroup(GroupName))
    {
        MiseAJourTableGroup(Timetable);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonAjouterLocal_clicked()
{
    cout << "Clic sur bouton Ajouter Local" << endl;

    string ClassName = getClassroomName();
    int SeatingCapacity;

    if ((SeatingCapacity = dialogInputInt("Combien de place ?", "Entrez le nombre de place dans votre classe  ?")) == 0)
        return;

    auto &Timetable = Timetable::getInstance();

    if (ClassName.empty())
    {
        dialogError("Chaine Vide Local", "Vous ne pouvez pas entré de chaine vide \n");
        return;
    }

    if (Timetable.addClassroom(ClassName, SeatingCapacity))
    {

        MiseAJourTableClassroom(Timetable);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonSupprimerProfesseur_clicked()
{
    cout << "Clic sur bouton Supprimer Professeur" << endl;
    int index;

    if ((index = getIndexProfessorSelection()) == -1)
    {
        dialogError("Suppression impossible", "Aucun professeur n'est sélectionné, la suppression est impossible");
        return;
    }
    cout << "Index cliquer : " << index;

    auto &Timetable = Timetable::getInstance();

    Timetable.deleteProfessorByIndex(index);

    MiseAJourTableProfesseur(Timetable);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonSupprimerGroupe_clicked()
{
    cout << "Clic sur bouton Supprimer Groupe" << endl;
    list<int> index = getIndexesGroupsSelection();

    if (index.empty())
    {
        dialogError("Suppression impossible", "Aucun Groupe n'a été sélectionné, la suppression est impossible");
        return;
    }

    index.sort(greater<int>()); //On reverse.sort() comme ca lors de la suppression on supprimera le plus grand puis le plus petit comme ca les index ne changeront pas et permettent de supprimer le bon index (greater<int> (operateur de la ))
    auto it = index.begin();

    auto &Timetable = Timetable::getInstance();

    for (auto it = index.cbegin(); it != index.cend(); it++)
    {
        cout << "Index cliquer : " << *it << endl;
        Timetable.deleteGroupByIndex(*it);
    }

    MiseAJourTableGroup(Timetable);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonSupprimerLocal_clicked()
{
    cout << "Clic sur bouton Supprimer Local" << endl;
    int index;

    if ((index = getIndexClassroomSelection()) == -1)
    {
        dialogError("Suppression impossible", "Aucun Local n'est sélectionné, la suppression est impossible");
        return;
    }
    cout << "Index cliquer : " << index;

    auto &Timetable = Timetable::getInstance();
    Timetable.deleteClassroomByIndex(index);

    MiseAJourTableClassroom(Timetable);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonPlanifier_clicked()
{
    cout << "Clic sur bouton Planifier" << endl;

    auto &Timetable = Timetable::getInstance();

    Professor p = Timetable.findProfessorByIndex(getIndexProfessorSelection());
    Classroom c = Timetable.findClassroomByIndex(getIndexClassroomSelection());

    int idp = p.getId();
    int idc = c.getId();

    list<int> indexG = getIndexesGroupsSelection();
    set<int> groupsSet;

    // Conversion de list<int> en set<int> et récupération des groupes par leur index
    for (auto it = indexG.begin(); it != indexG.end(); it++)
    {
        Group p = Timetable.findGroupByIndex(*it);
        if (p.getId() != -1)
        {
            groupsSet.insert(p.getId()); // Ajout du groupe dans le set
        }
    }

    // Vérification de la validité des sélections
    if ((idp == -1) || (idc == -1) || groupsSet.empty())
    {
        dialogError("Il vous manque des éléments à sélectionner", "Sélectionnez bien un professeur, un groupe ou des groupes, et une classe");
        return;
    }

    string day = getDaySelection();
    int startH = getHourStart();
    int startM = getMinuteStart();
    int dur = getDuration();
    string title = getTitle();

    const char *titles = title.c_str();

    try
    {
        Timing t(day, Time(startH, startM), Time(dur));
        Course cls(Event::currentCode, titles, idp, idc, groupsSet); // Passer le set<int> de groupes

        Timetable.schedule(cls, t);

        MiseAJourTableCourse(Timetable);
        dialogMessage("Ajout avec succès", "Le cours a été ajouté avec succès");
    }
    catch (TimingException &timingExcep)
    {
        cout << "message d'erreur" << timingExcep.getMessage() << "\nCode: " << timingExcep.getCode() << endl;
        switch (timingExcep.getCode())
        {
        case 15:
            dialogError("Professeur pas disponible", "Le Professeur demandé n'est pas disponible a cette horaire");
            break;

        case 16:
            dialogError("Classroom pas disponible", "Le Classroom demandé n'est pas disponible a cette horaire");
            break;

        case 17:
            dialogError("Group pas disponible", "Le Group demandé n'est pas disponible a cette horaire");
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les items de menu //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionQuitter_triggered()
{
    cout << "Clic sur Menu Fichier --> Item Quitter" << endl;
    QApplication::quit();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionOuvrir_triggered()
{
    cout << "Clic sur Menu Fichier --> Item Ouvrir" << endl;
    string NomFichier = dialogInputText("Qu'elle fichier souhaitez vous ouvrir", "Entrez le fichier que vous souhaitez ouvrir");
    auto &Timetable = Timetable::getInstance();

    Timetable.vider();

    if (Timetable.load(NomFichier))
    {
        dialogMessage("Ouverture réussie", "Votre fichier a bien été Ouvert");
        MiseAJourTableClassroom(Timetable);
        MiseAJourTableGroup(Timetable);
        MiseAJourTableProfesseur(Timetable);
        MiseAJourTableCourse(Timetable);
        return;
        cout << "current code de ouvrir: " << Event::currentCode << endl;
    }
    dialogError("L'ouverture n'a pas marche", "L'ouverture de votre fichier n'a malencontreusement pas fonctionné");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionNouveau_triggered()
{
    cout << "Clic sur Menu Fichier --> Item Nouveau" << endl;
    auto &Timetable = Timetable::getInstance();
    Timetable.vider();

    MiseAJourTableClassroom(Timetable);
    MiseAJourTableGroup(Timetable);
    MiseAJourTableProfesseur(Timetable);
    MiseAJourTableCourse(Timetable);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionEnregistrer_triggered()
{
    cout << "Clic sur Menu Fichier --> Item Enregistrer" << endl;
    auto &Timetable = Timetable::getInstance();
    string NomFichier = dialogInputFileForSave("Entrez le nom du fichier que vous souhaitez sauvegarder");
    if (Timetable.save(NomFichier))
    {
        dialogMessage("Sauvegarde réussie", "Votre fichier a bien été sauvegardé");
        return;
    }
    dialogError("NAAAAAAAAAAAAAAAAA", "Po marcher la sovegard.... T*T");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionSupprimerProfesseur_triggered()
{
    cout << "Clic sur Menu Supprimer --> Item Professeur" << endl;

    int id;

    if ((id = dialogInputInt("Suppression par ID d'un professeur", "Qu'elle est l'id du professeur que vous souhaiter supprimer ?")) == 0)
    {
        return;
    }
    auto &Timetable = Timetable::getInstance();

    if (Timetable.deleteProfessorById(id))
    {
        MiseAJourTableProfesseur(Timetable);
        return;
    }

    dialogError("Id pas trouver", "Impossible de trouver l'id demandé");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionSupprimerGroupe_triggered()
{
    cout << "Clic sur Menu Supprimer --> Item Groupe" << endl;

    int id;

    if ((id = dialogInputInt("Suppression par ID du groupe", "Qu'elle est l'id du Groupe que vous souhaiter supprimer ?")) == -1)
    {
        return;
    }
    auto &Timetable = Timetable::getInstance();

    if (Timetable.deleteGroupById(id))
    {
        MiseAJourTableGroup(Timetable);
        return;
    }

    dialogError("Id pas trouver", "Impossible de trouver l'id demandé");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionSupprimerLocal_triggered()
{
    cout << "Clic sur Menu Supprimer --> Item Local" << endl;

    int id;

    if ((id = dialogInputInt("Suppression par ID d'un local", "Qu'elle est l'id du Local que vous souhaiter supprimer ?")) == -1)
    {
        return;
    }
    auto &Timetable = Timetable::getInstance();

    if (Timetable.deleteClassroomById(id))
    {
        MiseAJourTableClassroom(Timetable);
        return;
    }
    dialogError("Id pas trouver", "Impossible de trouver l'id demandé");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionSupprimerCours_triggered()
{
    cout << "Clic sur Menu Supprimer --> Item Cours" << endl;

    int code = dialogInputInt("Suppression par code d'un course", "Qu'elle est le code du cours que vous souhaiter supprimer ?");
    auto &Timetable = Timetable::getInstance();

    if (Timetable.deleteCourseByCode(code))
    {
        MiseAJourTableCourse(Timetable);
        return;
    }
    dialogError("code pas trouver", "Impossible de trouver le codedemandé");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionImporterProfesseurs_triggered()
{
    cout << "Clic sur Menu Importer --> Item Professeurs" << endl;
    auto &Timetable = Timetable::getInstance();

    Timetable.importProfessorsFromCsv("../professors.csv");
    MiseAJourTableProfesseur(Timetable);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionImporterGroupes_triggered()
{
    cout << "Clic sur Menu Importer --> Item Groupes" << endl;
    auto &Timetable = Timetable::getInstance();

    Timetable.importGroupsFromCsv("../groups.csv");
    MiseAJourTableGroup(Timetable);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionImporterLocaux_triggered()
{
    cout << "Clic sur Menu Importer --> Item Locaux" << endl;
    auto &Timetable = Timetable::getInstance();

    Timetable.importClassroomsFromCsv("../classrooms.csv");
    MiseAJourTableClassroom(Timetable);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionExporterProfesseur_triggered()
{
    cout << "Clic sur Menu Exporter horaire --> Item Professeur" << endl;
    auto &Timetable = Timetable::getInstance();
    int id = dialogInputInt("Entre l'id ", "Entrez l'id du professeur auquels vous souhaitez imprimer l'horaire");

    Timetable.exportProfessorTimetable(id);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionExporterGroupe_triggered()
{
    cout << "Clic sur Menu Exporter horaire --> Item Groupe" << endl;
    auto &Timetable = Timetable::getInstance();
    int id = dialogInputInt("Entre l'id ", "Entrez l'id du groupe auquels vous souhaitez imprimer l'horaire");

    Timetable.exportGroupTimetable(id);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionExporterLocal_triggered()
{
    cout << "Clic sur Menu Exporter horaire --> Item Local" << endl;
    auto &Timetable = Timetable::getInstance();
    int id = dialogInputInt("Entre l'id ", "Entrez l'id du Local auquels vous souhaitez imprimer l'horaire");

    Timetable.exportClassroomTimetable(id);
}

void ApplicHoraireWindow::MiseAJourTableProfesseur(Timetable &x)
{
    int i = 0;
    clearTableProfessors(); // Vide la table des professeurs

    do
    {
        string tuple = x.getProfessorTupleByIndex(i); // Récupère un tuple
        i++;
        if (tuple.empty()) // Arrête si aucun tuple n'est retourné
            break;
        addTupleTableProfessors(tuple); // Ajoute le tuple à la table
    } while (true);
}

void ApplicHoraireWindow::MiseAJourTableGroup(Timetable &x)
{
    int i = 0;
    clearTableGroups(); // Vide la table des groupes

    do
    {
        string tuple = x.getGroupTupleByIndex(i); // Récupère un tuple
        i++;
        if (tuple.empty()) // Arrête si aucun tuple n'est retourné
            break;
        addTupleTableGroups(tuple); // Ajoute le tuple à la table
    } while (true);
}

void ApplicHoraireWindow::MiseAJourTableClassroom(Timetable &x)
{
    int i = 0;
    clearTableClassrooms(); // Vide la table des salles

    do
    {
        string tuple = x.getClassroomTupleByIndex(i); // Récupère un tuple
        i++;
        if (tuple.empty()) // Arrête si aucun tuple n'est retourné
            break;
        addTupleTableClassrooms(tuple); // Ajoute le tuple à la table
    } while (true);
}

void ApplicHoraireWindow::MiseAJourTableCourse(Timetable &t)
{
    int i = 0;
    Course cls();
    string tupleG;

    clearTableCourses();
    do
    {
        tupleG = t.getCourseTupleByIndex(i);
        i++;
        if (tupleG.empty())
            break;
        //cout << tupleG << endl;
        addTupleTableCourses(tupleG);

    } while (true);
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonSelectionner_clicked()
{
    cout << "Clic sur bouton Selectionner" << endl;
    string TupleG;
     int Group1;
    auto &Timetable = Timetable::getInstance();
    string daySelect = getDaySelection();
    list<int> groupSelect = getIndexesGroupsSelection();
    int profSelect = getIndexProfessorSelection();
    int classSelect = getIndexClassroomSelection();

    if(!groupSelect.empty())
    {
        auto it = groupSelect.begin();
        Group1 = *it;
    }
    else
    {   
         Group1 = -1;
    }

        list<Course> NvxCourse = Timetable.selectionner(isDayChecked(),daySelect,isGroupChecked(),Group1,isProfessorChecked(),profSelect,isClassroomChecked(),classSelect);



    clearTableCourses();
    for(auto it = NvxCourse.begin(); it != NvxCourse.end(); it++)
        {
            TupleG = Timetable.tuple(*it);
            //cout << TupleG << endl;
            addTupleTableCourses(TupleG);
        }
    
}

    