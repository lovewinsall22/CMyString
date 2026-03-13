#pragma once

class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& rhs); // 딮카피를 위한 복사생성자
	~CMyString();

	void operator=(const CMyString& rhs); // 딮카피를 위한 단순대입연산자 재정의

	const size_t getLength() const;

	const char* getData() const;
	void setData(const char* pParam);

private:
	char* m_pszData;
	size_t length;
};

