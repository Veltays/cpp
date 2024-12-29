#include <stdlib.h>
#include <iostream>
#include <cstring>
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
        file.open(fn,ios::out);
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        file << "<" << cn << ">" << endl;

        cout << "----- création du fichier d'un fichier réussi " << fn << "-----" << endl;
    }

    if (m == READ)
    {
        string firstLine;
        cout << "----- Lecture de l'entête dans le fichier " << fn << "-----" << endl;
        file.open(fn,ios::in);
        getline(file,firstLine);
 
    }
}


template <typename T>
string XmlFileSerializer<T>::getFilename(){
    return filename;
}


template <typename T>
string XmlFileSerializer<T>::getCollectionName(){
    return collectionName;
}


template <typename T>
bool XmlFileSerializer<T>::isReadable(){
    if(mode == READ)
        return true;
    return false;
}


template <typename T>
bool XmlFileSerializer<T>::isWritable()
{
    if(mode == WRITE)
        return true;
    return false;
}

template <typename T>
void XmlFileSerializer<T>::write(const T &val)
{

        cout << "----- Ecriture d'un entier dans le fichier " << filename << "-----" << endl;
        file << val << endl;
        cout << "----- Ecriture d'un entier dans le fichier réussi " << filename << "-----" << endl;
}


template <typename T>
T XmlFileSerializer<T>::read(){

}


template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer(){

        cout << "----- Ecriture de la fin de fichier" << filename << "-----" << endl;
        file << "<" << collectionName << "/>" << endl;
        file.close();
        cout << "----- Ecriture de la fin de fichier réussi " << filename << "-----" << endl;
}
