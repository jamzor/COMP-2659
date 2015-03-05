#define GRID_WIDTH 10
#define GRID_HEIGHT 18

struct CellGrid {/*holds the array of grid cells containing the current state of the grid*/
	Cell[10][18];
};

struct Cell { /*holds information about a single position in the tetris grid*/
	bool isFull; /* has the cell been filled by the placement of a block or the presence of the current block*/
	bool isOwned;/* is the cell generically filled or is it owned by the current shape*/
};

struct Shape { /*holds the x and y positions of all cells pertaining to a single shape*/
	int x1;
	int y1;
	int x2;
	int y2;
	int x3;
	int y3;
	int x4;
	int y4;
};

bool lowerShape(Shape s){ /*method lets us know if we can lower the shape by one cell*/
	bool collision = false;
	
	int x = s->x1;
	int y = s->y1;

	return collision;
}

bool canLowerCell(int y){ /* method is a helper for lowerShape - tells us if a specific cell can move down one cell and still be in bounds*/
	int yTemp = y;
	if (++yTemp == GRID_HEIGHT)
		return false;
	return true;
}

