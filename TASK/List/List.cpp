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

	//데이터 출력
	for (; beginIter != endIter; ++beginIter)
	{
		int& value = *beginIter;
		std::cout << "data1 : " << value << std::endl;
	}

	beginIter = list.begin();//재 시작
	//beginIter 가 끝까지 갔으므로, 다시 앞으로 보내야,다음 출력이된다.
	
	std::cout << "//--------------------------------------" << std::endl;

	UList::iterator testIter = list.begin();//여기까진 값없는 더미시작노드
	testIter = ++beginIter;//시작노드가 1칸이동하니,1을 가리킴,테스트도 1
	testIter = list.erase(testIter);//테스트가 가리키는 1삭제
	std::cout << *testIter << std::endl;//1이 삭제되니,테스트는 이제2를 가리킴

	beginIter = list.begin();

	for (; beginIter != endIter; ++beginIter)
	{
		int& value = *beginIter;
		std::cout << "data2 : " << value << std::endl;
	}



	int a = 0;

	return 0;
}