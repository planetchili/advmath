#pragma once
#include "Entity.h"
#include "Star.h"
#include "RectF.h"

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
	RectF GetBoudingRect() const
	{
		return RectF::FromCenter( GetPos(),GetRadius(),GetRadius() );
	}
private:
	float radius;
};