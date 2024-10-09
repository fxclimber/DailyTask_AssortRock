#pragma once
#include "Actor.h"


class UPlayer : public AActor
{
public:
	UPlayer();

	inline int GetEquipAtt()const
	{

	}

	inline void SetEquipAtt(int _Value)
	{
		EquipAtt = _Value;
	}

	void StatusTextRender()override;

private:
	int EquipAtt = 0;
};

