#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "math.h"
#include "wssumSftMs5.h"

double validSizes[3] = { QUARTER_CUBIC_METER, HALF_CUBIC_METER, ONE_CUBIC_METER };

struct Map populateMap()
{
	struct Map result = {
		//0	1  2  3  4  
		//A B  C  D  E 
		{
		{0, 0, 0, 0, 1},	//0
		{0, 1, 1, 0, 1},	//1
		{0, 0, 1, 0, 1},	//2
		{0, 0, 0, 0, 0},	//3
		{0, 1, 0, 1, 0},	//4
		//24
	},
	MAP_ROWS, MAP_COLS
	};
	return result;
}

/// <summary>
/// Program debugged
/// </summary>
/// <param name="map"></param>
/// <param name="route">
/// List of Changes:
/// -Will make sure that pathways are interconnected
/// -Will reject negative number coordinates
/// -Will now inspect that symbol is not out of range
/// </param>
/// <returns>
/// If any errors detected a error message will be printed
/// out and the map structure will be returned unmodified
/// to show no changes.</returns>
struct Map addRoute(const struct Map* map, const struct Route* route)
{
	int r, c;
	struct Map result = { {0}, 0 };
	int i = 0, a = 1, detector = 0;

	for (i = 0; i < route->numPoints; i++)
	{
		if ((route->points[i].col < 0) || (route->points[i].row < 0))
		{
			detector = 1;
			i = route->numPoints;
		}

		if ((route->points[a].col >= route->points[i].col + 2) || (route->points[a].row >= route->points[i].row + 2))
		{
			detector = 1;
			i = route->numPoints;
		}
		a++;
	}

	if (detector == 1)
	{
		printf("Out of range Coordinate on route detected. No negative coordinates allowed and all coordinates must be adjacent.\n");

		return *map;
	}

	if (route->routeSymbol == BLUE)
	{
		for (r = 0; r < map->numRows; r++)
		{
			for (c = 0; c < map->numCols; c++)
			{
				result.squares[r][c] = map->squares[r][c];
			}
		}
		result.numRows = map->numRows;
		result.numCols = map->numCols;

		for (r = 0; r < route->numPoints; r++)
		{
			result.squares[route->points[r].row][route->points[r].col] += route->routeSymbol;
		}
	}
	else if (route->routeSymbol == YELLOW)
	{
		for (r = 0; r < map->numRows; r++)
		{
			for (c = 0; c < map->numCols; c++)
			{
				result.squares[r][c] = map->squares[r][c];
			}
		}
		result.numRows = map->numRows;
		result.numCols = map->numCols;

		for (r = 0; r < route->numPoints; r++)
		{
			result.squares[route->points[r].row][route->points[r].col] += route->routeSymbol;
		}
	}
	else if (route->routeSymbol == GREEN)
	{
		for (r = 0; r < map->numRows; r++)
		{
			for (c = 0; c < map->numCols; c++)
			{
				result.squares[r][c] = map->squares[r][c];
			}
		}
		result.numRows = map->numRows;
		result.numCols = map->numCols;

		for (r = 0; r < route->numPoints; r++)
		{
			result.squares[route->points[r].row][route->points[r].col] += route->routeSymbol;
		}
	}
	else
	{
		printf("Invalid Symbol. Please change it to an equivalent of macros BLUE, YELLOW or GREEN.\n");
		return *map;
	}


	return result;
}
/**
* Add a point to a route
* @param route - the route to which the point should be added
* @param point - the point to add to the route.
*/
void addPtToRoute(struct Route* route, struct Point pt)
{
	route->points[route->numPoints].col = pt.col;
	route->points[route->numPoints].row = pt.row;
	route->numPoints++;
}

/**
* Add a point to a route
* @param route - the route to which the point should be added
* @param point - the point to add to the route.
*/
void addPointToRoute(struct Route* route, const int row, const int col)
{
	struct Point pt = { row, col };
	if (((pt.row >= route->points[route->numPoints - 1].row + 2) || (pt.col >= route->points[route->numPoints - 1].col + 2)))
	{
		printf("Invalid Coordinates. Not connected to current path.\n");
	}
	else if ((pt.row == route->points[route->numPoints - 1].row) && (pt.col == route->points[route->numPoints - 1].col))
	{
		printf("Invalid Coordinates. Already entered.\n");
	}
	else if ((pt.row == route->points[route->numPoints - 1].row + 1) || (pt.col == route->points[route->numPoints - 1].col + 1))
	{
		addPtToRoute(route, pt);
	}
}

/**
* Add a point to a route if it is not equal to another point.
* @param route - the route to which the point should be added
* @param row - the row of the point to add to the route.
* @param col - the column of the point to add to the route.
* @param notThis - the point will be added to the route ONLY if it is not equal to this point.
*/
void addPointToRouteIfNot(struct Route* route, const int row, const int col, const struct Point notThis)
{
	struct Point pt = { row, col };
	if (notThis.row != row && notThis.col != col)
	{
		addPtToRoute(route, pt);
	}

}

/**
* Compare two points for equality.
* @param p1 - the first point
* @param p2 - the second point
* @returns - true if p1 is equal to p2
*/
int eqPt(const struct Point p1, const struct Point p2)
{
	return p1.row == p2.row && p1.col == p2.col;
}

int main(void)
{
	const struct Point testPoint = { 5,5 };
	int tester = 0;
	struct Route expectedRoute =
	{
			{
			{0,0},
			{1,0},
			{2,0},{2,1},{2,2}

			},
				5, 2
	};
	struct Route testRoute =
	{
			{
			{0,0},
			{1,0},
			{2,0}

			},
				3, 2
	};
	addPointToRoute(&testRoute, 2, 1);
	addPointToRouteIfNot(&testRoute, 2, 2, testPoint);


	for (int i = 0; i < expectedRoute.numPoints; i++)
	{
		printf("{%d,%d}\n", expectedRoute.points[i].row, expectedRoute.points[i].col);
	}
	printf("\n\n");
	for (int i = 0; i < expectedRoute.numPoints; i++)
	{
		printf("{%d,%d}\n", testRoute.points[i].row, testRoute.points[i].col);
	}

	for (int i = 0; i < expectedRoute.numPoints; i++)
	{
		if (eqPt(testRoute.points[i], expectedRoute.points[i]))
		{
			tester++;
		}
	}
	printf("\n\n");

	printf("%d", tester);
	return 0;
}


