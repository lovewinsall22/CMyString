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
    CMyString hello("hello ");
    CMyString world("world");

    CMyString Res(hello + world);
    std::cout << Res.getLength() << std::endl;
    std::cout << Res[-1] << std::endl;
    std::cout << Res[11] << std::endl;
    std::cout << Res[0] << std::endl;
    std::cout << Res[10] << std::endl;
    return 0;

}

