#ifndef LED_H
#define LED_H
#include "nodod.h"

using namespace std;

template <class T>
class LED
{
    public:
        nodod<T>* head = nullptr;
        void print();
        void add(T dato);
        void remov(T dato);
        bool fnd(T dato, nodod<T>* &ptr);
        ~LED()
        {
            cout << " DESTRUI LISTA ENLAZADA DOBLE " << '\n';
            nodod<T>* pes;
            while(head)
            {
                pes = head;
                head = head->next;
                delete(pes);
            }
            head = nullptr;
        };
};

template <class U>
void LED<U>::add(U dato)
{
    U aux;
    nodod<U> *pos;
    nodod<U> *pes;
    if(!fnd(dato, pos))
    {
        /*if(!pos)
        {
            if(!head)
            {
                head = new nodod<U> (dato,head);
            }
            else
            {
                pes = head;
                head = new nodod<U> (dato,head);
                pes->prev =  head;
            }

        }
        else
        {
            pos->next = new nodod<U> (dato,pos->next);
            pos->next->prev = pos;
        }*/
        if(!head)
        {
            head = new nodod<U> (dato,nullptr,nullptr);
        }
        else if(head->value > dato)
        {
            pes = head;
            head = new nodod<U> (dato);
            head->prev = pes;
            pes->next = head;

        }
        else if(!pos->next)
        {
            pos->next = new nodod<U> (dato);
            pos->next->prev = pos;
        }
        else
        {
            pes = pos->next;
            pos->next = new nodod<U> (dato,pes,pos);
            pes->prev = pos->next;
        }

    }
}
template <class U>
bool LED<U>::fnd(U dato, nodod<U>* &ptr)
{
    ptr = nullptr;
    for(nodod<U>* p = head;p && p->value <= dato;ptr = p ,p = p->next)
    {
        if(p->value == dato)
        {
            return true;
        }
    }
    return false;
}

template <class U>
void LED<U>::print()
{

    nodod<U>* ptr = head;

    for(nodod<U>* p = ptr;p;p = p->next)
    {
        if(p->next)
        {
            cout << p->value << " -> " ;
        }
        else
        {
            cout << p->value << '\n';
        }

        ptr = p;
    }
    cout << " LISTA IMPRESA AL REVES " << '\n';
    for(nodod<U>* p = ptr;p;p = p->prev)
    {
         if(p->prev)
        {
            cout << p->value << " -> " ;
        }
        else
        {
            cout << p->value << '\n';
        }
    }
}

template <class U>
void LED<U>::remov(U dato)
{
    nodod<U>* ptr, *ptr2;
    if(fnd(dato, ptr))
    {

    if(ptr)
    {
        ptr = ptr->next;
    }
    if(!ptr->next)
    {
        ptr2 = ptr;
        ptr = ptr->prev;
        ptr->next = nullptr;
        delete(ptr2);
    }

    else if(!ptr)
    {
        ptr2 = head;
        head = head->next;
        head->prev = nullptr;
        delete(ptr2);
    }
    else
    {
        ptr2 = ptr;
        ptr = ptr->prev;
        ptr2->next->prev = ptr;
        ptr->next = ptr2->next;
        delete(ptr2);
    }
    }
}

#endif // LED_H
