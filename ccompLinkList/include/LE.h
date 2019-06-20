#ifndef LE_H
#include <iostream>
#define LE_H
#include "nodo.h"

using namespace std;

template <class T>
class LE
{
    public:
        nodo<T>* head = nullptr;
        void print();
        void add(T dato);
        void remov(T dato);
        bool fnd(T dato, nodo<T>* &ptr);
        ~LE()
        {
            cout << " DESTRUI LISTA ENLAZADA " << '\n';
            while(head)
            {
                nodo<T>* pes;
                pes = head;
                head = head->next;
                delete(pes);
            }
            head = nullptr;

        };
};

template <class U>
void LE<U>::add(U dato)
{
    U aux;
    nodo<U> *pos;
    nodo<U> *pes;
    if(!fnd(dato, pos))
    {
        if(!pos)
        {
            head = new nodo<U> (dato,head);
        }
        else
        {
            pos->next = new nodo<U> (dato,pos->next);
        }


    }
}
template <class U>
bool LE<U>::fnd(U dato, nodo<U>* &ptr)
{
    ptr = nullptr;
    for(nodo<U>* p = head;p && p->value <= dato;ptr = p ,p = p->next)
    {
        if(p->value == dato)
        {
            return true;
        }
    }
    return false;
}

template <class U>
void LE<U>::print()
{

    nodo<U>* ptr = head;

    for(nodo<U>* p = ptr;p;p = p->next)
    {
         if(p->next)
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
void LE<U>::remov(U dato)
{
    nodo<U>* ptr, *ptr2;
    if(fnd(dato,ptr))
    {
    if(ptr)
    {
            ptr2 = ptr->next->next;
            delete(ptr->next);
            ptr->next = ptr2;
    }
    else if(!ptr)
    {
        head = head->next;
    }
    }
}
#endif // LE_H
