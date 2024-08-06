
#include <Windows.h>

#include "Core/ProjectHub.h"

int main(int argc, char** argv)
{
	Editor::ProjectHub hub;
	hub.run();
	
	return EXIT_SUCCESS;
}