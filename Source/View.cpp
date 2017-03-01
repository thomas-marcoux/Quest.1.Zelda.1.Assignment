#include "View.h"
#include "Object.h"

//Initializes View attributes
bool View::Initialize(InputDevice *i, GAME_FLT x, GAME_FLT y)
{
	iDevice = i;
	position.x = x;
	position.y = y;
	center.x = x + SCREEN_WIDTH_2;
	center.y = y + SCREEN_HEIGHT_2;
	angle = DEFAULT_VIEW_ANGLE;
	return true;
}

//Update view according to the game event
bool View::Update(GAME_FLT gameTime)
{
	switch (iDevice->GetEvent())
	{
	case GAME_UP:
		center.x -= VIEW_MOVEMENT * cos(angle);
		center.y -= VIEW_MOVEMENT * sin(angle);
		break;
	case GAME_DOWN:
		center.x += VIEW_MOVEMENT * cos(angle);
		center.y += VIEW_MOVEMENT * sin(angle);
		break;
	case GAME_LEFT:
		angle -= VIEW_ROTATION;
		break;
	case GAME_RIGHT:
		angle += VIEW_ROTATION;
		break;
	case GAME_TAB:
		switchPerspective();
		break;
	case GAME_ESC:
		return false;
	case GAME_QUIT:
		return false;
	}
	position.x = center.x - SCREEN_WIDTH_2;
	position.y = center.y - SCREEN_HEIGHT_2;
	return true;
}

//Update view with the coordinates of one of the objects
void View::switchPerspective()
{
	Object*	o = (*objects)[objectId].get();
	GAME_VEC p = o->getPosition();

	center.x = p.x;
	center.y = p.y;
	angle = -TO_RADIAN(o->getAngle());
	objectId++;
	objectId %= (*objects).size();
}
