#include <iostream>
#include "CMyString.h"

using namespace std;

CMyString::CMyString() : m_pszData(nullptr) {
	cout << "CMyString()" << endl;
}
CMyString::~CMyString() {
	cout << "~CMyString()" << endl;
}

void CMyString::setData(char* pParam)
{
	
}
