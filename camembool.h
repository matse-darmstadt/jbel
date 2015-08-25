class Camembool
{
public:
	// Constructor
	// will have to make sure the sides are cheese only
	Camembool(char dim);
	// Destructor (mouse breathing air and eating cheese?)
	~Camembool();
	// fills the cube with cheese and air in a fixed pattern
	void RipenFixedCube();
	// fills the cube with cheese and air in a random pattern
	// probably not going to be used
	void RipenRandomCube();
	// lets the user decide the pattern of the cheese cube
	// implementation/arguments unclear
	// probably not going to be used either
	void RipenCustomCube();
	// bad pun on bouillon
	// initiates the search of a path through the cube
	void PourBoollon(char* coord);

private:
	// the cheese cube: a 3d bool array
	// nxnxn (a cube, duh!)
	// or maybe leave dimensions optional in case of cheese slices? (i.e. 2d)
	bool cube [][][];
	// the dimension of the cube (i.e. length of the edges)
	// we're not gonna use cubes larger than 256, are we?
	char dimension;
	// the current path through the cube
	char* path;
	// constant value for fixed cube dimension
	const char FIXED_DIM = 4;

	// returns an array of 3 chars which represent a segment's coordinates
	// looks for the first air segment in the top layer (z == 0)
	char* GetEntryPoint(cube* cheese);
	// returns the number of steps taken so far (from path)
	int CountPathSteps();
	// determines what the segment exactly below the coordinates is made off
	bool CheckSegmentBelow(char* coord);
	// returns the 3x3 cube around the coordinates
	char* GetNeighbours(char* coord);
	// an array of coordinates (char[x][3]) that represents the path through the cube
	char* WalkPath();
	// verifies if the intended step is valid
	bool VerifyStep(char* curr, char* next);
	// takes a look at the neighbours of the segment to make sure
	// we're not leaving the cube's boundaries
	// (could be implemented in VerifyStep instead)
	bool CheckBoundary(char* coord);
};
