#include <string>
#include <iostream>
#include <time.h>

#include "StudentData.h"


using std::cout;
using std::endl;

template <class T>
class Node
{
public:
	Node(T& newData);
	~Node();

	Node<T>* getNextPtr();
	void setNextPtr(Node<T>* pMem);
	T* getData();

private:
	Node<T>* mpNext;
	T mData;
};

template <class T>
Node<T>::Node(T& newData)
{
	mpNext = nullptr;
	mData = newData;
}

template <class T>
Node<T>::~Node()
{
}

template<class T>
Node<T>* Node<T>::getNextPtr()
{
	return mpNext;
}

template<class T>
void Node<T>::setNextPtr(Node<T>* pMem)
{
	mpNext = pMem;
}

template<class T>
T* Node<T>::getData()
{
	return &mData;
}
