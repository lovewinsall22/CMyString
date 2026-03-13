#include <iostream>
#include "CMyString.h"

int main()
{
    CMyString hello("hello");
    //std::cout << hello.getData() << std::endl;
    std::cout << hello << std::endl;

    CMyString world(hello); // 복사생성자 호출
    //std::cout << world.getData() << std::endl;
    std::cout << world << std::endl;

    //CMyString everyone = world; // == everyone(world);
    CMyString everyone;
    everyone = world;
    //std::cout << everyone.getData() << std::endl;
    std::cout << everyone << std::endl;
    return 0;

}

