#include "Blackbirdpch.h"
#include "EntryPoint.h"

#ifdef BlACKBIRD_PLATFORM_WINDOWS

int main(int argc, char** argv) {
	auto app = Blackbird::CreateApplication();
	app->Run();
	delete app;
}

#endif
