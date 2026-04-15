#pragma once

class CMyString
{
	friend CMyString operator+(const char* pLeft, const CMyString& rhs);
public:
	CMyString(); // 기본생성자
	explicit CMyString(const char* param); // 묵시적변환을 막는 변환생성자 ===> 객체의생성/소멸로 인한 성능저하를 막고 단순대입이 변환생성자를 호출하는 혼란을 막기 위해 explicit 넣기
	CMyString(const CMyString& rhs); // 딮카피를 위한 복사생성자 ===> 기본적으로 얕은복사를 하여 댕글링포인터가 발생할 위험을 방지하기 위해 딮카피하는 복사생성자 기술
	CMyString(CMyString&& rhs) noexcept; // 임시객체 상수형 참조를 위한 이동생성자 ===> 의도적 얕은복사를 하여 성능저하를 막기
	virtual ~CMyString();

	CMyString& operator=(const CMyString& rhs); // 딮카피를 위한 단순대입연산자 재정의 ===> 재정의 안할시 얕은복사 수행 ... 해제시 댕글링포인터 오류발생
	CMyString& operator=(CMyString&& rhs) noexcept; // 이동생성자의 세트인 이동대입연산자 재정의 ===> 재정의 안할시 얕은복사만 수행 ... 해제시 댕글링포인터 오류발생
																								// 임시객체의 주소를 nullptr로 만들어주며 얕은복사해야함
	operator const char* () { // cout이 클래스에 대한 호환성을 가지게 되는 operator
		return m_pszData;
	}
	CMyString operator+(const CMyString& rhs);
	CMyString operator+(const char* pParam);
	size_t append(const char* pParam);
	CMyString& operator+=(const char* pParam);
	CMyString& operator+=(const CMyString& rhs);
	char operator[](const int index);
	const size_t getLength() const;

	const char* getData() const;
	void setData(const char* pParam);
	virtual void onSetData(const char*& pParam) {}

private:
	char* m_pszData;
	size_t length;
};

