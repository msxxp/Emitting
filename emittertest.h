#ifndef EMITTERTEST_H
#define EMITTERTEST_H

#include <QObject>

class EmitterTest : public QObject
{
    Q_OBJECT
public:
    explicit EmitterTest(QObject *parent = 0);
    
    int getValue() const { return mem_value;}
    void setValueAndEmit(int v,int h);

// these pick up the emitted signal
public slots :
    void setValue(int v,int f,int w);

// these are what are sent out over emitted signals
// you do not implement the signals since they are just virtual functions
// as such that you call with emit then the value within the parameter(s)
// is passed to the slot.
signals:
    void valueChanged(int newV,int h,int w);

private:
    int mem_value;
    
};

#endif // EMITTERTEST_H
