#pragma once
#include "Actor.h"

class AMonster : public AActor
{
public:
	virtual void BeginPlay() = 0;
	void SetRandomGold(int _Min, int _Max);

private:

};
