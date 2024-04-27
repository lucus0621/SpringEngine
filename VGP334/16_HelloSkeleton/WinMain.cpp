#include <SpringEngine/Inc/SpringEngine.h>
#include "GameState.h"

int	WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	SpringEngine::App& mainApp = SpringEngine::MainApp();
	mainApp.AddState<GameState>("GameState");

	SpringEngine::AppConfig config;
	config.appName = L"Hello Skeleton";
	config.winWidth = 1280;
	config.winHeight = 780;
	config.debugDrawLimit = 100000;
	mainApp.Run(config);

	return(0);
}