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


    return 0;

}

