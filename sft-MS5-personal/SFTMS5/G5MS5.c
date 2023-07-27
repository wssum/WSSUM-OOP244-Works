#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "math.h"
#include "G5MS5.h"

double validSizes[3] = { QUARTER_CUBIC_METER, HALF_CUBIC_METER, ONE_CUBIC_METER };

struct Map populateMap()
{
	struct Map result = {
		//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
		//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
		{
		{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
		{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
		{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
		{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
		{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
		{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
		},
		MAP_ROWS, MAP_COLS
	};
	return result;
}

/**
* Get the number of rows in a map.
* @param map - the map to query
* @returns - the number of rows in the map.
*/
int getNumRows(const struct Map* map)
{
	return map->numRows;
}

/**
* Get the number of columns in a map.
* @param map - the map to query
* @returns - the number of columns in the map.
*/
int getNumCols(const struct Map* map)
{
	return map->numCols;
}
/**
* Print the map usign the symbols:
* space = open space
* X = building
* B = blue route
* G = green route
* Y = yellow route
* . = B & G routes overlap
* - = B & Y routes overlap
* * = G & Y routes overlap
* + = B & G & Y routes overlap
* P = a shortest path or route from one point to another
* @param map - map to print
* @param base1 - if true print row indices from 1 up otherwise 0 up
* @param alphaCols - if true print col header as letters, otherwise numbers
*/
void printMap(const struct Map* map, const int base1, const int alphaCols)
{
	//              01234567890123456
	//              1248F
	char sym[] = { " XB?G?.?Y?-?*?+?P" };
	int r, c, rowMax;

	rowMax = map->numRows + base1;

	printf("%4s", " ");
	for (c = 0; c < map->numCols; c++)
	{
		if (alphaCols) printf("%c", 'A' + c);
		else printf("%d", c % 10);
	}
	printf("\n");
	printf("%4s", " ");
	for (c = 0; c < map->numCols; c++)
	{
		printf("-");
	}
	printf("\n");

	for (r = base1; r < rowMax; r++)
	{
		printf("%3d|", r);
		for (c = 0; c < map->numCols; c++)
		{
			printf("%c", sym[map->squares[r - base1][c]]);
		}
		printf("\n");
	}
}

struct Route getBlueRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},
			{5, 9},
			{6, 9},
			{7, 9},
			{8, 9},
			{9, 9},
			{10, 9},{10, 10},
			{11, 10},
			{12, 10},
			{13, 10},
			{14, 10},
			{15, 10},
			{16, 10},
			{17, 10},{17, 11},{17, 12},{17, 13},{17, 14},{17, 15},{17, 16},{17, 17},{17, 18},{17, 19},{17, 20},
				{17, 21},{17, 22},{17, 23},{17, 24},
		},
			42, BLUE
	};
	return result;
}

struct Route getGreenRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},{4, 10},{4, 11},
			{3, 11},
			{2, 11},
			{1, 11},
			{0, 11},{0, 12},{0, 13},{0, 14},{0, 15},{0, 16},{0, 17},{0, 18},{0, 19},
			{1, 19},
			{2, 19},
			{3, 19},
			{4, 19},
			{5, 19},
			{6, 19},
			{7, 19},
			{8, 19},
			{9, 19},{9, 20},{9, 21},{9, 22},{9, 23},{9, 24}

		},
			42, GREEN
	};
	return result;
}

struct Route getYellowRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3},
			{5, 3},
			{6, 3},
			{7, 3},
			{8, 3},
			{9, 3},{9, 2},{9, 1},
			{10, 1},
			{11, 1},
			{12, 1},
			{13, 1},
			{14, 1},
			{15, 1},
			{16, 1},
			{17, 1},
			{18, 1},
			{19, 1},{19, 2},{19, 3},{19, 4},{19, 5},{19, 6},{19, 7},{19, 8},{19, 9},{19, 10},{19, 11},{19, 12},
				{19, 13},{19, 14},{19, 15},{19, 16},{19, 17},{19, 18},{19, 19},{19, 20},{19, 21},{19, 22},{19, 23},{19, 24}
		},
			48, YELLOW
	};
	return result;
}
/**
* Add a route to a map using the indicated symbol.
* @param map - map to add route to
* @param route - the route to add to the map
* @returns a copy of the original map with the route added to it
*/
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
		route->numPoints++;
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
	if (notThis.row != row || notThis.col != col) addPtToRoute(route, pt);
}

/**
* Calculate the Euclidian distance between two points.
* @param p1 - the first point
* @param p2 - the second point
* @returns - the distance between p1 and p2.
*/
double distance(const struct Point* p1, const struct Point* p2)
{
	int deltaRow = p2->row - p1->row;
	int deltaCol = p2->col - p1->col;

	return sqrt((double)(deltaRow * deltaRow + deltaCol * deltaCol));
}
/**
* Calculate the shortest path between two points so that the path does not pass through buildings.
* @param map - the map showing the location of buildings.
* @param start - the point to start from
* @param dest - the point to go to
* @returns - the shortest path from start to dest. If there is no path, then a Route of zero length is returned.If start
* and dest are the same point, it also returns a Route of zero length.
*/
struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest)
{
	struct Route result = { {0,0}, 0, DIVERSION };
	struct Point last = { -1, -1 };
	struct Point current = start;
	struct Route possible = { {0,0},0,0 };
	int close = 0;

	while (!eqPt(current, dest) && close >= 0)
	{
		possible = getPossibleMoves(map, current, last);
		close = getClosestPoint(&possible, dest);
		if (close >= 0)
		{
			last = current;
			current = possible.points[close];
			addPtToRoute(&result, current);
		}
	}

	return result;
}

/**
* Calculate all adjacent squares to a given point so that the squares do not overpal a building and do not include the backpath.
* @param map - the map showing the location of buildings.
* @param p1 - the point to calculate possible moves for
* @param backpath - the previous point we visited on the path we travelled so we will exclude travelling backwards.
* @returns - a collection of adjacent points we could potentially move to.
*/
struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath)
{
	struct Route result = { {0,0}, 0, DIVERSION };

	if (p1.row > 0)
	{
		if (map->squares[p1.row - 1][p1.col] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col, backpath);	// square above
		if (p1.col > 0 && map->squares[p1.row - 1][p1.col - 1] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col - 1, backpath);	// top left
		if (p1.col < (map->numCols - 1) && map->squares[p1.row - 1][p1.col + 1] != 1) addPointToRouteIfNot(&result, p1.row - 1, p1.col + 1, backpath);	// top right
	}
	if (p1.col > 0 && map->squares[p1.row][p1.col - 1] != 1)addPointToRouteIfNot(&result, p1.row, p1.col - 1, backpath);	// left
	if (p1.col < (map->numCols - 1) && map->squares[p1.row][p1.col + 1] != 1)addPointToRouteIfNot(&result, p1.row, p1.col + 1, backpath);	// right
	if (p1.row < (map->numRows - 1))
	{
		if (map->squares[p1.row + 1][p1.col] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col, backpath);	// square below
		if (p1.col > 0 && map->squares[p1.row + 1][p1.col - 1] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col - 1, backpath);	// bot left
		if (p1.col < (map->numCols - 1) && map->squares[p1.row + 1][p1.col + 1] != 1) addPointToRouteIfNot(&result, p1.row + 1, p1.col + 1, backpath);	// top right
	}

	return result;
}

/**
* Calculates the Euclidian distance from every point in a route to a single point and returns the
* index of the point in the route which is closest to the point.
* @param route - the route to use to find the closest point
* @param pt - the point to to find the member of the route which is closest to this point
* @returns - the index of the closest point on the route to the point or -1 if the route is empty.
*/
int getClosestPoint(const struct Route* route, const struct Point pt)
{
	int i, closestIdx = -1;
	double closestDist = 999999.9, dist;

	for (i = 0; i < route->numPoints; i++)
	{
		dist = distance(&pt, &route->points[i]);
		if (dist < closestDist)
		{
			closestDist = dist;
			closestIdx = i;
		}
	}
	return closestIdx;
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
/*
 * Validates the weight value.
 * This function checks if the given weight value falls within the acceptable range.
 * @param weight - The weight value entered by the user to validate.
 * @returns 1 (True) if the weight is within the valid range [MIN_WEIGHT, MAX_WEIGHT], False otherwise.
 */
int validateWeight(int weight) {
	if (weight >= MIN_WEIGHT && weight <= MAX_WEIGHT)
	{
		return 1;
	}

	return 0;
}
/*
 * Validates the box size.
 * This function verifies if the provided box size is valid based on predefined valid sizes.
 * @param boxSize - The size of the box entered by the user to validate.
 * @returns 1 (True) if the box size is one of the valid sizes [QUARTER_CUBIC_METER, HALF_CUBIC_METER, ONE_CUBIC_METER], False otherwise.
 */
int validateBoxSize(double boxSize) {
	for (int i = 0; i < NUM_VALID_SIZES; i++) {
		if (boxSize == validSizes[i]) {
			return 1;
		}
	}
	return 0;
}
/*
 * Validates the volume of a truck.
 * @param truck - The truck structure containing the boxes.
 * @returns 1 (True) if the truck's volume is within the valid range, False otherwise.
 */
int validateVolume(const struct Truck* truck) {
	if (truck->totalVolume < MAX_VOLUME)
	{
		if (truck->totalVolume >= 0)
		{
			return 1;
		}

	}
	return 0;
}

/**
 * Calculates the limiting factor for a truck.
 * @param truck - The truck structure for which to calculate the limiting factor.
 * @return The limiting factor as a percentage (weight or volume).
 */
double calculateLimitingFactor(const struct Truck* truck) {
	double weightPercentage = (double)truck->totalWeight / MAX_WEIGHT;
	double volumePercentage = truck->totalVolume / MAX_VOLUME;

	double limitingFactor;
	if (weightPercentage > volumePercentage) {
		limitingFactor = weightPercentage;
	}
	else {
		limitingFactor = volumePercentage;
	}

	return limitingFactor * 100.0;
}

void getUserInput() {
	int weight;
	int value;
	double size;
	struct Point dest;
	char input[100];
	struct Map map = populateMap();

	printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
	fgets(input, sizeof(input), stdin); // Read input as a string
	value = sscanf(input, "%d %lf %2s %c", &weight, &size, dest.row, &dest.col);

	// Stops taking input when 0 0 x is entered.
	while (weight != 0 && size != 0.0 && strcmp(dest.row, "x") != 0) {
		// Extract values from the input using sscanf
		if (value == 4) {
			// Validate weight, size, and destination
			if (validateWeight(weight)) {
				if (validateSize(size)) {
					if (validateLocation(&map, &dest)) {
						printf("Weight is: %d\nSize: %.2lf\nDest: %s%c\n", weight, size, dest.row, dest.col);
					}
					else {
						printf("Invalid destination.\n");
					}
				}
				else {
					printf("Invalid size.\n");
				}
			}
			else {
				printf("Invalid weight (must be 1-1000 Kg.)\n");
			}
		}
		else {
			printf("Invalid input format. Please try again.\n");
		}
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
		fgets(input, sizeof(input), stdin); // Read input as a string
		value = sscanf(input, "%d %lf %2s %c", &weight, &size, dest.row, &dest.col);
	}
}



/*
 * Validates the location on the grid.
 * This function checks if the given destination point is a valid location within the provided map's boundaries.
 * @param map - The map structure representing the grid.
 * @param map - The map structure representing the grid.
 * @param destination - The destination point to validate.
 * @returns 1 (True) if the destination point is within the map's boundaries, False otherwise.
 */
int validateLocation(const struct Map* map, const struct Point* destination) {
	if (destination->col < 0 || destination->col > MAP_COLS || destination->row < 0 || destination->row > MAP_ROWS
		|| map->squares[destination->row][destination->col] == 0)
		return 0;
	return 1;
}

/*
 * Find an available truck for the shipment.
 * @param input - The input struct containing the map and trucks.
 * @param weight - The weight of the shipment in kilograms.
 * @param size - The size of the box required in cubic meters.
 * @param destination - The destination of the box as a Point (row, col).
 * @return - A pointer to the available truck, or NULL if no truck is available.
 */
struct Truck* findAvailableTruck(struct Input* input, int weight, double size, struct Point destination) {
	struct Truck* availableTruck = NULL;
	int minDistance = -1;

	for (int i = 0; i < input->numTrucks; i++) {
		struct Truck* truck = &input->trucks[i];

		if (truck->totalWeight < MAX_WEIGHT || truck->totalVolume < MAX_VOLUME) {

			struct Point truckPosition = truck->boxes[truck->numBoxes - 1].destination;

			double distanceToDestination = distance(&truckPosition, &destination);

			if (minDistance == -1 && distanceToDestination < minDistance) {
				minDistance = distanceToDestination;
				availableTruck = truck;
			}
			else if (distanceToDestination == minDistance) {
				double truck1SpaceLeft = MAX_VOLUME - truck->totalVolume;
				double truck2SpaceLeft = MAX_VOLUME - availableTruck->totalVolume;

				double truck1LimitingFactor = truck1SpaceLeft / MAX_VOLUME;
				double truck2LimitingFactor = truck2SpaceLeft / MAX_VOLUME;

				if (truck1LimitingFactor < truck2LimitingFactor) {
					availableTruck = truck;
				}
			}
		}
	}
	return availableTruck;
}

int main(void)
{
	struct Truck deliveryA = { {7,8}, 10,5.0, 100, 50.5 };


	validateVolume(&deliveryA);


	return 0;
}


