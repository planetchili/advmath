#pragma once
#include "Entity.h"
#include "Star.h"

class Ball : public Entity
{
public:
	Ball( Vec2 pos,float radius,Vec2 vel,Color c = Colors::Red )
		:
		Entity( Star::Make( radius,radius,8 ),pos,c ),
		vel( vel )
	{}
	float GetRadius() const
	{
		return radius;
	}
	Vec2 GetVel() const
	{
		return vel;
	}
	void SetVel( const Vec2& vel_in )
	{
		vel = vel_in;
	}
	void Update( float dt )
	{
		TranslateBy( vel * dt );
	}
private:
	float radius;
	Vec2 vel;
};