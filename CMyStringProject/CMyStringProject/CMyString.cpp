#include <iostream>
#include "CMyString.h"

using namespace std;

CMyString::CMyString() : m_pszData(nullptr), length(0) {
	cout << "CMyString()" << endl;
}
CMyString::~CMyString() {
	cout << "~CMyString()" << endl;
	delete[] m_pszData;
}

const size_t CMyString::getLength() const
{
	return this->length;
}

const char* CMyString::getData() const
{
	return m_pszData;
}

void CMyString::setData(const char* pParam)
{
	if (m_pszData != nullptr) // 이미 값이 채워져있다면
		delete[] m_pszData; // 비워줘야함
	size_t length = strlen(pParam); // 넘어온 값 길이 체크
	m_pszData = new char[length + 1]; // 널문자까지의 길이로 할당

	strcpy_s(m_pszData, length + 1, pParam); // 스트링카피
	this->length = length; // 길이 최신화
}
