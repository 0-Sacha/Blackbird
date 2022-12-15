#pragma once

#include "Application/Application.h"

#ifdef SPITFIRE_PLATFORM_WINDOWS

extern Spitfire::Application* Spitfire::CreateApplication();

int main(int argc, char** argv) {
	auto app = Spitfire::CreateApplication();
	app->Run();
	delete app;
}

#endif
