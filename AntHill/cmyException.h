#pragma once
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#endif  MYEXCEPTION_H
#include <map>

class cmyException :public std:: exception
{
public:


	enum error_id {};

  
     






private:
    error_id _errorcode;
    const char* _additional_info;
};
