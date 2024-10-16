#include "Block.h"
#include <EngineCore/Renderer.h>
#include <conio.h>
#include "EngineCore/ConsoleWindow.h"

void Block::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, '@');
}

void Block::Tick()
{
	Super::Tick();


	FIntPoint restPos = GetActorLocation();

	if (GetActorLocation().Y == 9)
	{
		SetActorLocation(FIntPoint(restPos.X+1, 0));
		restPos.X += 1;
	}
	else
	{
	AddActorLocation(FIntPoint::DOWN);

	}



	//int Value = _kbhit();
	//if (Value != 0)
	//{
	//	int Select = _getch();

	//	switch (Select)
	//	{
	//	case 'A':
	//	case 'a':
	//		AddActorLocation(FIntPoint::LEFT);
	//		break;
	//	case 'D':
	//	case 'd':
	//		AddActorLocation(FIntPoint::RIGHT);
	//		break;
	//	case 'W':
	//	case 'w':
	//		AddActorLocation(FIntPoint::UP);
	//		break;
	//	case 'S':
	//	case 's':
	//		AddActorLocation(FIntPoint::DOWN);
	//		break;
	//	default:
	//		break;
	//	}

	//}


}