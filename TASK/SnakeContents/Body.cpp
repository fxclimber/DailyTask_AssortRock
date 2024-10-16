#include "Body.h"
#include <EngineCore/Renderer.h>
#include <EngineCore/ConsoleEngine.h>

Body* Body::CurEatBody = nullptr;

void Body::BeginPlay()
{
	Super::BeginPlay();

	Renderer* Render = CreateDefaultSubObject();
	Render->RenderImage.Create({ 1, 1 }, 'B');

	// ������ ����϶�°� �ƴϴ�.
	CurEatBody = this;
}

void Body::Tick()
{

}