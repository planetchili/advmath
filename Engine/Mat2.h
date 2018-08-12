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
	_Mat2 operator*( const _Mat2& rhs ) const
	{
		_Mat2 out;
		for( int row_left = 0; row_left < 2; row_left++ )
		{
			for( int col_right = 0; col_right < 2; col_right++ )
			{
				out.cells[row_left][col_right] = (T)0;
				for( int i = 0; i < 2; i++ )
				{
					out.cells[row_left][col_right] += cells[row_left][i] * rhs.cells[i][col_right];
				}
			}
		}
		return out;
	}
	_Mat2& operator*=( const _Mat2& rhs )
	{
		return *this = *this * rhs;
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