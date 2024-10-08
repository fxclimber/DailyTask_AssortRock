#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    //시드
    std::srand(static_cast<unsigned __int64>(std::time(nullptr)));
    
    //랜드 (1~100사이 정수)
    for (int i = 0; i < 10; i++)
    {
        int randNum = std::rand() % 100 +1;
        std::cout <<i <<"  : " << "randNum : " << randNum << std::endl;
    }
}

//2024.10.08