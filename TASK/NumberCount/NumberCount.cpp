#include <iostream>

//숫자의 자릿수 세기
int NumberCount(int _Value)
{
	int Result = 0;
	while (_Value)
	{
		_Value /= 10;
		Result += 1;
	}
	return Result;
}




int main()
{
	int num = NumberCount(5475692311);

	return 0;


}