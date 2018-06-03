#pragma once
#include "Entity.h"
#include "Star.h"
#include "RectF.h"

class StarBro : public Entity
{
public:
	StarBro( Vec2 pos,float radius,float innerRatio,int nFlares,Color c,float colorFreq,float colorPhase,
		float radiusFactorAmplitude,float radiusFactorFreq,float radiusFactorPhase )
		:
		Entity( Star::Make( radius,radius * innerRatio,nFlares ),pos,c ),
		radius( radius ),
		colorFreqFactor( colorFreq * 2.0f * 3.14159f ),
		colorPhase( colorPhase ),
		baseColor( c ),
		radiusFactorAmplitude( radiusFactorAmplitude ),
		radiusFactorFreqFactor( 2.0f * 3.14159f * radiusFactorFreq ),
		radiusFactorPhase( radiusFactorPhase )
	{}
	float GetRadius() const
	{
		return radius;
	}
	RectF GetBoudingRect() const
	{
		return RectF::FromCenter( GetPos(),GetRadius(),GetRadius() );
	}
	void Update( float dt )
	{
		time += dt;
		UpdateColor();
		UpdateScale();
	}
private:
	void UpdateColor()
	{
		Color c;
		const int offset = int( 127.0f * sin( colorFreqFactor * time + colorPhase ) ) + 128;
		c.SetR( std::min( baseColor.GetR() + offset,255 ) );
		c.SetG( std::min( baseColor.GetG() + offset,255 ) );
		c.SetB( std::min( baseColor.GetB() + offset,255 ) );
		SetColor( c );
	}
	void UpdateScale()
	{
		const float factor = radiusFactorAmplitude * sin( radiusFactorFreqFactor * time + radiusFactorPhase );
		SetScale( 1.0f + factor );
	}
private:
	float radius;
	Color baseColor;
	float colorFreqFactor;
	float colorPhase;
	float radiusFactorAmplitude;
	float radiusFactorFreqFactor;
	float radiusFactorPhase;
	float time;
};