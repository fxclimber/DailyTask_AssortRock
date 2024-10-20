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
		return a > b; //작은값부터 정렬,내림차순
	}
};

struct CustomCompareUp//오름
{
	bool operator()(const int& a, const int& b)const
	{
		return a < b;
	}
};

//--------------------------------------------------------------------

struct ABSCompare//절대값
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

//-----------나이기준 정렬---------------------------------------------------------
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
		return a.age < b.age;//나이기준 정렬
	}
};


#pragma endregion



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#pragma region std::map 기초


	////map의 선언 , 초기화
	//std::map<int, int> myMap;
	//std::map<int, std::string> Mymap1 = { {1,"one"},{2,"two"},{3,"three"}};
	//std::map<int, char> myMap2 = { {1,'A'},{2,'B'},{3,'C'}};
	//std::map<char, int> myMap3({ {'a',1},{'b',2},{'c',3}});

	//std::set<int> mySet;
	//std::set<int> mySet1 = {1};

	////insert , c++11이전문법 ,생성+복사+삽입
	////pair<,> 구조체를 사용해야한다, 또는 { , } -> 이미 만든 객체를 삽입할때!

	//std::pair<int, int> myPair = { 1,2 };//이미 생성된 pair삽입
	//myMap.insert(myPair);//이미 생성된 pair삽입
	//myMap.insert(std::make_pair(10, 11));//이미 생성된 pair삽입
	//myMap.insert({22,33});
	//myMap.insert(std::map<int, int>::value_type(2, 8));
	//myMap.insert({77,14});
	//myMap.insert({37,91});//같은 키가 중복될경우, 맨처음것만 쓰고,나머진 넣지않는다.에러아님.
	//myMap.insert({7,100});
	//myMap.insert({3,8});
	//myMap.insert({94,1});
	//myMap.insert({37,11});
	//myMap.insert({37,1});
	//myMap.insert({37,2});

	////emplace , c++ 11이후 문법
	//// insert :  {} make_pair 객체생성-> 이 객체를 복사,이동(추가비용)
	////emplace : ()안의 인자를 받아 객체생성 , 복사없음(추가비용없음) <- 권장!
	//myMap.emplace(100,1000);//생성+삽입

	//// []
	//myMap[22] = 100;//밸류변경
	//myMap[2] = 222;//기존 키가 없으면, 새로 "키-쌍" 추가

	//// 삭제는 "키"만 필요하다. 무시되는 경우가 있어선가, 키만 쓰네.. 
	//myMap.erase({37});

	////find
	////맵을 사용하는 이유
	//std::map<int, int>::iterator findIter = myMap.find(22);
	//if (myMap.find(333) != myMap.end())//end()는 없는 데이타(더미)이다. 이것과 같다면, 없는 값이란뜻
	//{
	//	std::cout << "key 3 is valid " << std::endl;
	//}
	//else
	//{
	//	std::cout << "key 333 is not valid " << std::endl;
	//}

	//// 맵내부 데이타 : 키,밸류
	//// first,second는 공용아니고, map에서만 사용
	//findIter->first;//맵의 키
	//findIter->second;//맵의 밸류

	//std::map<int, int>::iterator startIt = myMap.begin();//맵객체 전체중에 시작, 데이타있는 첫노드
	//std::map<int, int>::iterator endIt = myMap.end();//맵객체 전체중에 끝-데이타 아닌, 종료조건(더미역할)

	//// 시작,끝노드를 만들었으니, 맵객체안의 데이타를 보까
	//for (; startIt != endIt; ++startIt)
	//{
	//	std::cout <<"index : " << startIt->first << ", value : " << startIt->second << std::endl;
	//}

	////size
	////요소의 갯수
	//std::cout <<"myMap.size() : " << myMap.size() << std::endl;

	////empty
	////맵이 비었으면 true리턴 
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

#pragma region 문자열길이
	std::cout << "-------문자열길이----------------------------------------" << std::endl;

	std::map<const char*, int, LengthCompare> myCharMap;
	myCharMap.emplace("short",0);
	myCharMap.emplace("long",2);
	myCharMap.emplace("big",7);
	myCharMap.emplace("zenith",5);
	myCharMap.emplace("unreal engine",1);
	myCharMap.emplace("longest",3);
	//auto대신 풀네임으로 써보았다...
	for (std::map<const char*, int, LengthCompare>::const_iterator it = myCharMap.begin(); it != myCharMap.end(); ++it)
	{
		const char* key = it->first;
		int value = it->second;
		std::cout << "key : " << key << " value: " << value << std::endl;
	}



#pragma endregion

#pragma region 문자열길이
std::cout << "-------나이기준 정렬----------------------------------------" << std::endl;
//이번엔 특이점이. 구조체(스트링,정수의 멤버있음)를 키로 하고, "직업"같은 스트링을 밸류로 하였다.
std::map<Person, std::string, AgeCompare> myAge;
myAge.insert({ {"Alice",30},"Engineer"});
//그래서, 객체생성과 초기화를 보면, 키인 구조체정보에 두개의 멤버변수를 다 적고있다.
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
