#include <iostream>
#include "CMyString.h"
#include "CMyStringEx.h"

CMyString getHello()
{
    CMyString hello;
    hello.setData("hello");
    return hello; // 임시객체 생성
}

int main()
{
    CMyStringEx a("BYE");
    CMyString& b = a;

    std::cout << b << std::endl;

    return 0;

}

