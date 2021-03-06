#ifndef PHYSICSDEVICE_H
#define PHYSICSDEVICE_H

#include "Box2D/Box2D.h"
#include "Definitions.h"

class Object;

class PhysicsDevice
{
public:
	PhysicsDevice(GAME_VEC const&);
	~PhysicsDevice();
	bool Initialize();
	bool Update(float dt);
	bool CreateFixture(Object*, GAME_OBJECTFACTORY_INITIALIZERS const&);
	//Setters
	bool SetTransform(Object* object, GAME_VEC position, GAME_FLT angle);
	bool SetLinearVelocity(Object* object, GAME_VEC linearVelociy);
	bool SetAngularVelocity(Object* object, GAME_FLT angularVelocity);
	bool SetTorque(Object* object, GAME_FLT torque);
	bool SetLinearImpulse(Object* object, GAME_VEC forceVec, GAME_VEC forceCenter);
	bool SetStatic(Object* object);
	bool SetStopPhysics(Object* object);
	bool SetAngle(Object* object, GAME_FLT angle);
	//Getters
	GAME_FLT GetAngularVelocity(Object* object);
	GAME_VEC GetPosition(Object* object);
	GAME_FLT GetAngle(Object* object);
	GAME_VEC GetVelocity(Object* object);
	GAME_VEC GetLinearVelocity(Object* object);
	b2World* getWorld() { return world.get(); }
	//Joints
	bool createDistanceJoint(Object* object1, Object* object2, GAME_FLT maxDistance, GAME_VEC anchor1, GAME_VEC anchor2);
	bool createDistanceJoint(Object* object1, Object* object2, GAME_FLT maxDistance);
	bool createRopeJoint(Object* object1, Object* object2, GAME_FLT maxDistance, GAME_VEC anchor1, GAME_VEC anchor2, bool collide);
	bool createRopeJoint(Object* object1, Object* object2, GAME_FLT maxDistance, bool collide);
	bool createRevolvingJoint(Object* object1, Object* object2, bool collide, GAME_VEC anchor1, GAME_VEC anchor2, GAME_FLT referenceAngle,
		bool enableLimit, GAME_FLT lowerAngle, GAME_FLT upperAngle, bool enableMotor, GAME_FLT motorSpeed, GAME_FLT maxMotorTorque);
	bool createRevolvingJoint(Object* object1, Object* object2, GAME_VEC anchor1, GAME_VEC anchor2);
	bool createRevolvingJoint(Object * object1, Object * object2);
	//Destructors
	bool DestroyJoint(Object* object);
	bool DestroyJoint(b2Body* body);
	bool RemoveObject(Object* object);

private:
	b2Body* FindBody(Object*);
	b2Vec2 GV2PV(GAME_VEC gv);
	GAME_VEC PV2GV(b2Vec2 pv);
	inline float PW2RW(GAME_FLT x) { return x * fPRV; }
	inline float RW2PW(GAME_FLT x) { return x / fPRV; }
	inline float RW2PW(GAME_INT x) { return (float)x / fPRV; }
	GAME_VEC AlignCenters(Object* object);	
	
private:
	std::unique_ptr<b2World>	world;
	const b2Vec2	gravity;
};

#endif // !PHYSICSDEVICE_H
