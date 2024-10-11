#include "Player.h"
#include <conio.h>
#include "Enums.h"
#include "ConsoleEngine.h"
#include <iostream>

void Player::BeginPlay()
{
	PlayerImage.Create({ 1, 1 }, '@');
}

void Player::Tick()
{
	int XX = ConsoleEngine::Window.GetBackBufferPtr()->GetImageSizeX();
	int YY = ConsoleEngine::Window.GetBackBufferPtr()->GetImageSizeY();

	int Value = _kbhit();
	Enums::GAMEDIR Dir = Enums::GAMEDIR::NONE;

	if (Value != 0)
	{
		int Select = _getch();

		switch (Select)
		{
		case 'A':
		case 'a':
		{
			if (Pos.X > 0)
			{
				Dir = Enums::GAMEDIR::LEFT;
				Pos += FIntPoint::LEFT;
			}
			break;
		}
		case 'D':
		case 'd':
			if (Pos.X < XX)
			{
				Dir = Enums::GAMEDIR::RIGHT;
				Pos += FIntPoint::RIGHT;
			}
			break;
		case 'W':
		case 'w':
			if (Pos.Y > 0)
			{
				Dir = Enums::GAMEDIR::UP;
				Pos += FIntPoint::UP;
			}
			break;
		case 'S':
		case 's':
			if (Pos.Y < YY)
			{
				Dir = Enums::GAMEDIR::DOWN;
				Pos += FIntPoint::DOWN;
			}
			break;
		default:
			break;
		}
	}



}

void Player::Render(ConsoleImage* _BackBuffer)
{
	// delete _BackBuffer;
	_BackBuffer->Copy(Pos, PlayerImage);
}

void Player::SetActorLocation(FIntPoint _Pos)
{
	Pos = _Pos;
}