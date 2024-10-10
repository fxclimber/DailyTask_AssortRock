#include "Object.h"
#include "Enums.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>

void UObject::SetName(const char* const _Name)
{
	//�̸� ����, ���
	if (static_cast<int>(Enums::MAXS::NAMEMAX) <=strlen(_Name))
	{
		MSGASSERT("�̸��� �ʹ� ���");
		return;
	}
	strcpy_s(Name, _Name);//�̸������� ���� ����
}


void UObject::TopLine()
{
	const char* Name = GetName();//�̸����
	printf_s("%s Status ", Name);//�̸����
	int NameLen = static_cast<int>(strlen(Name));//�̸�����
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
		printf_s("-");//�ٱ��� ��ŭ -�� ä���
	}
	printf_s("\n");
}