/*
 * camemboolTest.cpp
 *
 *  Created on: 30.09.2015
 *      Author: bkra
 */

#include "camembool.h"
#include <iostream>
#include <functional>
#include <stdlib.h>

using namespace std;
typedef unsigned char uchar;


#define CHEESE true
#define AIR false

// asserts
int testCounter = 0;
int testFailCounter = 0;

void assertTrue(bool testValue, string testName) {
	cout << testName << ":\t" << (testValue ? "TRUE" : "FALSE") << endl;
	if (!testValue) {
		testFailCounter++;
	}
	testCounter++;
}

void assertEqual(bool testValue, bool expectedValue, string testName) {
	cout << testName << ":\t" << (testValue ? "TRUE" : "FALSE") << endl;
	if (testValue != expectedValue) {
		testFailCounter++;
	}
	testCounter++;
}


void printTestSummary() {
	cout <<"\n" << "Number of tests: " << testCounter << "\t"
		<< "SUCCESSFUL tests: " << (testCounter - testFailCounter) << "\t"
		<< "FAILED tests: " << testFailCounter << endl;
}

// TODO pull type of Camembool out of test methods and call those with the type to test
class CamemboolTest {


public:

	Camembool getAllCheese(uchar size) {

		bool*** cube = new bool**[size];
		for (uchar x = 0; x < size; x++) {
			cube[x] = new bool*[size];
			for (uchar y = 0; y < size; y++) {
				cube[x][y] = new bool[size];
				for (uchar z = 0; z < size; z++) {
					cube[x][y][z] = CHEESE;
				}
			}
		}
		return Camembool(cube, size);
	}

	Camembool getAllAir(uchar size) {

		bool*** cube = new bool**[size];
		for (uchar x = 0; x < size; x++) {
			cube[x] = new bool*[size];
			for (uchar y = 0; y < size; y++) {
				cube[x][y] = new bool[size];
				for (uchar z = 0; z < size; z++) {
					cube[x][y][z] = AIR;
				}
			}
		}
		return Camembool(cube, size);
	}

	Camembool getCubeWithHoleInMiddle(uchar size) {
		bool*** cube = new bool**[size];
		for (uchar x = 0; x < size; x++) {
			cube[x] = new bool*[size];
			for (uchar y = 0; y < size; y++) {
				cube[x][y] = new bool[size];
				for (uchar z = 0; z < size; z++) {
					if (x == size/2 && z == size/2)
						cube[x][y][z] = AIR;
					else
						cube[x][y][z] = CHEESE;
				}
			}
		}
		return Camembool(cube, size);
	}

	Camembool getRandomCube(uchar size) {
		bool*** cube = new bool**[size];
		for (uchar x = 0; x < size; x++) {
			cube[x] = new bool*[size];
			for (uchar y = 0; y < size; y++) {
				cube[x][y] = new bool[size];
				for (uchar z = 0; z < size; z++) {
					int r = rand();
					if (r % 2 == 0)
						cube[x][y][z] = AIR;
					else
						cube[x][y][z] = CHEESE;
				}
			}
		}
		return Camembool(cube, size);
	}
	Camembool createCamembool(unsigned char size,
								function<bool(uchar x, uchar y, uchar z)> cheeseGenerator) {

		bool*** cube = new bool**[size];
		for (uchar z = 0; z < size; z++) {
			cube[z] = new bool*[size];
			for (uchar y = 0; y < size; y++) {
				cube[z][y] = new bool[size];
				for (uchar x = 0; x < size; x++) {
					cube[z][y][x] = cheeseGenerator(x, y, z);
				}
			}
		}

		return Camembool(cube, size);
	}



	void testCheckBoundary() {

		Camembool c = getAllCheese(5);
		int numberOfValidSegments = 0;
		uchar segment[3];
		for (uchar x = -1 ; x <= c.size ; x++) {
			segment[0] = x;
			segment[1] = 0;
			segment[2] = 0;
			if (c.CheckBoundary(segment))
				numberOfValidSegments++;
		}

		assertTrue(numberOfValidSegments == 5, "Test:checkBoundary::allCheeseCube");

		c = getAllAir(5);
		numberOfValidSegments = 0;
		// 0xFF
		segment[0] = -1;
		segment[1] = -1;
		segment[2] = -1;
		assertTrue(c.CheckBoundary(segment) == false, "Test::checkBoundary::allAir::invalidPoint");

		segment[0] = 3;
		segment[1] = 2;
		segment[2] = 1;
		assertTrue(c.CheckBoundary(segment) == true, "Test::checkBoundary::allAir::validPoint");

	}

	void testGetNeighbours() {

		Camembool c = getAllCheese(5);

		uchar segment[] = { 0,0,0 };
		uchar* neighbourCoords;
		uchar numberOfNeighbours;
		c.GetNeighbours(segment, neighbourCoords, numberOfNeighbours);
		assertTrue(numberOfNeighbours == 0, "Test::GetNeighbours::allCheeseCube");

		c = getAllAir(5);
		segment[0] = 2;
		segment[1] = 2;
		segment[2] = 2;
		c.GetNeighbours(segment, neighbourCoords, numberOfNeighbours);
		assertTrue(numberOfNeighbours == 6, "Test::GetNeighbours::allAirCube");

		segment[0] = 2;
		segment[1] = 0;
		segment[2] = 2;
		c = getCubeWithHoleInMiddle(5);
		c.GetNeighbours(segment, neighbourCoords, numberOfNeighbours);
		assertTrue(numberOfNeighbours == 1, "Test::GetNeighbours::CubeWithHoleInMiddle:numberOfNeighbours");
		assertTrue(neighbourCoords[0] == 2 && neighbourCoords[1] == 1 && neighbourCoords[2] == 2,
					"Test::GetNeighbours::CubeWithHoleInMiddle:neighbourCoords");
	}

	void testWalkPath() {
		Camembool c = getAllCheese(5);
		assertTrue(!c.WalkPath(), "Test::walkPath::allCheeseCube");

		c = getAllAir(5);
		assertTrue(c.WalkPath(), "Test::walkPath::allAirCube");

		c = getCubeWithHoleInMiddle(5);
		assertTrue(c.WalkPath(), "Test::walkPath::CubeWithHileInMiddle");
	}

	void testGetEntryPoint() {

		Camembool c = getAllCheese(5);
		assertTrue(c.GetEntryPoint() == nullptr, "Test::GetEntryPoint::allCheeseCube::null");

		c = getAllAir(5);
		assertTrue(c.GetEntryPoint() != nullptr, "Test::GetEntryPoint::allAirCube");

		c = getCubeWithHoleInMiddle(5);
		uchar* result = c.GetEntryPoint();
		uchar expectedCoords[] = {2,0,2};
		bool match = true;
		for (uchar i = 0 ; i < 3 ; i++) {
			if (result[i] != expectedCoords[i])
				match = false;
		}
		assertTrue(match, "Test::GetEntryPoint::CubeWithHoleInMiddle::singleValidPoint");
	}

	void testCountPathSteps() {
		Camembool c = getAllCheese(5);
		unsigned int numberOfSteps = c.CountPathSteps();
		assertTrue(numberOfSteps == 0, "Test::CountPathSteps::allCheeseCube");

		c = getAllAir(5);
		numberOfSteps = c.CountPathSteps();
		assertTrue(numberOfSteps == 5, "Test::CountPathSteps::allCheeseCube");

		c = getCubeWithHoleInMiddle(5);
		numberOfSteps = c.CountPathSteps();
		assertTrue(numberOfSteps == 5, "Test::CountPathSteps::allCheeseCube");
	}

	void testCheckSegmentBelow() {

		Camembool c = getAllCheese(5);
		uchar segment[] = {0,0,0};
		bool belowSegmentType = c.CheckSegmentBelow(segment);
		assertTrue(belowSegmentType == CHEESE, "Test::CheckSegmentBelow::allCheeseCube");

		c = getCubeWithHoleInMiddle(5);
		segment[0] = 2;
		segment[0] = 0;
		segment[0] = 2;
		belowSegmentType = c.CheckSegmentBelow(segment);
		assertTrue(belowSegmentType == AIR, "Test::CheckSegmentBelow::allCheeseCube");

	}

	void testVerifyStep() {
		Camembool c = getAllCheese(5);

	}


};

int main() {
	CamemboolTest test;

	test.testCheckBoundary();
	test.testGetNeighbours();
	test.testWalkPath();
	test.testGetEntryPoint();
	test.testCountPathSteps();
	test.testCheckSegmentBelow();
	test.testVerifyStep();




	printTestSummary();
}

