#include "ConsoleEngine.h"
#include <Windows.h>
#include "GlobalValue.h"

//static 전역이므로, 구현부에서 초기화
ConsoleEngine* ConsoleEngine::MainEngine = nullptr;

FIntPoint ConsoleEngine::WindowSize;
UConsoleWindow ConsoleEngine::Window;

ConsoleEngine::ConsoleEngine()
{

}

void ConsoleEngine::Start()
{
	ConsoleEngine Engine;
	MainEngine = &Engine;

	Engine.BeginPlay();

	while (true)
	{
		Engine.Tick();
		Engine.Render();
		// 프로그램 250
		// 1000이 1초입니다.
		Sleep(250);
	}
	
}

void ConsoleEngine::BeginPlay()
{
	Window.BeginPlay();

	WindowSize.X = 20;
	WindowSize.Y = 10;

	GlobalValue::WindowPtr = &Window;

	Window.SetScreenSize(WindowSize);

	MainPlayer.BeginPlay();
}

void ConsoleEngine::Tick()
{
	MainPlayer.Tick();
}

void ConsoleEngine::Render()
{
	Window.Clear();

	ConsoleImage* BackBufferPtr = Window.GetBackBufferPtr();
	MainPlayer.Render(BackBufferPtr);

	Window.ScreenRender();
}