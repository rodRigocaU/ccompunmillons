#ifndef NODOD_H
#define NODOD_H


template<class T>
class nodod
{
    public:
        T value;
        nodod* next;
        nodod* prev;
        nodod(T val_,nodod* next_ = nullptr,nodod* prev_ = nullptr)
        {
            value = val_;
            next = next_;
            prev = prev_;
        }
    private:
};

#endif // NODOD_H
