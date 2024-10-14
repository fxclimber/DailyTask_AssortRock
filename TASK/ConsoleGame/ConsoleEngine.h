#pragma once
#include "ConsoleWindow.h"
#include "Player.h"

class ConsoleEngine
{
	// void Update(); // 움직인다.
	// void Move(); // 움직인다.
public:
	static void Start();

	static FIntPoint GetWindowsize()
	{
		return WindowSize;
	}

	static UConsoleWindow& GetWindow()
	{
		return Window;
	}
	static ConsoleEngine& GetEngine()
	{
		return *MainEngine;
	}

	Player& GetPlayer()
	{
		return MainPlayer;
	}

private:
	//생성자를 막음으로, 자신이 만드는것외에 외부에서 생성못한->싱글톤 
	ConsoleEngine();

	static FIntPoint WindowSize;
	static UConsoleWindow Window;
	//자신의 스태틱포인터,스태틱게터함수로, 외부접근을 허용한다.
	static ConsoleEngine* MainEngine;




	Player MainPlayer;




	// 2번 실행되지 않습니다.
	void BeginPlay(); // 움직인다.

	void Tick(); // 움직인다.
	void Render(); // 그린다.
};

