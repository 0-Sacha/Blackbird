#pragma once

#include "Application/Application.h"

#ifdef BlACKBIRD_PLATFORM_WINDOWS

extern Blackbird::Application* Blackbird::CreateApplication();

int main(int argc, char** argv) {
	auto app = Blackbird::CreateApplication();
	app->Run();
	delete app;
}

#endif
