#pragma once
#include "Actor.h"


class APlayer : public AActor
{
public:
	APlayer();

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

