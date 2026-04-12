#include <iostream>
#include "CMyString.h"

using namespace std;

CMyString::CMyString() : m_pszData(nullptr), length(0) {
	cout << "CMyString()" << endl;
}
CMyString::CMyString(const char* param) {
	cout << "CMyString(const char*)" << endl;
	this->setData(param);
}
CMyString::CMyString(const CMyString& rhs) {
	cout << "CMyString(const CMyString& rhs)" << endl;
	this->setData(rhs.getData()); // 복사생성자의 딮카피 코드 => setData가 내부적으로 동적할당코드

}
CMyString::CMyString(CMyString&& rhs) noexcept {
	cout << "CMyString(CMyString&& rhs) - move" << endl;
	this->m_pszData = rhs.m_pszData; // shallow copy
	rhs.m_pszData = nullptr;
}
CMyString::~CMyString() {
	cout << "~CMyString()" << endl;
	delete[] m_pszData;
}

void CMyString::operator=(const CMyString& rhs)
{
	cout << "CMyString::Operator=(const CMyString& rhs)" << endl;
	this->setData(rhs.getData());
}
void CMyString::operator=(CMyString&& rhs) noexcept
{
	cout << "CMyString::Operator=(CMyString&& rhs) - move" << endl;
	this->m_pszData = rhs.m_pszData; // shallow copy
	rhs.m_pszData = nullptr;
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
