#pragma once
#include <cmath>
#include "Vec2.h"

template<typename T>
auto sq( T x )
{
	return x * x;
}

template<typename T>
T DistancePointLine( const _Vec2<T>& p0,const _Vec2<T>& p1,const _Vec2<T>& q )
{
	const T a = p0.y - p1.y;
	const T b = p1.x - p0.x;
	const T c = p0.x * p1.y - p1.x * p0.y;

	return std::abs( a * q.x + b * q.y + c ) / std::sqrt( sq( a ) + sq( b ) );
}