#pragma once
#ifndef G5MS5_H
#define G5MS5_H

#define NUM_TRUCKS 3

#define MIN_WEIGHT 1
#define MAX_WEIGHT 1000

#define QUARTER_CUBIC_METER 0.25
#define HALF_CUBIC_METER 0.5
#define ONE_CUBIC_METER 1.0
#define NUM_VALID_SIZES 3

#define MAX_VOLUME 36
#define MAX_BOXES 20

// Define boolean type and values
#define true 1
#define false 0

extern double validSizes[3]; // = { QUARTER_CUBIC_METER, HALF_CUBIC_METER, ONE_CUBIC_METER };

#define MAP_ROWS 25
#define MAP_COLS 25
#define MAX_ROUTE 100
#define BLUE 2
#define GREEN 4
#define YELLOW 8
#define DIVERSION 16

/**
* A map is a 2D raster representation of a map with contents of the map encoded as numeric values.
*/
struct Map
{
	int squares[MAP_ROWS][MAP_COLS];
	int numRows;
	int numCols;
};

/**
* A point represents the row-column position of a square on a map.
*/
struct Point
{
	char row;
	char col;
};

/**
* A route is a collection of points that are adjacent to one another and constitute a path from the
* first point on the path to the last.
*/
struct Route
{
	struct Point points[MAX_ROUTE];
	int numPoints;
	char routeSymbol;
};


struct Box {
	int weight;
	double size;
	struct Point destination;
};

struct Truck
{
	struct Box boxes[MAX_BOXES];
	int numBoxes;
	double totalVolume;
	int totalWeight;
	double limitingFactor; // The limiting factor as a percentage (weight or volume)


};

struct Input
{
	struct Truck trucks[NUM_TRUCKS];
	int numTrucks;
	struct Map map;
};


int validateWeight(int weight);//combo C

int validateBoxSize(double boxSize);//combo C

int validateLocation(const struct Map* map, const struct Point* destination);//combo C

int validateVolume(const struct Truck* truck);//combo C

double calculateLimitingFactor(const struct Truck* truck);//combo C

struct Truck* findAvailableTruck(struct Input* input, int weight, double size, struct Point destination);//combo C

struct Map populateMap();//no need to integrate

int getNumRows(const struct Map* map);//no need to integrate

int getNumCols(const struct Map* map);//no need to integrate

void printMap(const struct Map* map, const int base1, const int alphaCols);//no need to integrate

struct Map addRoute(const struct Map* map, const struct Route* route);//combo B

void addPtToRoute(struct Route* route, struct Point pt);//combo B

void addPointToRouteIfNot(struct Route* route, const int row, const int col, const struct Point notThis);//combo B

void addPointToRoute(struct Route* route, const int row, const int col);//combo B

struct Route getBlueRoute();//no need to integrate

struct Route getGreenRoute();//no need to integrate

struct Route getYellowRoute();//no need to integrate

double distance(const struct Point* p1, const struct Point* p2);//combo A

struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest);//combo A

struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath);//combo A

int getClosestPoint(const struct Route* route, const struct Point pt);//combo A

int eqPt(const struct Point p1, const struct Point p2);//combo B

void getUserInput();//All
#endif
