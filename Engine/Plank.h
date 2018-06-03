#pragma once
#include "Entity.h"
#include <algorithm>

class Plank : public Entity
{
public:
	Plank( Vec2 anchor,float freeX,float minFreeY,float maxFreeY,float fatness = 8.0f,Color c = Colors::Yellow )
		:
		Entity( {},anchor,c ),
		minFreeYModel( minFreeY - anchor.y ),
		maxFreeYModel( maxFreeY - anchor.y ),
		freePtModel( freeX - anchor.x,minFreeYModel ),
		fatness( fatness )
	{}
	// generate the model dynamically on demand before returning the Drawable
	Drawable GetDrawable()
	{
		std::vector<Vec2> model;
		model.reserve( 4 );
		model.emplace_back( 0.0f,0.0f );
		model.push_back( freePtModel );
		model.push_back( freePtModel + Vec2{ 0.0f,fatness } );
		model.emplace_back( 0.0f,fatness );
		SetModel( std::move( model ) );
		return Entity::GetDrawable();
	}
	Vec2 GetFreePt() const
	{
		return freePtModel + GetPos();
	}
	void SetFreeY( float freeY_in )
	{
		freePtModel.y = std::clamp( freeY_in - GetPos().y,minFreeYModel,maxFreeYModel );
	}
	void MoveFreeY( float deltaY )
	{
		SetFreeY( GetFreePt().y + deltaY );
	}
	Vec2 GetPlankSurfaceVector() const
	{
		return -freePtModel;
	}
private:
	float minFreeYModel;
	float maxFreeYModel;
	Vec2 freePtModel;
	float fatness;
};