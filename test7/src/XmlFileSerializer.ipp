#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

#include "XmlFileSerializerException.h"
using namespace std;

template <typename T>
const char XmlFileSerializer<T>::READ = 'r';

template <typename T>
const char XmlFileSerializer<T>::WRITE = 'w';

template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string &fn, char m, const string &cn)
{
    filename = fn;
    mode = m;
    collectionName = cn;

    if (m == WRITE)
    {
        cout << "----- création du fichier d'un fichier " << fn << "-----" << endl;
        file.open(fn, ios::out);
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        file << "<" << cn << ">" << endl;

        cout << "----- création du fichier d'un fichier réussi " << fn << "-----" << endl;
    }

    if (m == READ)
    {
        string ligne;
        cout << "----- Lecture de l'entête dans le fichier " << fn << "-----" << endl;
        file.open(fn, ios::in);
        if (!file.is_open())
            throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "Fichier introuvable");

        getline(file, ligne);
        cout << "Lecture de la première ligne du fichier : " << ligne << endl;
        getline(file, ligne);
        cout << "Lecture de la seconde ligne du fichier qui sera notre Collection Name : " << ligne << endl << endl;

        cout << "Suppression des < > du collectionName ..." << ligne << endl << endl;
        ligne = ligne.substr(1,ligne.length() - 2); // Supprime les caractères <


        collectionName = ligne;

        cout << "---------------Collection Name --------------- : " << ligne << endl;
    }
}


template <typename T>
string XmlFileSerializer<T>::getFilename()
{
    return filename;
}

template <typename T>
string XmlFileSerializer<T>::getCollectionName()
{
    return collectionName;
}

template <typename T>
bool XmlFileSerializer<T>::isReadable()
{
    if (mode == READ)
        return true;
    return false;
}

template <typename T>
bool XmlFileSerializer<T>::isWritable()
{
    if (mode == WRITE)
        return true;
    return false;
}

template <typename T>
void XmlFileSerializer<T>::write(const T &val)
{
    if (mode == READ)
        throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "Ecriture en mode lecture est impossible");

    cout << "----- Ecriture d'un donnée dans le fichier " << filename << "-----" << endl;
    file << val << endl;
    cout << "----- Ecriture d'un donnée dans le fichier réussi " << filename << "-----" << endl;
}

template <typename T>
T XmlFileSerializer<T>::read()
{
    if (mode == WRITE)
        throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "Lecture en mode écriture est impossible");

    string ligne;
    string endCollectionName = "</" + collectionName + ">";
    streampos currentPos = file.tellg();

    cout << "----- Lecture d'un donnée dans le fichier " << filename << "-----" << endl;
    file >> ligne;
    cout << "----- Lecture d'une donnée dans le fichier réussi " << filename << "-----" << endl;

    cout << "----- Vérification du template : " << ligne << " pour savoir si on est à la fin du fichier ou non"
         << "-----" << endl;
    if (ligne == endCollectionName)
        throw XmlFileSerializerException(XmlFileSerializerException::END_OF_FILE, "Fin du fichier");

    file.seekg(currentPos);
    T type;
    file >> type;

    return type;
}

template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer()
{

    cout << "----- Ecriture de la fin de fichier : " << filename << "-----" << endl;
    file << "</" << collectionName << ">" << endl;
    file.close();
    cout << "----- Ecriture de la fin de fichier réussi : " << filename << "-----" << endl;
}
