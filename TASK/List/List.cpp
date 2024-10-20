#include <iostream>
#include "UList.h"


int main()
{
	UList list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(7);
	list.push_back(16);
	list.push_back(43);
	list.push_front(77);

	UList::iterator beginIter = list.begin();
	UList::iterator endIter = list.end();

	//������ ���
	for (; beginIter != endIter; ++beginIter)
	{
		int& value = *beginIter;
		std::cout << "data1 : " << value << std::endl;
	}

	beginIter = list.begin();//�� ����
	//beginIter �� ������ �����Ƿ�, �ٽ� ������ ������,���� ����̵ȴ�.
	
	std::cout << "//--------------------------------------" << std::endl;

	UList::iterator testIter = list.begin();//������� ������ ���̽��۳��
	testIter = ++beginIter;//���۳�尡 1ĭ�̵��ϴ�,1�� ����Ŵ,�׽�Ʈ�� 1
	testIter = list.erase(testIter);//�׽�Ʈ�� ����Ű�� 1����
	std::cout << *testIter << std::endl;//1�� �����Ǵ�,�׽�Ʈ�� ����2�� ����Ŵ

	beginIter = list.begin();

	for (; beginIter != endIter; ++beginIter)
	{
		int& value = *beginIter;
		std::cout << "data2 : " << value << std::endl;
	}



	int a = 0;

	return 0;
}