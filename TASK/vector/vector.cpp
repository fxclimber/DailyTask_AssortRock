
#include <iostream>
#include <vector>
#include "UVector.h"

UVector<int> createVector() {
	return UVector<int>{1, 2, 3}; // 이동 생성자 호출
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		//------------------------std::vector---------------------

		//스택에 객체 직접 생성
		std::vector<int> v;
		//힙에 동적 메모리 할당시, 포인터로 선언해야한다 
		std::vector<int>* v1 = new std::vector<int>;

		v.reserve(100);
		std::cout << "v.capacity()" << v.capacity() << std::endl;


		for (int i = 0; i < 100; ++i)
		{
			v.push_back(i);
			std::cout << v[i] << std::endl;
		}
		//std::cout << "sizeof" << sizeof(v) << std::endl;//틀림, size()맞음
		std::cout << "v.capacity()" << v.capacity() << std::endl;
		std::cout << "size" << v.size() << std::endl;

		std::vector<int> v3 = v;
		v3 = v;



		v.clear();
		std::cout << "v.capacity()" << v.capacity() << std::endl;
		std::cout << "v.size()" << v.size() << std::endl;

	}




	//-----------UVector------------------------------
	UVector<int> uv;
	//UVector<int> uv2;
	uv.reserve(11);

	for (int i = 0; i < uv.getCapacity(); i++)
	{
		uv.push_back(i);
		std::cout << uv[i] << std::endl;
	}
	std::cout << "getSize : " << uv.getSize() << std::endl;
	std::cout << "getCapacity : " << uv.getCapacity() << std::endl;

	std::cout << "-------------end-----------------" << std::endl;

	UVector<int> uv2 = uv;

	UVector<int> uv3;
	uv3 = uv;

	for (int i = 0; i < uv2.getCapacity(); i++)
	{
		std::cout << "uv2 (" << i << ") : " << uv2[i] << std::endl;
	}

	UVector<int> vec = createVector(); // 여기서 이동 생성자 호출해야는데 안해...



	//uv.clear();

	//std::cin.get();
	return 0;//프로그램 정상종료 
}
