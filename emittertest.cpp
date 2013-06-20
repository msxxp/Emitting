#include <QObject>
#include <QString>
#include <stdio.h>
#include "emittertest.h"

EmitterTest::EmitterTest(QObject *parent) :
    QObject(parent)
{
    mem_value = 0;
    printf("new obj:%d\n",(int)this);
}


void EmitterTest::setValue(int v,int f,int w)
{
    // if the value has changed
    printf("The new value for %d\n", v);
    mem_value = v;
    printf("set obj:%d\n",(int)this);
    printf("The new value for %d\n", f);
}

void EmitterTest::setValueAndEmit(int v,int h)
{
    // if the value has changed
    if (v != mem_value)
    {
        mem_value = v;
        emit valueChanged(v,h,0);
        printf("The new value for %d..u\n", v);
    }
    printf("The new value for %d..u\n", v);
}
