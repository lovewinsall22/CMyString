#include <iostream>
#include "CMyString.h"

using namespace std;

CMyString::CMyString() : m_pszData(nullptr) {
	cout << "CMyString()" << endl;
}
CMyString::~CMyString() {
	cout << "~CMyString()" << endl;
	delete[] m_pszData;
}

char* CMyString::getData()
{
	return m_pszData;
}

void CMyString::setData(const char* pParam)
{
	if (m_pszData != nullptr)
		delete[] m_pszData;
	size_t length = strlen(pParam);
	m_pszData = new char[length + 1];

	strcpy_s(m_pszData, length + 1, pParam);
}
