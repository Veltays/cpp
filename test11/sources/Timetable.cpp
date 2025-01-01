#include "Timetable.h"
using namespace planning;

Timetable Timetable::instance;

Timetable::Timetable()
{
}
Timetable::~Timetable()
{
}

//? ------------Les classroom ----------------
int Timetable::addClassroom(const string &name, int seatingCapacity)
{
	auto result = classrooms.insert(Classroom(Schedulable::currentId, name, seatingCapacity));

	if (result.second) // result.second est true si l'insertion a réussi
	{
		cout << "La classe a été ajouté avec succès." << endl;
		Schedulable::currentId++;
		return 1;
	}
	else
	{
		cout << "Le groupe existe déjà." << endl;
		return 0;
	}
}
void Timetable::displayClassrooms() const
{
	int index = 0;
	for (set<Classroom>::const_iterator it = classrooms.cbegin(); it != classrooms.cend(); it++)
	{
		cout << "-->" << index << " | "
			 << "Id"
			 << "[" << it->getId() << "]"
			 << "  |  " << it->toString() << it->getId() << endl;
		index++;
	}
}

Classroom Timetable::findClassroomByIndex(int index) const
{
	auto it = classrooms.cbegin();
	int i = 0;

	while (it != classrooms.cend() && i < index)
	{
		it++;
		i++;
	}

	if (it != classrooms.cend())
		return *it;
	else
	{
		cout << "Index hors limites" << endl;
		return Classroom(); // Retourne un objet Classroom vide ou un autre objet par défaut
	}
}

Classroom Timetable::findClassroomById(int id) const
{
	auto it = classrooms.cbegin();

	while (it != classrooms.cend() && it->getId() != id)
	{
		it++;
	}

	if (it != classrooms.cend())
		return *it;

	cout << "Classroom pas trouvé" << endl;
	return Classroom();
}

void Timetable::deleteClassroomByIndex(int index)
{
	auto it = classrooms.cbegin();
	int i = 0;

	while (i < index)
	{
		it++;
		i++;
	}
	if (it != classrooms.end())
		classrooms.erase(it);
	else
		cout << "index inatteignable" << endl;
}
int Timetable::deleteClassroomById(int id)
{

	Classroom Deleted = findClassroomById(id);

	auto it = classrooms.find(Deleted);

	if (it != classrooms.cend())
	{
		classrooms.erase(it);
		return 1;
	}
	return 0;
}

//? ------------Les Professeurs ----------------
int Timetable::addProfessor(const string &lastName, const string &firstName)
{
	auto result = professors.insert(Professor(Schedulable::currentId, lastName, firstName));
	if (result.second) // result.second est true si l'insertion a réussi
	{
		cout << "Le groupe a été ajouté avec succès." << endl;
		Schedulable::currentId++;
		return 1;
	}
	else
	{
		cout << "Le groupe existe déjà." << endl;
		return 0;
	}
}
void Timetable::displayProfessors() const
{
	int index = 0;
	for (set<Professor>::const_iterator it = professors.cbegin(); it != professors.cend(); it++)
	{
		cout << "-->" << index << " | "
			 << "Id"
			 << "[" << it->getId() << "]"
			 << "  |  " << it->toString() << it->getId() << endl;
		index++;
	}
}
Professor Timetable::findProfessorByIndex(int index) const
{
	auto it = professors.cbegin();
	int i = 0;

	while (it != professors.cend() && i < index)
	{
		it++;
		i++;
	}

	if (it != professors.cend())
		return *it;
	else
	{
		cout << "Index hors limites" << endl;
		return Professor(); // Retourne un objet Professorr vide ou un autre objet par défaut
	}
}
Professor Timetable::findProfessorById(int id) const
{
	auto it = professors.cbegin();

	while (it != professors.cend() && it->getId() != id)
	{
		it++;
	}

	if (it != professors.cend())
		return *it;

	cout << "professors pas trouvé" << endl;
	return Professor();
}
void Timetable::deleteProfessorByIndex(int index)
{
	auto it = professors.cbegin();
	int i = 0;

	while (i < index)
	{
		it++;
		i++;
	}
	if (it != professors.end())
		professors.erase(it);
	else
		cout << "index inatteignable" << endl;
}

int Timetable::deleteProfessorById(int id)
{
	Professor Deleted = findProfessorById(id);

	auto it = professors.find(Deleted);

	if (it != professors.cend())
	{
		professors.erase(it);
		return 1;
	}
	return 0;
}

//? ------------Les groupes ----------------
int Timetable::addGroup(const string &name)
{
	auto result = groups.insert(Group(Schedulable::currentId, name));

	if (result.second) // result.second est true si l'insertion a réussi
	{
		cout << "Le groupe a été ajouté avec succès." << endl;
		Schedulable::currentId++;
		return 1;
	}
	else
	{
		cout << "Le groupe existe déjà." << endl;
		return 0;
	}
}
void Timetable::displayGroups() const
{
	int index = 0;
	for (set<Group>::const_iterator it = groups.cbegin(); it != groups.cend(); it++)
	{
		cout << "-->" << index << " | "
			 << "Id"
			 << "[" << it->getId() << "]"
			 << "  |  " << it->toString() << it->getId() << endl;
		index++;
	}
}
Group Timetable::findGroupByIndex(int index) const
{
	auto it = groups.cbegin();
	int i = 0;

	while (it != groups.cend() && i < index)
	{
		it++;
		i++;
	}

	if (it != groups.cend())
		return *it;
	else
	{
		cout << "Index hors limites" << endl;
		return Group(); // Retourne un objet Group vide ou un autre objet par défaut
	}
}
Group Timetable::findGroupById(int id) const
{
	auto it = groups.cbegin();

	while (it != groups.cend() && it->getId() != id)
	{
		it++;
	}

	if (it != groups.cend())
		return *it;

	return Group();
}
void Timetable::deleteGroupByIndex(int index)
{
	auto it = groups.cbegin();
	int i = 0;

	while (i < index)
	{
		it++;
		i++;
	}
	if (it != groups.end())
		groups.erase(it);
	else
		cout << "index inatteignable" << endl;
}
int Timetable::deleteGroupById(int id)
{
	Group Deleted = findGroupById(id);

	auto it = groups.find(Deleted);

	if (it != groups.cend())
	{
		groups.erase(it);
		return 1;
	}
	return 0;
}

//? Les course

bool Timetable::isProfessorAvailable(int id, const Timing &timing)
{
	bool resultat;

	for (auto it = courses.begin(); it != courses.end(); it++)
	{
		if (it->getProfessorId() == id)
		{
			resultat = it->getTiming().intersect(timing);
			if (resultat == false)
				return false;
		}
	}
	return true;
}

bool Timetable::isGroupAvailable(int id, const Timing &timing)
{
	bool resultat;

	for (auto it = courses.begin(); it != courses.end(); it++)
	{
		set<int> grp = it->getGroupsId();

		for (auto itgrp = grp.cbegin(); itgrp != grp.cend(); itgrp++)
		{
			if (*itgrp == id)
			{
				resultat = it->getTiming().intersect(timing);
				if (resultat == false)
					return false;
			}
		}
	}
	return true;
	cout << "reflechis..";
}

bool Timetable::isClassroomAvailable(int id, const Timing &timing)
{
	bool resultat;
	
	for (auto it = courses.begin(); it != courses.end(); it++)
	{
		if (it->getClassroomId() == id)
		{
			if (!it->getTiming().intersect(timing));
				return true;
		}
	}
	return false;
}
void Timetable::schedule(Course &c, const Timing &t)
{

		int idProf = c.getProfessorId();
		int idClass =c.getClassroomId();
		set<int> idGroup =c.getGroupsId();

		for(auto it = idGroup.cbegin(); it != idGroup.cend(); it++)
		if(!(isProfessorAvailable(idProf,t)) && !(isClassroomAvailable(idClass,t)) && !(isGroupAvailable((*it),t)))
		{
			cout << "pas dispo" << endl;
			throw  TimingException(TimingException::TIMING_NOT_AVAIBLE , "PAS DISPONIBLE CHERCHE TOI UNE VIE");
		}

		c.setTiming(t);
	
}

Timetable &Timetable::getInstance()
{
	return instance;
}

//Fonction get

string Timetable::getProfessorTupleByIndex(int index)
{
	Professor t = findProfessorByIndex(index);
	auto it = professors.cbegin();
	std::advance(it, index); // pour avancer l'it jusqua un index précis

	if (it != professors.cend())
	{
		return t.tuple();
	}
	return "";
}

string Timetable::getGroupTupleByIndex(int index)
{
	Group t = findGroupByIndex(index);
	auto it = groups.cbegin();
	std::advance(it, index); // pour avancer l'it jusqua un index précis

	if (it != groups.cend())
	{
		return t.tuple();
	}
	return "";
}

string Timetable::getClassroomTupleByIndex(int index)
{

	Classroom t = findClassroomByIndex(index);
	auto it = classrooms.cbegin();
	std::advance(it, index); // pour avancer l'it jusqua un index précis

	if (it != classrooms.cend())
	{
		return t.tuple();
	}
	return "";
}

// les load
int Timetable::save(const string &timetableName)
{
	int i;
	string NomConcat;
	const char *NomFichier;

	NomConcat = timetableName + "_config.dat";
	NomFichier = NomConcat.c_str();

	int fd;
	if ((fd = open(NomFichier, O_WRONLY | O_CREAT | O_APPEND, 0777)) == -1)
	{
		cerr << "Une erreur lors de l'ouverture du fichier est survenue lors de l'ajout du fichier" << endl;
		return -1;
	}
	write(fd, &Schedulable::currentId, sizeof(Schedulable::currentId));
	close(fd);
	//!Enregistrer un fichier Classroom

	NomConcat = timetableName + "_classroom.xml";
	XmlFileSerializer<Classroom> *FC = new XmlFileSerializer<Classroom>(NomConcat, XmlFileSerializer<Classroom>::WRITE, "Classrooms");

	auto itc = classrooms.cbegin();
	i = 0;

	while (itc != classrooms.cend())
	{
		Classroom t = findClassroomByIndex(i);
		FC->write(t);
		itc++;
		i++;
	}
	delete FC;

	//!Enregistrer un fichier groupe
	NomConcat = timetableName + "_group.xml";
	XmlFileSerializer<Group> *FG = new XmlFileSerializer<Group>(NomConcat, XmlFileSerializer<Group>::WRITE, "Groups");

	auto itg = groups.cbegin();
	i = 0;

	while (itg != groups.cend())
	{
		Group t = findGroupByIndex(i);
		FG->write(t);
		itg++;
		i++;
	}
	delete FG;

	//!Enregistrer un fichier profresseur
	NomConcat = timetableName + "_professor.xml";
	XmlFileSerializer<Professor> *FP = new XmlFileSerializer<Professor>(NomConcat, XmlFileSerializer<Professor>::WRITE, "Professors");

	auto itp = professors.cbegin();
	i = 0;

	while (itp != professors.cend())
	{
		Professor t = findProfessorByIndex(i);
		FP->write(t);
		itp++;
		i++;
	}
	delete FP;

	return 1;
}

int Timetable::load(const string &timetableName)
{
	string NomConcat;
	int i;

	NomConcat = timetableName + "_classroom.xml";

	XmlFileSerializer<Classroom> *FC = nullptr;
	try
	{
		FC = new XmlFileSerializer<Classroom>(NomConcat, XmlFileSerializer<Classroom>::READ);
		cout << "Filename = " << FC->getFilename() << endl;
		cout << "Collection name = " << FC->getCollectionName() << endl;
		cout << "Readable = " << FC->isReadable() << endl;
		cout << "Writable = " << FC->isWritable() << endl
			 << endl;
	}
	catch (const XmlFileSerializerException &e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	if (FC != nullptr)
	{
		bool end = false;
		while (!end)
		{
			try
			{
				Classroom val = FC->read();
				addClassroom(val.getName(), val.getSeatingCapacity());
			}
			catch (const XmlFileSerializerException &e)
			{
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
					end = true;
				else
				{
					cout << "Erreur de lecture XML : " << e.getMessage() << endl;
					break;
				}
			}
		}
		delete FC;
	}

	//! GRoup

	NomConcat = timetableName + "_group.xml";

	XmlFileSerializer<Group> *FG = nullptr;
	try
	{
		FG = new XmlFileSerializer<Group>(NomConcat, XmlFileSerializer<Group>::READ);
		cout << "Filename = " << FG->getFilename() << endl;
		cout << "Collection name = " << FG->getCollectionName() << endl;
		cout << "Readable = " << FG->isReadable() << endl;
		cout << "Writable = " << FG->isWritable() << endl
			 << endl;
	}
	catch (const XmlFileSerializerException &e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	if (FG != nullptr)
	{
		bool end = false;
		while (!end)
		{
			try
			{
				Group val = FG->read();
				addGroup(val.getName());
			}
			catch (const XmlFileSerializerException &e)
			{
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
					end = true;
				else
				{
					cout << "Erreur de lecture XML : " << e.getMessage() << endl;
					break;
				}
			}
		}
		delete FG;
	}

	//! Professor

	NomConcat = timetableName + "_professor.xml";

	XmlFileSerializer<Professor> *FP = nullptr;
	try
	{
		FP = new XmlFileSerializer<Professor>(NomConcat, XmlFileSerializer<Professor>::READ);
		cout << "Filename = " << FP->getFilename() << endl;
		cout << "Collection name = " << FP->getCollectionName() << endl;
		cout << "Readable = " << FP->isReadable() << endl;
		cout << "Writable = " << FP->isWritable() << endl
			 << endl;
	}
	catch (const XmlFileSerializerException &e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	if (FP != nullptr)
	{
		bool end = false;
		while (!end)
		{
			try
			{
				Professor val = FP->read();
				addProfessor(val.getLastName(), val.getFirstName());
			}
			catch (const XmlFileSerializerException &e)
			{
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
					end = true;
				else
				{
					cout << "Erreur de lecture XML : " << e.getMessage() << endl;
					break;
				}
			}
		}
		delete FP;
	}

	const char *NomFichier;
	int fd;

	NomConcat = timetableName + "_config.dat";
	NomFichier = NomConcat.c_str();

	if ((fd = open(NomFichier, O_RDONLY, 0777)) == -1)
	{
		cerr << "Une erreur lors de l'ouverture du fichier est survenue" << endl;
		return -1;
	}

	if (read(fd, &Schedulable::currentId, sizeof(Schedulable::currentId)) < 1)
	{
		cerr << "Erreur: données lues incorrectes" << endl;
		close(fd);
		return -1;
	}
	cout << "L'entier lu du fichier est: " << Schedulable::currentId << endl;
	close(fd);

	return 1;
}

int Timetable::vider()
{

	for (auto itc = classrooms.begin(); itc != classrooms.end();)
	{
		itc = classrooms.erase(itc); // Effacer l'élément et obtenir le nouvel itérateur
	}

	// Effacer les groupes
	for (auto itg = groups.begin(); itg != groups.end();)
	{
		itg = groups.erase(itg); // Effacer l'élément et obtenir le nouvel itérateur
	}

	// Effacer les professeurs
	for (auto itp = professors.begin(); itp != professors.end();)
	{
		itp = professors.erase(itp); // Effacer l'élément et obtenir le nouvel itérateur
	}

	// Réinitialisation de currentId
	Schedulable::currentId = 1;

	return 1;
}