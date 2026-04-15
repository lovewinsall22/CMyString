#include <iostream>
#include "CMyStringEx.h"

using namespace std;

CMyStringEx::CMyStringEx()
{
	cout << "CMyStringEx()" << endl;
}

CMyStringEx::~CMyStringEx()
{
	cout << "~CMyStringEx()" << endl;
}

void CMyStringEx::setData(const char* pParam)
{
	if (pParam != nullptr)
	{
		if (strcmp(pParam,"BYE") == 0)
		{
			CMyString::setData("BYE CANCELED");
			return;
		}
		CMyString::setData(pParam);
	}
}
