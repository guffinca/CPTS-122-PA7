#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;


template <class T>
class List
{
public:
	List<T>();
	~List();

	void InsertAtFront(T& newData);

	T dequeue();
	bool isEmpty();
	Node<T>* getHeadPtr();
	void setHeadPtr(Node<T>* newHeadPtr);

private:
	Node<T>* mpHead;

	void deleteList();
};

template <class T>
List<T>::List()
{
	mpHead = nullptr;
}

template <class T>
List<T>::~List()
{
	cout << "Inside List deconstructor" << endl;
}

template <class T>
void List<T> ::InsertAtFront(T& newData)
{
	Node<T>* pMem = new Node<T>(newData);

	if (mpHead == nullptr)
	{
		mpHead = pMem;
	}
	else
	{
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}
}

template <class T>
T List<T> ::dequeue()
{
	T newData;
	Node<T>* pTemp = nullptr;

	pTemp = mpHead;
	newData = *(mpHead->getData());

	if (mpHead->getNextPtr() == nullptr) {
		mpHead = nullptr;
	}
	else {
		setHeadPtr(mpHead->getNextPtr());
	}
	delete pTemp;

	return newData;

}

template<class T>
bool List<T>::isEmpty()
{
	return mpHead == nullptr;
}

template<class T>
void List<T>::deleteList()
{
	while (!isEmpty()) {
		dequeue();
	}
}

template<class T>
Node<T>* List<T>::getHeadPtr()
{
	return mpHead;
}

template<class T>
void List<T>::setHeadPtr(Node<T>* newHeadPtr)
{
	mpHead = newHeadPtr;
}
