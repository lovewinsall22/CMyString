#include <iostream>
#include "CMyString.h"

int main()
{
    CMyString hello;
    hello.setData("hello");
    std::cout << hello.getData() << std::endl;

    CMyString world(hello); // 복사생성자 호출
    std::cout << world.getData() << std::endl;
    return 0;

}

