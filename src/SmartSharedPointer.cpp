#include "SmartSharedPointer.h"
#include "Exceptions.h"
#include "ReferenceCounter.h"

template<class T>
SmartSharedPointer<T>::SmartSharedPointer()
    : data(0), refCounter(0) {

    refCounter = new ReferenceCounter();
    refCounter->addReference();

}

template<class T>
SmartSharedPointer<T>::SmartSharedPointer(T *Ptr)
    : data(Ptr), refCounter(0) {

    refCounter = new ReferenceCounter();
    refCounter->addReference();

}

template<class T>
SmartSharedPointer<T>::SmartSharedPointer(const SmartSharedPointer<T>& smartSharedPointer)
    : data(smartSharedPointer.data), refCounter(smartSharedPointer.refCounter) {
    refCounter->addReference();
}

template<class T>
T* SmartSharedPointer<T>::operator->() {
    return data;
}

template<class T>
T& SmartSharedPointer<T>::operator *() {
    return *data;
}

template<class T>
SmartSharedPointer<T>& SmartSharedPointer<T>::operator=(const SmartSharedPointer<T>& smartSharedPointer) {

    if (this != &smartSharedPointer) { // do not allow self assignment

        // decrement old ref count in order to copy the new one.
        if (refCounter->releaseReference() == 0) {
            delete data;
            delete refCounter;
        }

        data = smartSharedPointer.data;
        refCounter = smartSharedPointer.refCounter;
        refCounter->addReference();
    }

    return *this;
}

template<class T>
SmartSharedPointer<T>::~SmartSharedPointer()
{
    if (refCounter->releaseReference() == 0) {
        delete data;
        delete refCounter;
    }
}
