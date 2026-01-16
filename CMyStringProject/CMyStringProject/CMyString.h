#pragma once

class CMyString
{
public:
	CMyString();
	~CMyString();

	void setData(const char* pParam);

private:
	char* m_pszData;
};

