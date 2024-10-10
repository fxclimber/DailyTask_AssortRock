#pragma once
#include "Enums.h"


// 속성 : 이름
// 기능 : 이름짓기, 이름얻기, 정보 위쪽, 정보 아래쪽

class UObject
{
public:
	void SetName(const char* const _Name);
	inline const char* GetName()
	{
		return Name;
	}

	void TopLine();
	void BotLine();

private:
	char Name[static_cast<int>(Enums::MAXS::NAMEMAX)] = {0,};
};

