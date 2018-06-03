#pragma once
#include "Ball.h"
#include <random>

class SpawnPoint
{
public:
	SpawnPoint( std::vector<Ball>& container,float radius,Vec2 pos,float minvx,float maxvx,float vy,float period )
		:
		pos( pos ),
		vxDist( minvx,maxvx ),
		period( period ),
		vy( vy ),
		container( container ),
		radius( radius )
	{}
	void Update( float dt )
	{
		time += dt;
		if( time >= period )
		{
			time -= period;
			container.emplace_back( pos,radius,Vec2{ vxDist( rng ),vy } );
		}
	}
private:
	std::mt19937 rng = std::mt19937( std::random_device{}() );
	std::uniform_real_distribution<float> vxDist;
	float period;
	float radius;
	Vec2 pos;
	float vy;
	float time = 0;
	std::vector<Ball>& container;
};