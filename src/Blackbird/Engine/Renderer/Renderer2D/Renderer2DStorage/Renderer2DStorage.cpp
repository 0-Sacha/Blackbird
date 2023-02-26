#include "Renderer2DStorage.h"

namespace Blackbird::Renderer2DUtils
{

	void Renderer2DStorage::Init()
	{
		Quad2D.Init();
		Shaders.Init();
	}

	void Renderer2DStorage::Release()
	{
		Quad2D.Release();
		Shaders.Release();
	}

}
