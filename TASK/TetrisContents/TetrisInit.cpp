#include "TetrisInit.h"
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

#include "Block.h"

void TetrisInit::UserBeginPlay(ConsoleEngine* _MainEngine)
{
	// 시작을 합니다.
	_MainEngine->GetWindow()->SetScreenSize({10, 10});
	_MainEngine->SpawnActor<Block>();
}