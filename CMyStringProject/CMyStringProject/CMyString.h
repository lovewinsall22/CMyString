#pragma once

class CMyString
{
public:
	CMyString();
	explicit CMyString(const char* param); // 묵시적변환을 막는 변환생성자
	CMyString(const CMyString& rhs); // 딮카피를 위한 복사생성자
	CMyString(CMyString&& rhs) noexcept; // 임시객체 상수형 참조를 위한 이동생성자
	~CMyString();

	void operator=(const CMyString& rhs); // 딮카피를 위한 단순대입연산자 재정의
	void operator=(CMyString&& rhs) noexcept; // 이동생성자의 세트인 이동대입연산자 재정의
	operator const char* () {
		return m_pszData;
	}

	const size_t getLength() const;

	const char* getData() const;
	void setData(const char* pParam);

private:
	char* m_pszData;
	size_t length;
};

