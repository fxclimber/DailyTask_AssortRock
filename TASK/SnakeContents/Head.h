#pragma once
#include "ListNode.h"

// Body�� ������ٰ� Ĩ�ô�.
// Body ���� ���� ���� ���� ���·� ����߿� ���ִ�.
// 1. �Դ´� => ���ڿ� �ܴ�.

// Food�� ������ٰ� Ĩ�ô�.
// 1. Food�� �Դ� ���� Food�� ������ �մϴ�.
// 2. Body�� �����. �׸��� �޾��ش�.



class Head : public ListNode
{
public:
	void BeginPlay() override;
	void Tick() override;

	void Move();
	void EatCheck();


	FIntPoint GetEmptyPoint();
};

