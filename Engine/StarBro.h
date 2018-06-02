#pragma once
#include "Entity.h"
#include "Star.h"

class StarBro : public Entity
{
public:
	StarBro( Vec2 pos,float radius,float innerRatio,int nFlares,Color c )
		:
		Entity( Star::Make( radius,radius * innerRatio,nFlares ),pos,c ),
		radius( radius )
	{}
	float GetRadius() const
	{
		return radius;
	}
private:
	float radius;
};