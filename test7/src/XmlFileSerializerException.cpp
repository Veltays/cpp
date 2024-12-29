#include "XmlFileSerializerException.h"

int XmlFileSerializerException::NOT_ALLOWED = 6;
int XmlFileSerializerException::FILE_NOT_FOUND = 7;
int XmlFileSerializerException::END_OF_FILE = 8;

XmlFileSerializerException::XmlFileSerializerException()
{
    code = 0;
}

XmlFileSerializerException::XmlFileSerializerException(int co, string msg): Exception(msg)
{
    setCode(co);
}

int XmlFileSerializerException::getCode()
{
    return code;
}
void XmlFileSerializerException::setCode(int co)
{
    if(code < 0);
        return;
    code = co;
}
