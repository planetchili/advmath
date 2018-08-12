#pragma once

#include "Graphics.h"
#include <vector>
#include "Vec2.h"

class Drawable
{
public:
	Drawable( const std::vector<Vec2>& model,Color c )
		:
		c( c ),
		model( &model )
	{}
	void ApplyTransformation( const Mat3& tranformation_in )
	{
		tranformation = tranformation_in * tranformation;
	}
	void Render( Graphics& gfx ) const
	{
		gfx.DrawClosedPolyline( *model,tranformation,c );
	}
private:
	Color c;
	const std::vector<Vec2>* model;
	Mat3 tranformation = Mat3::Identity();
};