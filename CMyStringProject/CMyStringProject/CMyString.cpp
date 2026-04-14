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

CMyString& CMyString::operator=(const CMyString& rhs)
{
	cout << "CMyString::Operator=(const CMyString& rhs)" << endl;
	this->setData(rhs.getData());

	return *this;
}
CMyString& CMyString::operator=(CMyString&& rhs) noexcept
{
	cout << "CMyString::Operator=(CMyString&& rhs) - move" << endl;
	this->m_pszData = rhs.m_pszData; // shallow copy
	rhs.m_pszData = nullptr;

	return *this;
}

CMyString CMyString::operator+(const CMyString& rhs)
{	
	CMyString result(this->m_pszData);
	result.append(rhs.m_pszData);
	return result;
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

size_t CMyString::append(const char* pParam)
{
	if (pParam == nullptr)
		return -1;

	if (this->m_pszData == nullptr)
	{
		this->setData(pParam);
		return strlen(pParam);
	}
	else
	{
		size_t pParamLen = strlen(pParam);
		char* appendResult = new char[length + pParamLen + 1];

		strcpy_s(appendResult, length + pParamLen + 1, this->m_pszData);
		strcat_s(appendResult + length, pParamLen + 1, pParam);

		delete[] this->m_pszData;
		m_pszData = appendResult;
		return strlen(appendResult);
	}

	return 0;
}

CMyString operator+(const char* pLeft, const CMyString& rhs)
{
	CMyString result(pLeft);
	result.append(rhs.getData());
	return result;
}