#ifndef IOBSERVER
#define IOBSERVER
class Calificacion;

class IObserver{
    public:
        virtual void EliminarCalificaciones()=0;
        virtual list<Calificacion*> getCalifObs()=0;
        virtual string getEmailObs()=0;
        virtual IObserver* getObserver()=0;
        virtual void notificar(Calificacion* calif)=0;
        virtual ~IObserver(){};
};

#endif