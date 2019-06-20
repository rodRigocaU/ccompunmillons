#ifndef NODO_H
#define NODO_H

template<class T>
class nodo
{
    public:
        T value;
        nodo* next;
        nodo(T val_,nodo* next_ = nullptr)
        {
            value = val_;
            next = next_;
        }
};

/*template <class U>
nodo::nodo(U val_,nodo* next_)
{
    value = val_;
    next = next_;
}*/

#endif // NODO_H
