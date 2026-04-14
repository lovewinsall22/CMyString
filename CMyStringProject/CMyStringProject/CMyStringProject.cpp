#include <iostream>
#include "CMyString.h"

CMyString getHello()
{
    CMyString hello;
    hello.setData("hello");
    return hello; // 임시객체 생성
}

int main()
{
    //CMyString result; // 객체생성
    //result = ::getHello(); // 반환되는 임시객체로 인해 이동대입연산자 실행
    //std::cout << result << std::endl;

    //CMyString test(std::move(::getHello())); // 이동 생성자로 객체 생성

    CMyString hello("hello ");
    CMyString world("world");

    CMyString result(hello + world);
    std::cout << result << std::endl;
    std::cout << "bye " + world << std::endl;

    std::cout << "+=+=+=+=+=" << std::endl;
    result += "!!!!";

    CMyString a("????");
    result += a;
    std::cout << result << std::endl;

    return 0;

}

