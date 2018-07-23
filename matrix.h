#pragma once
#include <cassert>
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
	Matrix(int c) : column(c), data(c) {}
	T& at(int n)
	{
		assert(n < column && -1 < n);
		return data[n];
	}
	const T& at(int n) const
	{
		assert(n < column && -1 < n);
		return data[n];
	}
	int getcolumn() { return column; }
};

template <typename T>
class Matrix<T, 2>
{
private:
	int row;
	int column;
	PriLib::dyarray<T> data;
public:
	Matrix(int r, int c) : row(r), column(c), data(r * c) {}
	T& at(int x, int y)
	{
		assert(x < row && -1 < x && y < column && -1 < y);
		return data[x*column + y];
	}
	const T& at(int x, int y) const
	{
		assert(x < row && -1 < x && y < column && -1 < y);
		return data[x*column + y];
	}
	int getrow() { return row; }
	int getcolumn() { return column; }
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
	Matrix(int n, int r, int c) : no(n), row(r), column(c), data(n * r * c) {}
	T& at(int x, int y, int z)
	{
		assert(x < no && -1 < x && y < row && -1 < y && z < column && -1 < z);
		return data[x*(row * column) + y * column + z];
	}
	const T& at(int x, int y, int z) const
	{
		assert(x < no && -1 < x && y < row && -1 < y && z < column && -1 < z);
		return data[x*(row * column) + y*column + z];
	}
	int getno(){ return no; }
	int getrow(){ return row; }
	int getcolumn(){ return column; }
};