#pragma once
#include "Father.h"
#include "Mother.h"

class Son :
    public Father,public Mother
{
    void func1();
    void func7();
    virtual void func9();
    void func();
};

