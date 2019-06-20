#ifndef LEDC_H
#define LEDC_H
#include "nodod.h"

template<class T>
class LEDC
{
    public:
        nodod<T>* head = nullptr;
        nodod<T>* fina = nullptr;
        void print();
        void add(T dato);
        void remov(T dato);
        bool fnd(T dato, nodod<T>* &ptr);
        ~LEDC()
        {
          nodod<T>* pes;
          cout << '\n';
          cout << " Lista circular doble delete " << '\n';

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
void LEDC<U>::add(U dato)
{
    U aux;
    nodod<U> *pos;
    nodod<U> *pes;

    if(!fnd(dato, pos))
    {

        if(!head)
        {
            head = new nodod<U> (dato,head);
            head->next = head;
            fina = head;
            head->prev = head;
        }

        else if(head->value > dato)
        {
            head = new nodod<U> (dato,head,head);
            fina->next = head;
        }

        else if(pos->next == fina)
        {
            pos = fina;
            pos->next = new nodod<U> (dato,head,fina);
            fina = pos->next;
            head->prev = fina;
        }


        else
        {
            pes = pos->next;
            pos->next = new nodod<U> (dato,pos->next);
            pes->prev = pos->next;
            pos->next->prev = pos;
        }

    }
}
template <class U>
bool LEDC<U>::fnd(U dato, nodod<U>* &ptr)
{
    ptr = head;
    for(nodod<U>* p = head;p && p->value < p->next->value && p->value <= dato;ptr = p,p = p->next)
    {
        if(p->value == dato)
        {
            return true;
        }
    }
    return false;
}

template <class U>
void LEDC<U>::print()
{

    nodod<U>* ptr = head;
    cout << head->value << " -> ";
    for(nodod<U>* p = ptr->next;p != fina->next;p = p->next)
    {

        cout << p->value << " -> " ;

    }
    cout << fina->next->value << '\n';
    cout << " Impresion al reves " << '\n';
    cout << fina->value << " -> ";
    for(nodod<U>* p = fina->prev;p != fina;p = p->prev)
    {
         cout << p->value << " -> " ;
    }
    cout << head->prev->value << '\n';
 }

template <class U>
void LEDC<U>::remov(U dato)
{
    nodod<U> *pes;
    nodod<U> *aux;
    if(fnd(dato,pes) != head)
    {
    if(head->value == dato)
    {
        pes = head;
        fina->next = head->next;
        head = head->next;
        head->prev = fina;
        delete(pes);
    }
    else if(fina->value == dato)
    {
        fnd(dato,pes);
        fina = pes;
        aux = pes->next;
        pes->next = head;
        head->prev = pes;
        delete(aux);
    }
    else
    {
        fnd(dato,pes);
        aux = pes->next;
        pes->next = pes->next->next;
        pes->next->prev = pes;
        delete(aux);

    }
    }


}

#endif // LEDC_H
