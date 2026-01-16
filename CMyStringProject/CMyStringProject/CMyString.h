#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();

	size_t getLength();

	char* getData();
	void setData(const char* pParam);

private:
	char* m_pszData;
	size_t length;
};

