#ifndef IOBSERVER
#define IOBSERVER
class Calificacion;

class IObserver{
    public:
        virtual void notificar(Calificacion calif)=0;
        virtual ~IObserver()=0;
};

#endif