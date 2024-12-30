#ifndef XMLFILESERIALIZER_H
#define XMLFILESERIALIZER_H

#include <fstream>
#include <string>




template<typename T>
class XmlFileSerializer{

    private:
    fstream file;
    string filename;
    char mode;
    string collectionName;


    public:
    XmlFileSerializer() = delete;  //mot clé pour evité que ce sois automatique
    XmlFileSerializer(const string& fn, char m, const string& cn = "entities");
    XmlFileSerializer(const XmlFileSerializer& fs) = delete; //mot clé pour evité que ce sois automatique
    ~XmlFileSerializer();



    string getFilename();
    string getCollectionName();
    bool isReadable();
    bool isWritable();

    void write(const T& val);
    T read();

    XmlFileSerializer<T> operator=(const XmlFileSerializer<T>&) = delete;
    

    static const char READ;
    static const char WRITE;  
};

#include "XmlFileSerializer.ipp"

#endif