
#include <iostream>
#include <vector>
#include "UVector.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
	//------------------------std::vector---------------------

	////���ÿ� ��ü ���� ����
	//std::vector<int> v;
	////���� ���� �޸� �Ҵ��, �����ͷ� �����ؾ��Ѵ� 
	//std::vector<int>* v1 = new std::vector<int>;

	//v.reserve(100);
	//std::cout << "v.capacity()" << v.capacity() << std::endl;


	//for (int i = 0; i < 100; ++i)
	//{
	//	v.push_back(i);
	//	std::cout << v[i] << std::endl;
	//}
	////std::cout << "sizeof" << sizeof(v) << std::endl;//Ʋ��, size()����
	//std::cout << "v.capacity()" << v.capacity() << std::endl;
	//std::cout << "size" << v.size() << std::endl;

	//std::vector<int> v3 = v;



	//v.clear();	
	//std::cout << "v.capacity()" << v.capacity() << std::endl;
	//std::cout << "v.size()" << v.size() << std::endl;

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
	std::cout <<"getSize : " << uv.getSize() << std::endl;
	std::cout <<"getCapacity : " << uv.getCapacity() << std::endl;

	std::cout << "-------------end-----------------" << std::endl;

	UVector<int> uv2 = uv;//�� ���͸� �߸������������. ����ī���ϴϱ� ���α׷��� �����ִ��� �ܼ�â�� �ȴ�����.
	for (int i = 0; i < uv2.getCapacity(); i++)
	{
		std::cout << "uv2 ("<<i<<") : " << uv2[i] << std::endl;
	}

	uv.clear();

	//std::cin.get();
	return 0;//���α׷� �������� 
}