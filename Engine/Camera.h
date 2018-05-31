#pragma once

#include "CoordinateTransformer.h"

class Camera
{
public:
	Camera( CoordinateTransformer& ct )
		:
		ct( ct )
	{}
	Vec2 GetPos() const
	{
		return pos;
	}
	void MoveBy( const Vec2& offset )
	{
		pos += offset;
	}
	void MoveTo( const Vec2& pos_in )
	{
		pos = pos_in;
	}
	void DrawClosedPolyline( std::vector<Vec2> poly,Color c )
	{
		for( auto& v : poly )
		{
			v -= pos;
		}
		ct.DrawClosedPolyline( std::move( poly ),c );
	}

private:
	Vec2 pos = {0.0f,0.0f};
	CoordinateTransformer& ct;
};