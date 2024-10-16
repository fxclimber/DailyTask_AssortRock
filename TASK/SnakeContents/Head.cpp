#include "Head.h"

// std
#include <conio.h>
#include <iostream>

// ���� 
#include <EngineBase/EngineMath.h>
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

// ������
#include "Body.h"


void Head::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');

	FIntPoint Size = ConsoleEngine::GetEngine().GetWindow()->GetBackBufferPtr()->GetImageSize();
	FIntPoint CenterPos = Size / 2;

	SetActorLocation(CenterPos);

}

void Head::Move()
{
	PrevPos = GetActorLocation();

	int Value = _kbhit();
	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
			AddActorLocation(FIntPoint::LEFT);
			TraceMove();
			break;
		case 'D':
		case 'd':
			AddActorLocation(FIntPoint::RIGHT);
			TraceMove();
			break;
		case 'W':
		case 'w':
			AddActorLocation(FIntPoint::UP);
			TraceMove();
			break;
		case 'S':
		case 's':
			AddActorLocation(FIntPoint::DOWN);
			TraceMove();
			break;
		default:
			break;
		}
	}


}

// �Լ� �ϳ����� ö���ϰ� �����ϸ� �ȴ�.
void Head::EatCheck()
{
	FIntPoint BodyPos = Body::CurEatBody->GetActorLocation();
	FIntPoint ThisPos = GetActorLocation();

	if (BodyPos == ThisPos)
	{
		push_back(Body::CurEatBody);

		ListNode* LastNode = this->GetLastNode();
		ListNode* PrevNode = LastNode->Prev;

		FIntPoint CurPos = PrevNode->GetPrevPos();
		LastNode->SetActorLocation(PrevNode->GetPrevPos());

		FIntPoint EmptyPoint = GetEmptyPoint();

		Body* NewBody = ConsoleEngine::GetEngine().SpawnActor<Body>();
		NewBody->SetActorLocation(EmptyPoint);
	}

	// body�� �ϳ��� ������ �Ѵ�.,
}

void Head::Tick()
{
	Super::Tick();
	// ö���ϰ� �̵��Ѵٶ�� �ൿ�� �Ѵ�.
	Move();
	EatCheck();
}

FIntPoint Head::GetEmptyPoint()
{
	// ����
	FIntPoint ScreenSize = ConsoleEngine::GetEngine().GetWindow()->GetScreenSize();

	std::vector<FIntPoint> AllRange;
	AllRange.reserve(ScreenSize.Y * ScreenSize.X);

	for (int y = 0; y < ScreenSize.Y; y++)
	{
		for (int x = 0; x < ScreenSize.X; x++)
		{
			AllRange.push_back({ x, y });
		}
	}


	std::vector<ListNode*> AllNode;
	ListNode* CurNode = this;
	while (nullptr != CurNode)
	{
		AllNode.push_back(CurNode);
		CurNode = CurNode->Next;
	}

	for (int i = 0; i < AllRange.size(); i++)
	{
		for (int j = 0; j < AllNode.size(); j++)
		{
			if (AllNode[j]->GetActorLocation() == AllRange[i])
			{
				AllRange[i].X = AllRange[i].Y = -1;
			}
		}
	}

	// �ϴ� �ִ�ġ�� �Ҵ�
	std::vector<FIntPoint> VoidPos;
	VoidPos.reserve(ScreenSize.Y * ScreenSize.X);

	for (int i = 0; i < AllRange.size(); i++)
	{
		if (-1 != AllRange[i].X)
		{
			VoidPos.push_back(AllRange[i]);
		}
	}

	srand(time(nullptr));

	int RandomIndex = rand() % VoidPos.size();

	return VoidPos[RandomIndex];
}