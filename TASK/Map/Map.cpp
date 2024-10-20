#include <iostream>
#include "UMap.h"
#include <map>
#include <set>
#include <cstring>

#pragma region Functor

//--------------------------------------------------------------------
struct CustomCompare
{
	bool operator()(const int& a, const int b)const
	{
		return a > b; //���������� ����,��������
	}
};

struct CustomCompareUp//����
{
	bool operator()(const int& a, const int& b)const
	{
		return a < b;
	}
};

//--------------------------------------------------------------------

struct ABSCompare//���밪
{
	bool operator()(const int a, const int b)const
	{
		if (std::abs(a) == std::abs(b))
		{
			return a < b;
		}
		return std::abs(a) < std::abs(b);
	}
};
//--------------------------------------------------------------------

struct LengthCompare
{
	bool operator()(const char* a, const char* b) const
	{
		return std::strlen(a) < std::strlen(b);
	}
};

//-----------���̱��� ����---------------------------------------------------------
struct Person
{
	std::string name;
	int age;
	Person(std::string n, int a) :name(n), age(a) {}
};
struct AgeCompare
{
	bool operator()(const Person& a, const Person& b)const
	{
		return a.age < b.age;//���̱��� ����
	}
};


#pragma endregion



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#pragma region std::map ����


	////map�� ���� , �ʱ�ȭ
	//std::map<int, int> myMap;
	//std::map<int, std::string> Mymap1 = { {1,"one"},{2,"two"},{3,"three"}};
	//std::map<int, char> myMap2 = { {1,'A'},{2,'B'},{3,'C'}};
	//std::map<char, int> myMap3({ {'a',1},{'b',2},{'c',3}});

	//std::set<int> mySet;
	//std::set<int> mySet1 = {1};

	////insert , c++11�������� ,����+����+����
	////pair<,> ����ü�� ����ؾ��Ѵ�, �Ǵ� { , } -> �̹� ���� ��ü�� �����Ҷ�!

	//std::pair<int, int> myPair = { 1,2 };//�̹� ������ pair����
	//myMap.insert(myPair);//�̹� ������ pair����
	//myMap.insert(std::make_pair(10, 11));//�̹� ������ pair����
	//myMap.insert({22,33});
	//myMap.insert(std::map<int, int>::value_type(2, 8));
	//myMap.insert({77,14});
	//myMap.insert({37,91});//���� Ű�� �ߺ��ɰ��, ��ó���͸� ����,������ �����ʴ´�.�����ƴ�.
	//myMap.insert({7,100});
	//myMap.insert({3,8});
	//myMap.insert({94,1});
	//myMap.insert({37,11});
	//myMap.insert({37,1});
	//myMap.insert({37,2});

	////emplace , c++ 11���� ����
	//// insert :  {} make_pair ��ü����-> �� ��ü�� ����,�̵�(�߰����)
	////emplace : ()���� ���ڸ� �޾� ��ü���� , �������(�߰�������) <- ����!
	//myMap.emplace(100,1000);//����+����

	//// []
	//myMap[22] = 100;//�������
	//myMap[2] = 222;//���� Ű�� ������, ���� "Ű-��" �߰�

	//// ������ "Ű"�� �ʿ��ϴ�. ���õǴ� ��찡 �־��, Ű�� ����.. 
	//myMap.erase({37});

	////find
	////���� ����ϴ� ����
	//std::map<int, int>::iterator findIter = myMap.find(22);
	//if (myMap.find(333) != myMap.end())//end()�� ���� ����Ÿ(����)�̴�. �̰Ͱ� ���ٸ�, ���� ���̶���
	//{
	//	std::cout << "key 3 is valid " << std::endl;
	//}
	//else
	//{
	//	std::cout << "key 333 is not valid " << std::endl;
	//}

	//// �ʳ��� ����Ÿ : Ű,���
	//// first,second�� ����ƴϰ�, map������ ���
	//findIter->first;//���� Ű
	//findIter->second;//���� ���

	//std::map<int, int>::iterator startIt = myMap.begin();//�ʰ�ü ��ü�߿� ����, ����Ÿ�ִ� ù���
	//std::map<int, int>::iterator endIt = myMap.end();//�ʰ�ü ��ü�߿� ��-����Ÿ �ƴ�, ��������(���̿���)

	//// ����,����带 ���������, �ʰ�ü���� ����Ÿ�� ����
	//for (; startIt != endIt; ++startIt)
	//{
	//	std::cout <<"index : " << startIt->first << ", value : " << startIt->second << std::endl;
	//}

	////size
	////����� ����
	//std::cout <<"myMap.size() : " << myMap.size() << std::endl;

	////empty
	////���� ������� true���� 
	//std::cout <<"myMap3.empty : " << myMap3.empty() << std::endl;


#pragma endregion 

#pragma region align ABS
std::cout << "-------align ABS----------------------------------------" << std::endl;

	std::map<int, std::string, ABSCompare> myCustomMap;
	myCustomMap.emplace(1,"one");
	myCustomMap.emplace(12,"twelve");
	myCustomMap.emplace(-11,"eleven");
	myCustomMap.emplace(11,"eleven");
	myCustomMap.emplace(2,"two");
	myCustomMap.emplace(-3,"three");
	myCustomMap.emplace(3,"three");
	myCustomMap.emplace(5,"five");
	myCustomMap.emplace(4,"four");
	myCustomMap.emplace(-10,"ten");

	for (const auto& pair : myCustomMap)
	{
		std::cout << pair.first << ":" << pair.second << std::endl;
	}



#pragma endregion

#pragma region ���ڿ�����
	std::cout << "-------���ڿ�����----------------------------------------" << std::endl;

	std::map<const char*, int, LengthCompare> myCharMap;
	myCharMap.emplace("short",0);
	myCharMap.emplace("long",2);
	myCharMap.emplace("big",7);
	myCharMap.emplace("zenith",5);
	myCharMap.emplace("unreal engine",1);
	myCharMap.emplace("longest",3);
	//auto��� Ǯ�������� �Ẹ�Ҵ�...
	for (std::map<const char*, int, LengthCompare>::const_iterator it = myCharMap.begin(); it != myCharMap.end(); ++it)
	{
		const char* key = it->first;
		int value = it->second;
		std::cout << "key : " << key << " value: " << value << std::endl;
	}



#pragma endregion

#pragma region ���ڿ�����
std::cout << "-------���̱��� ����----------------------------------------" << std::endl;
//�̹��� Ư������. ����ü(��Ʈ��,������ �������)�� Ű�� �ϰ�, "����"���� ��Ʈ���� ����� �Ͽ���.
std::map<Person, std::string, AgeCompare> myAge;
myAge.insert({ {"Alice",30},"Engineer"});
//�׷���, ��ü������ �ʱ�ȭ�� ����, Ű�� ����ü������ �ΰ��� ��������� �� �����ִ�.
myAge.insert({ {"Robert",17},"Student"});
myAge.insert({ {"Berk",41},"Teacher"});
myAge.insert({ {"Elizabeth",21},"Salesman"});
myAge.insert({ {"Jorge",53},"Cop"});

for (const auto& pair : myAge)
{
	std::cout << "name :" << pair.first.name << ", age:" << pair.first.age << ", Job :" << pair.second << std::endl;
}






#pragma endregion





	return 0;

}
