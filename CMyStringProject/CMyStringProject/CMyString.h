#pragma once
#include <iostream>
using namespace std;

class CMyString
{
public:
	CMyString() : m_pszData(nullptr) {
		cout << "CMyString()" << endl;
	}
	~CMyString() {
		cout << "~CMyString()" << endl;
	}

	char* getData() {
		return m_pszData;
	}
private:
	char* m_pszData;
};

