
#include <iostream>
#include <string>

int StringCount(const char* const _Str)
{	//포인터(주소)와 문자배열을 상수화 
	int Count = 0;
	while (true)
	{
		//char변수에 문자열을 대입한다.문자열은 C스타일 
		//얼핏보면, 낱개의 변수에 배열을 대입하는거같아 이상하지만, 
		// Ch는 낱개변수이고, _Str[Count]는 해당인덱스의 문자1개를 가져오므로, 배열이 아니다.
		char Ch = _Str[Count];

		//char Ch[Count] = _Str;
		//이 문법이 틀린 이유는, 배열의 크기도 제각각이라,배열끼리는 대입이 안되기때문이고,
		//_Str이 배열인 이유는 문자열(문자 배열)이므로.

		if (0 == Ch)
		{	//조건문의 성립이유-문자열은 늘 맨끝에 0이 오므로, 문자열의 인덱스별로 순회후, 0을 만난건 끝이란 의미
			break;
		}
		Count++;//한개씩 순회할때마다,1증가
	}
	return Count;
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxx
int StringsCount(const char* const _Str)
{
	// 포인터(주소)와 문자 배열을 상수화 
	int Count = 0;

	// 문자열을 순회하며 문자 수를 세기
	while (_Str[Count] != '\0') // 문자열의 끝을 나타내는 null 문자('\0')에 도달할 때까지
	{
		Count++; // 한 개씩 순회할 때마다 1 증가
	}
	return Count; // 문자 배열의 길이 반환
}



int main()
{
	//호출함수의 결과값받기 -> 변수에 저장하기 
	int result = StringCount("A125gkopPP_@");
	std::cout << result << std::endl;
	//----------------------------------------------------------
	const char* myString = "Hello, World!";
	int length = StringCount(myString);
	std::cout << "문자열의 길이는: " << length << std::endl; // 결과 출력
	//----------------------------------------------------------

	//포인터변수를 사용하려면, 변수명 왼쪽에 *이 와야한다.
	// *A
	const char* A = "alphabet";
	std::cout << *A << std::endl;//a

	//----------------------------------------------------------
	//정수형 배열의 특정인덱스10값을 다른 배열의 특정인덱스20에 대입
	//즉,배열에 배열대입이 아니다.
	int countInt = 10;
	int _arr[20];
	int arr = _arr[countInt];

	//배열대입은 오류문법이다
	int arr1[10];
	int arr2[10];
	//arr1 = arr2; // 에러 발생

	//----------------------------------------------------------
	//문자배열초기화
	const char* strings[] = { "Hello","World", ",","C++","123",nullptr };
	//문자배열 크기(갯수)
	int strCounts = 0;
	while (strings[strCounts] != nullptr)
	{
		strCounts++;
	}

	std::cout << "배열갯수는 : " << strCounts << std::endl;

	//xxxxxxxxxxxxxxxxxxxxxxxxxxx
	std::cout << "배열의 문자갯수 : " << StringsCount(strings[5]) << std::endl;

	for (int i = 0; i < strCounts; i++)
	{
		int newCharCount = StringsCount(strings[i]);
		std::cout << "\"" << strings[i] << "\"의 문자수" << newCharCount << std::endl;
	}




	//다른 방식(함수)사용
	int strCountSize = sizeof(strings) / sizeof(char);
	int strCountsizeArr = sizeof(strings) / sizeof(strings[0]);//이둘은 같다 

	//string 배열 초기화
	std::string stringS[] = { "Hello","World", ",","C++","123" };








	return 0;
}