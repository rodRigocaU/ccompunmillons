#ifndef MERGESORT_H
#define MERGESORT_H
#include "LE.h"
#include "nodo.h"


template<class T>
class mergesort
{
    public:
        void sorted(LE<T>&,LE<T>&);
};

template<class U>
void mergesort<U>::sorted(LE<U> &ab,LE<U> &bb)
{
    nodo<U>* a = ab.head;
    nodo<U>* b = bb.head;
    nodo<U>* prev = nullptr;
    nodo<U>* e = nullptr;
    cout << a->value << '\n';
    cout << b->value << '\n';
    bool v = true;
    while(v)
    {
        cout << a->value << '\n';
        cout << b->value << '\n';
        if(a->value <= b->value && a == ab.head && b == bb.head)
        {
            e = a;
            prev = a;
            a = a->next;
        }
        else if(b->value <= a->value && a == ab.head && b == bb.head)
        {
            e = b;
            prev = b;
            b = b->next;
        }
        else if(a->value <= b->value)
        {
            prev->next = a;
            prev = a;
            a = a->next;
            if(!(a->next))
            {
                prev->next = a;
                a->next = b;
                v = false;
            }
        }
        else if(b->value <= a->value)
        {
            prev->next = b;
            prev = b;
            b = b->next;
            if(!(b->next))
            {
                prev->next = /*b*/b;
                b->next = a;
                v = false;
            }
        }
    }
    /*while(validation)
    {
        if(ptr1->value < ptr2->value)
        {
            if(cont == 1)
            {
                ne = ptr1;
                cont = 0;
            }

            if(ptr1->next == nullptr && ptr2 != b.head)
            {
                prev->next = ptr1;
                ptr1->next = ptr2;
                validation = false;
            }
            else if(ptr1->next == nullptr)
            {
                validation = false;
                prev->next = ptr2;
                ptr2->next = ptr1;
            }
            else if(ptr1->next->value > ptr2->value)
            {
                if(ptr2->next == nullptr)
                {
                    aux = ptr1->next;
                    ptr1->next = ptr2;
                    ptr1 = aux;
                    ptr2->next = ptr1;
                    validation = false;
                }
                else
                {
                    if(ptr1 != a.head && ptr2 != b.head)
                    {
                         prev->next = ptr1;
                    }
                    prev = ptr2;
                    aux = ptr1->next;
                    ptr1->next = ptr2;
                    ptr1 = aux;
                    ptr2 = ptr2->next;
                }
            }
            else
            {
                ptr1 = ptr1->next;
                prev = ptr2;
            }
        }
        ///OTRO CONDICIONAL
        else if(ptr2->value < ptr1->value)
        {
            if(cont == 1)
            {
                ne = ptr2;
                cont = 0;
            }
            if(ptr2->next == nullptr && ptr1 != a.head)
            {
                validation = false;
                prev->next = ptr2;
                ptr2->next = ptr1;
            }
            else if(ptr2->next == nullptr && ptr1 == a.head)
            {
                validation = false;
                ptr2->next = prev;
            }
            else if(ptr2->next->value > ptr1->value)
            {
                if(ptr1->next == nullptr)
                {
                    aux = ptr2->next;
                    ptr2->next = ptr1;
                    ptr2 = aux;
                    ptr1->next = ptr2;
                    validation = false;
                }
                else
                {
                    if(ptr2 != b.head && ptr1 != a.head)
                    {
                        prev->next = ptr2;
                    }
                    prev = ptr1;
                    aux = ptr2->next;
                    ptr2->next = ptr1;
                    ptr2 = aux;
                    ptr1 = ptr1->next;
                }
            }
            else
            {
                ptr2 = ptr2->next;
                prev = ptr1;
            }
        }
    }*/
    ab.head = e;

}

#endif // MERGESORT_H
