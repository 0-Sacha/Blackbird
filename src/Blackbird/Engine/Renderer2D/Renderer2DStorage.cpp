#include "Renderer2DStorage.h"

#include "Renderer2D.h"

namespace Blackbird
{
	void Renderer2DStorage::Init(Renderer2D& renderer)
	{
		QuadManager.Init(renderer);
	}

	void Renderer2DStorage::Release()
	{
		QuadManager.Release();
	}
}
