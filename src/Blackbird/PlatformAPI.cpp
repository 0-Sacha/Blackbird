#include "PlatformAPI.h"

namespace Blackbird
{
	static PlatformAPI s_PlatformAPI;
	
	PlatformAPI& PlatformAPI::GetInstance()
	{
		return s_PlatformAPI;
	}
}
