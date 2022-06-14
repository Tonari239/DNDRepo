#ifndef __GRID_H
#define __GRID_H

#include <vector>
#include "cell.h"

using namespace std;

class Grid
{
	int mRows;
	int mCols;
	Cell** mGrid;

	void free();
	void copyFrom(const Grid& other);
	void populateGrid();
public:
	Grid() = default;
	Grid(int rows, int cols);
	~Grid();
	Grid(const Grid& other);
	Grid& operator=(const Grid& other);

	void setCellValue(int row, int col, char value);
	const Cell& getCell(int row, int col) const;
	void markCellAsVisited(int row, int col);
	void print() const;

	int getRows() const;
	int getCols() const;

	friend ostream& operator<<(ostream& out, const Grid& grid);
	friend istream& operator>>(istream& out, Grid& grid);
};


#endif