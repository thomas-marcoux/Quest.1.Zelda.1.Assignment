#ifndef TIMEDLIFECOMPONENT_H
#define TIMEDLIFECOMPONENT_H

#include "Component.h"

//Decreases health until Object death
class TimedLifeComponent : public Component
{
public:
	TimedLifeComponent(std::unique_ptr<Object> const&);
	~TimedLifeComponent() {}
	bool Initialize(GAME_OBJECTFACTORY_INITIALIZERS const& initializers);
	std::unique_ptr<Object> Update(GAME_FLT);
	bool Finish();
	GAME_INT	getTimer() { return _health; }

private:
	GAME_INT _health;
	GAME_INT _decrement;
};

#endif // !TIMEDLIFECOMPONENT_H
