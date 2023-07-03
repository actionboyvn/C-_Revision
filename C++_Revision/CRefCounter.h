#pragma once
class CRefCounter {
public:
	CRefCounter();
	int iInc();
	int iDec();
	int iGet();
private:
	int i_count;
};

inline CRefCounter::CRefCounter()
{
	i_count = 0;
}

inline int CRefCounter::iInc()
{
	return ++i_count;
}

inline int CRefCounter::iDec()
{
	return --i_count;
}

inline int CRefCounter::iGet()
{
	return i_count;
}
