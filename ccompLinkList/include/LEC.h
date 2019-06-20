#ifndef LEC_H
#define LEC_H
#include "nodoc.h"

template<class T>
class LEC
{
    public:
        nodoc<T>* head = nullptr;
        nodoc<T>* fina = nullptr;
        void print();
        void add(T dato);
        void remov(T dato);
        bool fnd(T dato, nodoc<T>* &ptr);
        void josephus(int,int);
        ~LEC()
        {
          nodoc<T>* pes;
          cout << '\n';
          cout << " Lista circular borrada " << '\n';
          while(head != head->next)
          {
                pes = head;
                head = head->next;
                fina->next = head;
                delete(pes);
          }
          head = nullptr;
          delete(head);
        };
};

template <class U>
void LEC<U>::add(U dato)
{
    U aux;
    nodoc<U> *pos;

    if(!fnd(dato, pos))
    {

        if(!head) ///CUANDO INSERTAMOS EL PRIMER ELEMENTO
        {
            head = new nodoc<U> (dato,head);
            head->next = head;
            fina = head;
        }

        else if(head->value > dato) ///CUANDO QUEREMOS INSERTAR UN ELEMENTO EN ANTES QUE LA CABEZA
        {
            //cout << dato << " e1 " << '\n';
            head = new nodoc<U> (dato,head);
            fina->next = head;
        }
        else if(pos->next == fina && fina->value < dato ) ///CUANDO INSERTAMOS AL FINAL
        {
            /*cout << dato << " e2 " << '\n';
            cout << pos->value<< '\n';*/
            pos = pos->next;
            pos->next = new nodoc<U> (dato,head);
            fina = pos->next;
        }
        else///CUANDO QUEREMOS INSERTAR ELEMENTOS EN EL CENTRO
        {
            /*cout << dato << " e3 " << '\n';
            cout << " EL POS VALUE " << pos->value << '\n';*/
            pos->next = new nodoc<U> (dato,pos->next);;

        }
    }
}
template <class U>
bool LEC<U>::fnd(U dato, nodoc<U>* &ptr)
{
    ptr = head;
    for(nodoc<U>* p = head;p && p->next != head && dato >= p->next->value; ptr = p,p = p->next)
    {

        if(p->value == dato)
        {
            return true;
        }
    }
    return false;
}

template <class U>
void LEC<U>::print()
{

    nodoc<U>* ptr = nullptr;
    cout << head->value << " -> " ;
    for(nodoc<U>* p = head->next;p != fina->next ;p = p->next)
    {
            cout << p->value << " -> " ;
    }
    cout << fina->next->value << '\n';

}

template <class U>
void LEC<U>::remov(U dato)
{
    nodoc<U> *pes;
    nodoc<U> *aux;
    ///cout << fnd(dato,pes) << '\n';
    fnd(dato,pes);
    if(pes->next->value == dato || pes->value == dato)
    {

        if(head->value == dato)
        {
            pes = head;
            fina->next = head->next;
            head = head->next;
            delete(pes);
        }
        else if(fina->value == dato)
        {
            fnd(dato,pes);
            fina = pes;
            aux = pes->next;
            pes->next = head;
            delete(aux);
        }
        else
        {
            fnd(dato,pes);
            aux = pes->next;
            pes->next = pes->next->next;
            delete(aux);
        }
    }
}
template<class U>
void LEC<U>::josephus(int cont, int kill)
{
    nodoc<U> *pes = head;
    int ct = 1;
    while(cont > 2)
    {

       if((ct + 1) % kill == 0)
       {
           remov(pes->next->value);
           cont--;
           pes = pes->next;
           ct = 0;
       }
       else
       {
           pes = pes->next;
       }

       ct++;
    }

}
#endif // LEC_H
