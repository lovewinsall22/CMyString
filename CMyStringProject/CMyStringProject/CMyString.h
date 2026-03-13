#pragma once

class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& rhs); // 딮카피를 위한 복사생성자
	~CMyString();

	const size_t getLength() const;

	const char* getData() const;
	void setData(const char* pParam);

private:
	char* m_pszData;
	size_t length;
};

