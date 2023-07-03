#pragma once
#include "CRefCounter.h"
template<typename T>
class CMySmartPointer
{
public:
	CMySmartPointer();
	CMySmartPointer(T* pcPointer);
	CMySmartPointer(const CMySmartPointer& pcOther);
	~CMySmartPointer();
	T& operator*();
	T* operator->();
	void operator=(const CMySmartPointer& pcOther);
	void vResetSmartPointer();
	int iGetCount();
private:
	T* pc_pointer;
	CRefCounter* pc_counter;
};

template<typename T>
inline CMySmartPointer<T>::CMySmartPointer()
{
	pc_pointer = nullptr;
	pc_counter = nullptr;
}

template<typename T>
inline CMySmartPointer<T>::CMySmartPointer(T* pcPointer)
{
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter();
	pc_counter->iInc();
}

template<typename T>
inline CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer& pcOther)
{
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iInc();
}

template<typename T>
inline CMySmartPointer<T>::~CMySmartPointer()
{
	vResetSmartPointer();
}

template<typename T>
inline T& CMySmartPointer<T>::operator*()
{
	return *pc_pointer;
}

template<typename T>
inline T* CMySmartPointer<T>::operator->()
{
	return pc_pointer;
}

template<typename T>
inline void CMySmartPointer<T>::operator=(const CMySmartPointer& pcOther)
{
	vResetSmartPointer();
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iInc();
}

template<typename T>
inline void CMySmartPointer<T>::vResetSmartPointer()
{
	if (pc_counter != nullptr)
		if (pc_counter->iDec() == 0) {
			delete pc_pointer;
			delete pc_counter;
		}
	pc_pointer = nullptr;
	pc_counter = nullptr;
}

template<typename T>
inline int CMySmartPointer<T>::iGetCount()
{
	if (pc_counter == nullptr)
		return 0;
	return pc_counter->iGet();
}
