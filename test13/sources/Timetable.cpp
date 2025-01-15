#include "Timetable.h"
using namespace planning;
#include "applichorairewindow.h"
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
}

bool Timetable::isClassroomAvailable(int id, const Timing &timing)
{
	bool resultat;

	for (auto it = courses.begin(); it != courses.end(); it++)
	{
		if (it->getClassroomId() == id)
		{
			resultat = it->getTiming().intersect(timing);
			if (resultat == false)
				return false;
		}
	}
	return true;
}
void Timetable::schedule(Course &c, const Timing &t)
{

	int idProf = c.getProfessorId();
	int idClass = c.getClassroomId();
	set<int> idGroup = c.getGroupsId();

	for (auto it = idGroup.cbegin(); it != idGroup.cend(); it++)
	{
		if (!(isProfessorAvailable(idProf, t)))
			throw TimingException(TimingException::PROFESSOR_NOT_AVAIBLE, "Le professeur n'est pas disponible");

		if (!(isClassroomAvailable(idClass, t)))
			throw TimingException(TimingException::CLASSROOM_NOT_AVAIBLE, "Le classroom n'est pas disponible");

		if (!(isGroupAvailable((*it), t)))
			throw TimingException(TimingException::GROUP_NOT_AVAIBLE, "Le groups n'est pas disponible");

		cout << "Professor : " << isProfessorAvailable(idProf, t) << endl;
		cout << "Classroom : " << isClassroomAvailable(idClass, t) << endl;
		cout << "Group     : " << isGroupAvailable((*it), t) << endl;
	}

	c.setCode(Event::currentCode);
	c.setTiming(t);
	courses.push_back(c);

	Event::currentCode++;
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

	//!Enregistrer un fichier Classroom

	NomConcat = timetableName + "_classroom.xml";
	XmlFileSerializer<Classroom> *FC = new XmlFileSerializer<Classroom>(NomConcat, XmlFileSerializer<Classroom>::WRITE, "Classrooms");

	auto itc = classrooms.cbegin();
	i = 0;

	while (itc != classrooms.cend())
	{
		Classroom t = findClassroomByIndex(i);
		try
		{

			FC->write(t);
		}
		catch(const XmlFileSerializerException &e)
		{
			cout <<" erreur " << e.getCode() << " : " << e.getMessage() << endl;
		}

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
		try{
			FG->write(t);

		}
		catch(const XmlFileSerializerException &e)
		{
			cout <<" erreur " << e.getCode() << " : " << e.getMessage() << endl;
		}
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
		try
		{
			FP->write(t);
		}
		catch(const XmlFileSerializerException &e)
		{
			cout <<" erreur " << e.getCode() << " : " << e.getMessage() << endl;
		}
		itp++;
		i++;
	}
	delete FP;

	//!Enregistrer course
	NomConcat = timetableName + "_courses.xml";
	XmlFileSerializer<Course> *FCO = new XmlFileSerializer<Course>(NomConcat, XmlFileSerializer<Course>::WRITE, "Courses");

	auto itco = courses.begin();
	i = 0;

	while (itco != courses.end())
	{
		Course t = findCourseByIndex(i);
		try{
			FCO->write(t);

		}
		catch(const XmlFileSerializerException &e){
			cout <<" erreur " << e.getCode() << " : " << e.getMessage() << endl;
		}
		itco++;
		i++;
	}
	delete FCO;

	NomConcat = timetableName + "_config.dat";
	NomFichier = NomConcat.c_str();

	int fd;
	if ((fd = open(NomFichier, O_WRONLY | O_CREAT, 0777)) == -1)
	{
		cerr << "Une erreur lors de l'ouverture du fichier est survenue lors de l'ajout du fichier" << endl;
		return -1;
	}
	write(fd, &Schedulable::currentId, sizeof(Schedulable::currentId));

	write(fd, &Event::currentCode, sizeof(Event::currentCode));

	close(fd);
	return 1;
}

int Timetable::load(const string &timetableName)
{
	string NomConcat;
	int i;

	//! Professor

	NomConcat = timetableName + "_professor.xml";

	XmlFileSerializer<Professor> *FP = nullptr;
	try
	{
		FP = new XmlFileSerializer<Professor>(NomConcat, XmlFileSerializer<Professor>::READ);
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
				addProfessor(val);
			}
			catch (const XmlFileSerializerException &e)
			{
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
					end = true;
				else
				{
					cout << e.getMessage() << endl;
					break;
				}
			}
		}
		delete FP;
	}
	//! GRoup

	NomConcat = timetableName + "_group.xml";

	XmlFileSerializer<Group> *FG = nullptr;
	try
	{
		FG = new XmlFileSerializer<Group>(NomConcat, XmlFileSerializer<Group>::READ);
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
				addGroup(val);
			}
			catch (const XmlFileSerializerException &e)
			{
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
					end = true;
				else
				{
					cout << e.getMessage() << endl;
					break;
				}
			}
		}
		delete FG;
	}

	//!Classroom
	NomConcat = timetableName + "_classroom.xml";

	XmlFileSerializer<Classroom> *FC = nullptr;
	try
	{
		FC = new XmlFileSerializer<Classroom>(NomConcat, XmlFileSerializer<Classroom>::READ);
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
				addClassroom(val);
			}
			catch (const XmlFileSerializerException &e)
			{
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
					end = true;
				else
				{
					cout << e.getMessage() << endl;
					break;
				}
			}
		}
		delete FC;
	}

	//? Course
	NomConcat = timetableName + "_courses.xml";

	XmlFileSerializer<Course> *FCO = nullptr;
	try
	{
		FCO = new XmlFileSerializer<Course>(NomConcat, XmlFileSerializer<Course>::READ);
	}
	catch (const XmlFileSerializerException &e)
	{
		cout << "Erreur : " << e.getMessage() << " (code = " << e.getCode() << ")" << endl;
	}

	if (FCO != nullptr)
	{
		bool end = false;
		while (!end)
		{
			try
			{

				Course val = FCO->read();

				courses.push_back(val);
			}
			catch (const XmlFileSerializerException &e)
			{
				if (e.getCode() == XmlFileSerializerException::END_OF_FILE)
					end = true;
				else
				{
					cout << e.getMessage() << endl;
					break;
				}
			}
		}

		delete FCO;
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

	if (read(fd, &Event::currentCode, sizeof(Event::currentCode)) < 1)
	{
		cerr << "Erreur: données lues incorrectes" << endl;
		close(fd);
		return -1;
	}

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

	for (auto itco = courses.begin(); itco != courses.end();)
	{
		itco = courses.erase(itco); // Effacer l'élément et obtenir le nouvel itérateur
	}

	// Réinitialisation de currentId
	Schedulable::currentId = 1;

	return 1;
}

string Timetable::tuple(const Course &c)
{
	Timing t;
	t = c.getTiming();
	Classroom classroom = findClassroomById(c.getClassroomId());
	Professor professor = findProfessorById(c.getProfessorId());

	string tupleG = to_string(c.getCode()) + ";" +
					t.getDay() + ";" +
					t.getStart().toString() + ";" +
					t.getDuration().toString() + ";" +
					classroom.getName() + ";" +
					c.getTitle() + ";" +
					professor.getLastName() + " " + professor.getFirstName() + ";";

	// Concaténer les groupes avec des virgules
	set<int> grp = c.getGroupsId();

	string groupsStr;
	for (auto it = grp.cbegin(); it != grp.cend(); it++)
	{
		Group group = findGroupById(*it);
		groupsStr += group.toString();
		if (next(it) != grp.cend())
		{ // Ajoute une virgule si ce n'est pas le dernier élément
			groupsStr += ", ";
		}
	}
	// Ajouter les groupes à la chaîne finale
	tupleG += groupsStr;

	// Affichage du résultat final
	return tupleG;
}

Course Timetable::findCourseByIndex(int index)
{

	auto it = courses.begin();

	int i = 0;
	while (it != courses.end() && i < index)
	{
		it++;
		i++;
	}
	if (it != courses.end())
	{
		return *it;
	}
	else
	{
		return Course(); // Retourne un objet Classroom vide ou un autre objet par défaut
	}
}

string Timetable::getCourseTupleByIndex(int index)
{
	Course classes = findCourseByIndex(index); //! C LUI
	if (classes.getProfessorId() != 0)
	{

		string tupleC = tuple(classes);
		return tupleC;
	}
	return "";
}

Course Timetable::findCourseByCode(int code) const
{
	auto it = courses.begin();

	while (it != courses.end() && it->getCode() != code)
	{
		it++;
	}
	if (it != courses.end())
		return *it;

	cout << "Cours pas trouvé" << endl;
	return Course();
}

int Timetable::deleteCourseByCode(int Code)
{

	Course deleted = findCourseByCode(Code);

	auto it = find(courses.begin(), courses.end(), deleted);

	if (it != courses.end())
	{
		courses.erase(it);
		return 1;
	}
	return 0;
}

int Timetable::addClassroom(const Classroom &c)
{
	classrooms.insert(c);
	return 1;
}
int Timetable::addProfessor(const Professor &c)
{
	professors.insert(c);
	return 1;
}
int Timetable::addGroup(const Group &c)
{
	groups.insert(c);
	return 1;
}

void Timetable::importProfessorsFromCsv(const string &filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Une erreur lors de l'ouverture du fichier est survenue" << endl;
		exit(1);
	}

	string line;
	string LastName;
	string FirstName;

	while (getline(file, line))
	{
		cout << "la ligne lue" << line << endl;
		istringstream iss(line);

		getline(iss, LastName, ';');
		getline(iss, FirstName, ';');

		cout << "nom :  " << LastName << "  | prenom :  " << FirstName << endl;
		addProfessor(LastName, FirstName);
	}
}

void Timetable::importGroupsFromCsv(const string &filename)
{

	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Une erreur lors de l'ouverture du fichier est survenue" << endl;
		exit(1);
	}

	string line;
	string Name;

	while (getline(file, line))
	{
		cout << "la ligne lue" << line << endl;
		istringstream iss(line);

		getline(iss, Name, ';');

		cout << "name :  " << Name << endl;
		addGroup(Name);
	}
}
void Timetable::importClassroomsFromCsv(const string &filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Une erreur lors de l'ouverture du fichier est survenue" << endl;
		exit(1);
	}

	string line;
	string Name;
	string SeatingCapacity;

	while (getline(file, line))
	{
		//cout << "la ligne lue" << line << endl;
		istringstream iss(line);

		getline(iss, Name, ';');
		getline(iss, SeatingCapacity, ';');

		//cout << "nom :  " << Name << "  | place :  " << stoi(SeatingCapacity) << endl;
		addClassroom(Name, stoi(SeatingCapacity));
	}
}

void Timetable::exportProfessorTimetable(int id)
{
	Professor t = findProfessorById(id);
	const string NomFichier = t.getLastName() + "_" + t.getFirstName() + ".hor";
	cout << "votre nom fichier " << NomFichier << endl;

	fstream file;

	file.open(NomFichier, ios::out);
	file << "Horaire de " + t.getLastName() + " " + t.getFirstName() + " :";
	file << endl
		 << endl;

	for (auto it = courses.begin(); it != courses.end(); it++)
	{
		string groupsStr, ligne;
		if (it->getProfessorId() == id)
		{
			int clsint = it->getClassroomId();
			Classroom cls = findClassroomById(clsint);

			ligne = it->getTiming().getDay() + "     " + it->getTiming().getStart().toString() + "  " + it->getTiming().getDuration().toString() + "  " + cls.getName() + "   " + it->getTitle() + "  ";

			set<int> tmp = it->getGroupsId();
			for (auto itg = tmp.cbegin(); itg != tmp.cend(); itg++)
			{
				Group group = findGroupById(*itg);
				groupsStr += group.toString();
				if (next(itg) != tmp.cend())
				{ // Ajoute une virgule si ce n'est pas le dernier élément
					groupsStr += ", ";
				}
			}

			file << ligne + groupsStr << endl;
		}
	}
}
void Timetable::exportGroupTimetable(int id)
{
	Group g = findGroupById(id);
	const string NomFichier = g.getName() + ".hor";
	cout << "votre nom fichier " << NomFichier << endl;

	fstream file;

	file.open(NomFichier, ios::out);
	file << "Horaire de " + g.getName() + " :";
	file << endl
		 << endl;

	for (auto it = courses.begin(); it != courses.end(); it++)
	{

		set<int> tmp = it->getGroupsId();
		for (auto itg = tmp.cbegin(); itg != tmp.cend(); itg++)
		{
			if (*itg == id)
			{
				Professor prof = findProfessorById(it->getProfessorId());
				Classroom cls = findClassroomById(it->getClassroomId());
				file << it->getTiming().getDay() + "     " + it->getTiming().getStart().toString() + "  " + it->getTiming().getDuration().toString() + "  " + cls.getName() + "   " + it->getTitle() + "  " + prof.getLastName() + " " + prof.getFirstName() << endl;
			}
		}
	}
}

void Timetable::exportClassroomTimetable(int id)
{

	Classroom cls = findClassroomById(id);
	const string NomFichier = cls.getName() + ".hor";
	cout << "votre nom fichier " << NomFichier << endl;

	fstream file;

	file.open(NomFichier, ios::out);
	file << "Horaire de " + cls.getName() + " :";
	file << endl
		 << endl;

	for (auto it = courses.begin(); it != courses.end(); it++)
	{
		string groupsStr, ligne;
		if (it->getClassroomId() == id)
		{

			Professor prof = findProfessorById(it->getProfessorId());
			ligne = it->getTiming().getDay() + "     " + it->getTiming().getStart().toString() + "  " + it->getTiming().getDuration().toString() + "  " + cls.getName() + "   " + it->getTitle() + "  " + prof.getLastName() +" " + prof.getFirstName() + "  ";

			set<int> tmp = it->getGroupsId();
			for (auto itg = tmp.cbegin(); itg != tmp.cend(); itg++)
			{
				Group group = findGroupById(*itg);
				groupsStr += group.toString();
				if (next(itg) != tmp.cend())
				{ // Ajoute une virgule si ce n'est pas le dernier élément
					groupsStr += ", ";
				}
			}

			file << ligne + groupsStr << endl;
		}
	}
}

list<Course> Timetable::selectionner(bool dayCheck, string dayChecked, bool groupCheck, int groupChecked, bool profCheck, int profChecked, bool classCheck, int classChecked)
{

	cout << "On rentre bien dans sélectionner, voici mes bool sélectionner" << endl
		 << "Day = : " << dayChecked << " | bool  : " << dayCheck << endl
		 << "Professor = : " << profChecked << " | bool  : " << profCheck << endl
		 << "Classroom = : " << classChecked << " | bool  : " << classCheck << endl
		 << "Group = : " << groupChecked << " | bool  : " << groupCheck << endl;

	//Début du code réel

	list<Course> CourseCpy = courses;

	if (dayCheck)
	{
		auto it = CourseCpy.begin();
		while (it != CourseCpy.end())
		{
			if (dayChecked != it->getTiming().getDay())
			{
				it = CourseCpy.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	if (profCheck && profChecked != -1)
	{
		auto it = CourseCpy.begin();
		Professor pf = findProfessorByIndex(profChecked);

		while (it != CourseCpy.end())
		{
			Professor ptemp = findProfessorById(it->getProfessorId());
			//cout <<"Nom prof rechercher" << pf.getFirstName() << " " << pf.getLastName() << "idProfjuste : " << pf.getId() << " | " << "IdProftemp" << ptemp.getId() << endl;
			if (pf.getId() != ptemp.getId())
			{
				it = CourseCpy.erase(it);
				//cout << "On ne prend pas le professeur a l'id" << ptemp.getId() << endl;
			}
			else
			{
				++it;
				//cout << "On prend le professeur a l'id" << ptemp.getId() << endl;
			}
		}
	}

	if (classCheck && classChecked != -1)
	{
		auto it = CourseCpy.begin();
		Classroom cf = findClassroomByIndex(classChecked);

		while (it != CourseCpy.end())
		{
			Classroom ctemp = findClassroomById(it->getClassroomId());
			//cout <<"Nom classe rechercher" << cf.getName() << "idClassejuste : " << cf.getId() << " | " << "IdClasstemp : " << ctemp.getId() << endl;
			if (cf.getId() != ctemp.getId())
			{
				it = CourseCpy.erase(it);
				//cout << "On ne prend pas le local a l'id : " << ctemp.getId() << endl;
			}
			else
			{
				++it;
				//cout << "On prend le local a l'id : " << ctemp.getId() << endl;
			}
		}
	}

	int compteurGrpTotal;
	int compteurGrp;
	int i = 0;
	if (groupCheck && groupChecked != -1)
	{

		auto it = CourseCpy.begin();
		Group gf = findGroupByIndex(groupChecked);

		while (it != CourseCpy.end())
		{
			compteurGrpTotal = 0;
			compteurGrp = 0;

			set<int> setGtemp = it->getGroupsId();

			for (auto itSetgT = setGtemp.begin(); itSetgT != setGtemp.end(); itSetgT++)
			{
				compteurGrpTotal++;
			}

			for (auto itSetgT = setGtemp.begin(); itSetgT != setGtemp.end(); itSetgT++)
			{
				Group gtemp = findGroupById(*itSetgT);

				if (gf.getId() != gtemp.getId())
				{
					compteurGrp++;
				}
			}
			cout << i << ":" << compteurGrp << endl;
			cout << i << ":" << compteurGrpTotal << endl;
			i++;
			if (compteurGrp == compteurGrpTotal)
			{
				it = CourseCpy.erase(it);
			}
			else
				++it;
		}
	}

	return CourseCpy;
}