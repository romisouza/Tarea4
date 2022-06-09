#ifndef IOBSERVER
#define IOBSERVER

class IObserver{
    public:
        virtual void notificar()=0;
        virtual ~IObserver()=0;
};

#endif