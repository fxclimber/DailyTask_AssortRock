#include <iostream>

//ũ��� ������� �ּҰ��� �ǹ̷� ���Ǵ� ������ void*
void Test(void* _Value)
{
    std::cout << "�ּ���� void������" << _Value << std::endl;
}




int main()
{
    //�����ڷ����� ������, �� �ڷ����� �����͵��� ���� ȣȯ�� �����ʴ´�.
    int iPtr = 10;
    char cPtr = 'c';

    Test(&iPtr);  // int* �����͸� void*�� ��ȯ
    Test(&cPtr);  // char* �����͸� void*�� ��ȯ

    iPtr + 1;
    //void*�� ��ġ�� �ǹ̸� ���´�
    //�ڽ��� ũ�⸦ ����, ��ġ������ 
    //� �������̰� void*�� �ɼ��ִ�.

}
