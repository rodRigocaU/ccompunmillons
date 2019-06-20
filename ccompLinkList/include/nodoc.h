#ifndef NODOC_H
#define NODOC_H

template<class T>
class nodoc
{
    public:
    T value;
    nodoc* next;
    nodoc(T val_,nodoc* next_ = nullptr)
    {
        value = val_;
        next = next_;
    }
};

#endif // NODOC_H
