#include "SmartDeleter.h"

template<class T>
SmartDeleter<T>::SmartDeleter(T *Ptr)
    : m_Ptr(Ptr)
{

}

template<class T>
T* SmartDeleter<T>::operator->() {
    return m_Ptr;
}

template<class T>
SmartDeleter<T>::~SmartDeleter()
{
    delete m_Ptr;
}
