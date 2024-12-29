#include "Exception.h"

Exception::Exception(){
    setMsg("vide");
}

Exception::Exception(string msg){
    setMsg(msg);
}

string Exception::getMsg() const{
    return message;
}

void Exception::setMsg(string m){
    message = m;
}