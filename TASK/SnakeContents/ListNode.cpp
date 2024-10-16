#include "ListNode.h"


// ����Լ�
void ListNode::push_back(ListNode* _Node)
{
	// this => Head
	// _Node => Body

	ListNode* LastNode = this;

	while (nullptr != LastNode->Next)
	{
		LastNode = LastNode->Next;
	}

	if (nullptr == LastNode->Next)
	{
		LastNode->Next = _Node;
		_Node->Prev = LastNode;
		return;
	}

	int a = 0;
}

void ListNode::NodeMode()
{
	if (nullptr != Next)
	{
		Next->SetActorLocation(PrevPos);
	}
	
}

// Ư�� �Լ� �ȿ���
// �ڽ��� �ٽ��ѹ� ȣ���ϴ� �Լ��� ����Լ���� �Ѵٰ� �߽��ϴ�.
ListNode* ListNode::GetLastNode()
{
	// this => Head
	if (nullptr == Next)
	{
		return this;
	}

	// ���� LastNode�� �ƴϴ�.
	return Next->GetLastNode();
}

void ListNode::TraceMove()
{
	if (nullptr == Next)
	{
		return;
	}

	// ���� ���� �̵��� �Ϸ��� ������ �� ��ġ�� ����� �����Ѵ�.
	Next->PrevPos = Next->GetActorLocation();
	Next->SetActorLocation(PrevPos);
	return Next->TraceMove();
}