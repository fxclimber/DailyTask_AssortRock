#include "Object.h"
#include "Enums.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>

void UObject::SetName(const char* const _Name)
{
	//이름 길경우, 경고
	if (static_cast<int>(Enums::MAXS::NAMEMAX) <=strlen(_Name))
	{
		MSGASSERT("이름이 너무 길다");
		return;
	}
	strcpy_s(Name, _Name);//이름변수에 인자 복사
}


void UObject::TopLine()
{
	const char* Name = GetName();//이름얻기
	printf_s("%s Status ", Name);//이름출력
	int NameLen = static_cast<int>(strlen(Name));//이름길이
	int StatusRand = static_cast<int>(strlen("Status"));//?
	int nameLineCount = static_cast<int>(Enums::MAXS::LINECOUNT) - NameLen - StatusRand;

	for (int i = 0; i < nameLineCount ;i++)
	{
		printf_s("-");

	}printf_s("\n");
}

void UObject::BotLine()
{
	for (int i = 0; i < static_cast<int>(Enums::MAXS::LINECOUNT); i++)
	{
		printf_s("-");//줄길이 만큼 -로 채우기
	}
	printf_s("\n");
}
