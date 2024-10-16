#pragma once
#include <EngineCore/Actor.h>

// ��� Ŭ������ �ڽ��� ���ο�
// �ڽŰ� ������ ������ Ŭ������ ���� ���� ������ �����
// Node�� �޸� ���¶�� �θ��ϴ�.

class ListNode : public AActor
{
public:
	FIntPoint PrevPos;
	// ����� ���� ����Ʈ �������
	ListNode* Prev = nullptr;
	ListNode* Next = nullptr;


	void push_back(ListNode* _Node);

	void NodeMode();

	ListNode* GetLastNode();

	FIntPoint GetPrevPos()
	{
		return PrevPos;
	}

	void TraceMove();

protected:
	
};

