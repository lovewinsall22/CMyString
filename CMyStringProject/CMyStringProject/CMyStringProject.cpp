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
    //CMyString hello("hello ");
    //CMyString world("world");

    //std::cout << hello + world << std::endl; // + 오퍼레이터 오버로딩으로 정의
    //std::cout << hello + "world" << std::endl; // 
    //std::cout << "hello " + world << std::endl; // friend 함수로 정의

    CMyStringEx Ex;
    Ex.setData("BYE");
    std::cout << Ex << std::endl;
    return 0;

}

