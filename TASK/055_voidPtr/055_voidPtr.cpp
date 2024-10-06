#include <iostream>

//크기와 상관없이 주소값의 의미로 사용되는 포인터 void*
void Test(void* _Value)
{
    std::cout << "주소출력 void포인터" << _Value << std::endl;
}




int main()
{
    //여러자료형이 있으면, 각 자료형의 포인터들은 서로 호환이 되지않는다.
    int iPtr = 10;
    char cPtr = 'c';

    Test(&iPtr);  // int* 포인터를 void*로 변환
    Test(&cPtr);  // char* 포인터를 void*로 변환

    iPtr + 1;
    //void*은 위치의 의미만 갖는다
    //자신의 크기를 버린, 위치정보만 
    //어떤 포인터이건 void*이 될수있다.

}
