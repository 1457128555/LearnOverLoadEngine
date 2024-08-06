
#include "Core/Application.h"

#include "Windows.h"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	Game::Application app;
	app.Run();

	return EXIT_SUCCESS;
}