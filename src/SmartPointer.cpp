#include "SmartPointer.h"

template<class T>
SmartPointer<T>::SmartPointer(T *Ptr)
    : data(Ptr)
{

}

template<class T>
T* SmartPointer<T>::operator->() {
    return data;
}

template<class T>
T* SmartPointer<T>::take() {
    T* oldData = data;
    data = nullptr;

    return oldData;
}

template<class T>
SmartPointer<T>::~SmartPointer()
{
    delete data;
}
