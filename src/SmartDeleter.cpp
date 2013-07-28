#include "SmartDeleter.h"

template<class T>
SmartDeleter<T>::SmartDeleter(T *Ptr)
    : data(Ptr)
{

}

template<class T>
T* SmartDeleter<T>::operator->() {
    return data;
}

template<class T>
T* SmartDeleter<T>::take() {
    T* oldData = data;
    data = nullptr;

    return oldData;
}

template<class T>
SmartDeleter<T>::~SmartDeleter()
{
    delete data;
}
