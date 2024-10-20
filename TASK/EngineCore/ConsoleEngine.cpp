// ������
#include "ConsoleEngine.h"

// Platform
#include <Windows.h>

// User
#include "ConsoleWindow.h"
#include "Actor.h"

ConsoleEngine* ConsoleEngine::MainEngine = nullptr;

ConsoleEngine::ConsoleEngine()
{

}


// void ConsoleEngine::Start(void(*Ptr)(ConsoleEngine*))
void ConsoleEngine::Start(class UserInit* _Init)
{
	ConsoleEngine Engine;

	MainEngine = &Engine;

	Engine.BeginPlay();

	_Init->UserBeginPlay(&Engine);

	// �ݹ�
	// Ptr(&Engine);

	while (true == Engine.EngineActive)
	{
		Engine.Tick(); 
		Engine.Render();
		Engine.Release(); // ���������� ��� ������ ��������
		Sleep(250);
	}

	Engine.End();
}

void ConsoleEngine::End()
{
	if (nullptr != Window)
	{
		delete Window;
		Window = nullptr;
	}
}

void ConsoleEngine::BeginPlay()
{
	Window = new UConsoleWindow();
	Window->BeginPlay();
	Window->SetScreenSize({10, 10});
}

void ConsoleEngine::Tick()
{
	std::list<class AActor*>::iterator StartIter = AllActors.begin();
	std::list<class AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		AActor* CurActor = *StartIter;

		if (false == CurActor->IsTickable())
		{
			continue;
		}

		CurActor->Tick();
	}

}

void ConsoleEngine::Render()
{
	Window->Clear();

	ConsoleImage* BackBufferPtr = Window->GetBackBufferPtr();

	std::list<class AActor*>::iterator StartIter = AllActors.begin();
	std::list<class AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		AActor* CurActor = StartIter.operator*();

		if (false == CurActor->IsTickable())
		{
			continue;
		}

		CurActor->Render(BackBufferPtr);
	}

	Window->ScreenRender();
}

void ConsoleEngine::Release()
{
	// �����ʿ����� 

	std::list<class AActor*>::iterator StartIter = AllActors.begin();
	std::list<class AActor*>::iterator EndIter = AllActors.end();

	for (; StartIter != EndIter; )
	{
		AActor* CurActor = *StartIter;

		if (false == CurActor->IsDestory())
		{
			++StartIter;
			continue;
		}

		delete CurActor;
		StartIter = AllActors.erase(StartIter);
	}
}