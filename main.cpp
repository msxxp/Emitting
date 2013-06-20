#include <QCoreApplication>
#include "emittertest.h"
int main(int argc, char *argv[])
{
    /*
    QCoreApplication a(argc, argv);
    
    return a.exec();
    */

    EmitterTest em1;

//    if ( true )
{
        EmitterTest em2;
     QObject::connect(&em1, SIGNAL(valueChanged(int,int,int)),
                      &em2, SLOT(setValue(int,int,int)));

     em1.setValueAndEmit(10,3);
     printf("The connection from the object connection em1 %d should equal em2 %d \n", em1.getValue(), em2.getValue());
     em2.setValueAndEmit(15,7);
     printf("The connection from the object connection em1 %d should NOT equal em2 %d \n", em1.getValue(), em2.getValue());
     // the values are not the same because I have not connected them even though I have called the emit within the
     // setValueAndEmit
}

     {
         EmitterTest em3;
         QObject::connect(&em1, SIGNAL(valueChanged(int,int,int)),
                          &em3, SLOT(setValue(int,int,int)));
     }

      em1.setValueAndEmit(150,7);
      printf("The connection from the object connection em1 %d should equal em2 %d \n", 1,1);

     return 0;
}
