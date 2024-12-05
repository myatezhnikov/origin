#pragma once
#include "Errors.h"

    Errors::Errors(const std::string& message) : message{ message }
    {
    }
    std::string message;    // сообщение об ошибке

