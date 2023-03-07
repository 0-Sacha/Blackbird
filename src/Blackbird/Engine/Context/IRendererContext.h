#pragma once

namespace Blackbird
{
	class IRendererContext
	{
	public:
		virtual ~IRendererContext() = default;

	public:
		virtual void Init() = 0;
		virtual void Destroy() = 0;
		virtual void SwapBuffer() = 0;

	public:
		virtual void DisplayInfo() = 0;
	};
}
