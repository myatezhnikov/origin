#pragma once
#include<string>
#include<exception>
class Errors : public std::exception
{
public:
    Errors(const std::string& message);
    const char* what() const noexcept
    {   
        return message.c_str();;
    };
private:
    std::string message; 
};
