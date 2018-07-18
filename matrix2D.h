#pragma once
#include <cassert>
#include "dyarray.h"

template <typename T>
class Matrix2D
{
private:
	int row;
	int column;
	PriLib::dyarray<T> data;
public:
	Matrix2D() :row( 3 ), column( 3 ), data ( 3 * 3 ) {}
	Matrix2D(int r, int c) :row( r ), column( c ), data ( r * c ) {}
	const T& at(int x, int y) const 
	{
		assert(x < row && y < column);
		return data[x*column + y];
	}
	~Matrix2D() {}
};

class Matrix2DInt
{
private:
	int row;
	int column;
	int *data;
public:
	Matrix2DInt() :row( 3 ), column( 3 ){
		data = new int[3 * 3]();
	}

	Matrix2DInt(int r, int c):row( r ),column( c ){
		data = new int[r*c]();
	}
	
	const int& at(int x, int y) const {
		assert(x < row && y < column);
		return *(data + x*column + y);
	}
};
