#pragma once
#include <cassert>
#include "matrix2D.h"
#include "dyarray.h"

template <typename T,int N>
class Matrix{};

template <typename T>
class Matrix<T, 1>
{
private:
	int column;
	PriLib::dyarray<T> data;
public:
	Matrix() :column(3), data(3) {}
	Matrix(int c) :column(c), data(c) {}
	const T& at(int n) const
	{
		assert(n < column);
		return data[n];
	}
	~Matrix() {}
};

template <typename T>
//using Matrix<T, 2> = Matrix2D<T>
class Matrix<T, 2>
{
private:
	int row;
	int column;
	PriLib::dyarray<T> data;
public:
	Matrix() :row(3), column(3), data(3 * 3) {}
	Matrix(int r, int c) :row(r), column(c), data(r * c) {}
	const T& at(int x, int y) const
	{
		assert(x < row && y < column);
		return data[x*column + y];
	}
	~Matrix() {}
};

template <typename T>
class Matrix<T,3>
{
private:
	int no;
	int row;
	int column;
	PriLib::dyarray<T> data;
public:
	Matrix() :no(2), row(2), column(2), data(2 * 2 * 2){}
	Matrix(int n, int r, int c) :no(n), row(r), column(c), data(n * r * c) {}
	const T& at(int x, int y, int z) const
	{
		assert(x < no && y < row && z < column);
		return data[x*(row * column) + y*column + z];
	}
	~Matrix() {}
};