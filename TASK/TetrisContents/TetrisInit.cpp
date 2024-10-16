#include "TetrisInit.h"
#include <EngineCore/ConsoleEngine.h>
#include <EngineCore/ConsoleWindow.h>

#include "Block.h"

void TetrisInit::UserBeginPlay(ConsoleEngine* _MainEngine)
{
	// ������ �մϴ�.
	_MainEngine->GetWindow()->SetScreenSize({10, 10});
	_MainEngine->SpawnActor<Block>();
}