#include "EngineAPI.h"

namespace Blackbird
{
	static EngineAPI s_EngineAPI;
	
	EngineAPI& EngineAPI::GetInstance()
	{
		return s_EngineAPI;
	}
}
