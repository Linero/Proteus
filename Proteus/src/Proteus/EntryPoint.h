#pragma once

#ifdef PROTEUS_PLATFORM_WIN

extern Proteus::Application* Proteus::CreateApplication();

int main(int argc, int** argv) {

	Proteus::Log::Init();
	PROTEUS_CORE_WARN("Initialized core  Log!");
	PROTEUS_INFO("Initialized client Log!");
	PROTEUS_INFO("Proteus Engine Loaded...");

	auto app = Proteus::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif // PROTEUS_PLATFORM_WIN
