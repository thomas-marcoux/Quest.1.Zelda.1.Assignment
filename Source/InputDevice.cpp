#include <iostream>
#include "InputDevice.h"

bool InputDevice::Initialize()
{
	event = std::make_unique<SDL_Event>();
	if (!event)
	{
		std::cout << "SDL Event could not initialize." << std::endl;
		return false;
	}
	return true;
}

GAME_EVENT InputDevice::GetEvent()
{
	while (SDL_PollEvent(event.get()))
	{
		if (event->type == SDL_QUIT)
		{
			return GAME_QUIT;
		}
		if (event->type == SDL_KEYDOWN)
		{
			return Translate();
		}
	}
	return GAME_NA;
}

//Translates the SDL_Event event to GAME_EVENT
GAME_EVENT InputDevice::Translate()
{
	switch (event->key.keysym.sym)
	{
	case SDLK_LEFT:
		return GAME_LEFT;
		break;
	case SDLK_RIGHT:
		return GAME_RIGHT;
		break;
	case SDLK_UP:
		return GAME_UP;
		break;
	case SDLK_DOWN:
		return GAME_DOWN;
		break;
	}
	return GAME_NA;
}