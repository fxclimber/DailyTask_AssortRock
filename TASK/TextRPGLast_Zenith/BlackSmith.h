#pragma once
#include "Zone.h"

class UBlackSmith : public UZone
{
public:
	void TryUpgrade();

	UZone* InPlayer() override;

	inline void setParent(class UZone* _ParentZone)
	{
		Connecting(_ParentZone);
	}

private:
};

