#pragma once
#include "Zone.h"
#include "StatusUnit.h"

class BlackSmith
{
public:
	// �ȳ־��ָ� ������ �ȵ�.
	//BlackSmith(UZone& _ParentZone)
	//	: ParentZone(_ParentZone)
	//{

	//}

	void InPlayer(class UPlayer& _Player/*, int& Result*/);

	inline void SetParent(class UZone* _ParentZone)
	{
		ParentZone = _ParentZone;
	}

	void Enhance(class UPlayer& _Player);

private:
	// class UZone& ParentZone;
	int Level = 1;
	class UZone* ParentZone = nullptr;
};

