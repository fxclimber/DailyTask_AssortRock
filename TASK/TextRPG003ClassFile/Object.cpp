#include "Object.h"
#include "Enums.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>


void UObject::SetName(const char* const _Name)
{
    if (NAMELEN <= strlen(_Name))
    {
        MSGASSERT("이름이 너무 깁니다");
        return;
    }

    strcpy_s(Name, _Name);
}

void UObject::TopLine()
{
    const char* Name = GetName();
    printf_s("%s Status", Name);
    int NameLen = static_cast<int>(strlen(Name));
    int StatusLen = static_cast<int>(strlen("Status"));
    int nameLineCount = static_cast<int>(Enums::MAXS::LINECOUNT) - NameLen - StatusLen;

    for (int i = 0; i < nameLineCount; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
}

void UObject::BotLine()
{
    for (int i = 0; i < static_cast<int>(Enums::MAXS::LINECOUNT); i++)
    {
        printf_s("-");
    }
    printf_s("\n");
}

