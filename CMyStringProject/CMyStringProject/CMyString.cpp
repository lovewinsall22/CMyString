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
	size_t length = strlen(pParam);
	m_pszData = new char[length + 1];

	strcpy_s(m_pszData, length + 1, pParam);
}
