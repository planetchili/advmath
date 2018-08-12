#pragma once

#include "Vec2.h"

template<typename T>
class _Mat2
{
public:
	_Vec2<T> operator*( const _Vec2<T>& v ) const
	{
		_Vec2<T> vout;
		vout.x = cells[0][0] * v.x + cells[0][1] * v.y;
		vout.y = cells[1][0] * v.x + cells[1][1] * v.y;
		return vout;
	}
	static _Mat2 Scale( T factor )
	{
		return {
			factor,	(T)0,
			(T)0,	factor
		};
	}
	static _Mat2 Identity()
	{
		return Scale( (T)1 );
	}
	static _Mat2 FlipY()
	{
		return {
			(T)1,	(T)0,
			(T)0,	(T)-1
		};
	}
	static _Mat2 Rotation( T theta)
	{
		const auto cost = std::cos( theta );
		const auto sint = std::sin( theta );
		return {
			cost,	-sint,
			sint,	cost
		};
	}
public:
	// [row][col]
	T cells[2][2];
};

using Mat2 = _Mat2<float>;
using Mad2 = _Mat2<double>;