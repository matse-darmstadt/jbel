/*
 * camemboolTest.cpp
 *
 *  Created on: 30.09.2015
 *      Author: bkra
 */

#include "camembool.h"
#include <iostream>
#include <functional>

using namespace std;
typedef unsigned char uchar;

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


void printTestSummary() {
	cout << "Number of tests: " << testCounter << "\t"
		<< "SUCCESSFUL tests: " << (testCounter - testFailCounter) << "\t"
		<< "FAILED tests: " << testFailCounter << endl;
}

class CamemboolTest {

public:

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

		Camembool c(cube);
	}



	void testCheckBoundary() {

		Camembool c = createCamembool(5, [](uchar x, uchar y, uchar z) {
			return true;
		});

		char segment[] = { 2, 2, 3 };
		cout << c.CheckBoundary(segment) << endl;
	}

	void testGetNeighbours() {

		Camembool c = createCamembool(5, [](uchar x, uchar y, uchar z) {
			return true;
		});

		char segment[] = { 0,0,0 };
		uchar* neighbourCoords;
		uchar numberOfNeighbours;
		c.GetNeighbours(segment, neighbourCoords, numberOfNeighbours);
<<<<<<< Updated upstream
		assertTrue(numberOfNeighbours == 0, "TestGetNeighbours");
=======
		assertTrue(numberOfNeighbours == 0, "Test::GetNeighbours::allCheeseCube");

		segment[0] = 2;
		segment[1] = 0;
		segment[2] = 2;
		c = getCubeWithHoleInMiddle(5);
		c.GetNeighbours(segment, neighbourCoords, numberOfNeighbours);
		assertTrue(numberOfNeighbours == 1, "Test::GetNeighbours::CubeWithHoleInMiddle");
>>>>>>> Stashed changes
	}

	void testWalkPath() {
		Camembool c = createCamembool(5, [](uchar x, uchar y, uchar z) {
					return true;
				});
	}

	void testGetEntryPoint() {
		Camembool c = createCamembool(5, [](uchar x, uchar y, uchar z) {
					return true;
				});
	}

	void testCountPathSteps() {
		Camembool c = createCamembool(5, [](uchar x, uchar y, uchar z) {
					return true;
				});
	}

	void testCheckSegmentBelow() {
		Camembool c = createCamembool(5, [](uchar x, uchar y, uchar z) {
					return true;
				});
	}

	void testVerifyStep() {
		Camembool c = createCamembool(5, [](uchar x, uchar y, uchar z) {
					return true;
				});
	}


};

int main() {
	CamemboolTest test;

	test.testCheckBoundary();

	test.testGetNeighbours();

	printTestSummary();
}

