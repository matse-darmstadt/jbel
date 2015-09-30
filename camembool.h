class Camembool
{
	friend class CamemboolTest;
public:
	
	
	/*
	 * 
	 * Constructor of the Camembool class
	 * Creates a Camembool object with a 3-dimensional array of booleans
	 * 
	 * @param: char size
	 * The edge length of the cube (i.e. number of array fields per dimension)
	 * unsigned char is used to limit the cube size to no more than 255³ segments
	 * 
	 * default value for each segment should be false (air)
	 * 
	 * @return: a new Camembool object (air/false cube)
	 * 
	 * 
	 */
	Camembool(unsigned char size);
	
	 /* Constructor with a given cube
	  *
	  */
	Camembool(bool*** cube);
	/*
	 * 
	 * Destructor of the Camembool class
	 * Deletes a Camembool object
	 * 
	 */
	~Camembool();
	
	/*
	 * 
	 * name: RipenFixedCube
	 * fills the cube in a fixed pattern of air and cheese segments
	 * 
	 * @param: void
	 * 
	 * @return: void
	 * 
	 */
	void RipenFixedCube();
	
	/*
	 *
	 * name: RipenRandomCube
	 * fills the cube with cheese and air in a random pattern
	 * probably not going to be used, though
	 * 
	 * @param: void
	 * @return: void
	 * 
	 *  
	 */
	void RipenRandomCube();
	
	/*
	 * name: RipenCustomCube
	 * lets the user input (somehow) the pattern of the cheese cube
	 * also probably not used
	 * 
	 * @param: unknown (void)
	 * @return: void
	 * 
	 * 
	 */
	void RipenCustomCube(bool*** cube);
	
	/*
	 * name: PourBoollon
	 * aside from being a bad pun on bouillon...
	 * initiates the search of a path through the cube (i.e. pouring water
	 * or in this case soup in the cube)
	 * 
	 * @param: char* coord
	 * a pointer on a char array (fixed length: 3) which represent the coordinates
	 * where the search starts
	 * NOTE: the z coordinate is always 0, since we'll be starting with the top layer
	 * 
	 * @return: void, I guess
	 * 
	 */
	void PourBoollon(char* coord);

private:


	/*
	 * the infamous cheese cube! a 3d bool array
	 * surprisingly, length in all dimensions is equal
	 *
	 */
	bool*** cube;
	
	/*
	 * The cubes edge length (number of fields per array dimension)
	 */
	char size;
	
	/*
	 * a char pointer to a n x 3 array
	 * (i.e. an array of coordinates)
	 * 
	 * stores the current path through the cube
	 * 
	 */
	char* path;
	
	/*
	 * just a constant array size for the fixed cube
	 * might as well be in there ...probably better anyway
	 * 
	 */
	const char FIXED_SIZE = 4;

	/*
	 * name: GetEntryPoint
	 * looks for the NEXT air segment in the top layer (z == 0)
	 * (remember char* path, that'll always at least hold the entry point and we can go from
	 *  there to find a new one, if the path leads nowhere)
	 * 
	 * @param: void
	 * 
	 * @return: pointer to a char array (size 3); coordinates, obviously
	 * 
	 */
	char* GetEntryPoint();
	
	/*
	 * name: CountPathSteps
	 * counts the number of steps taken so far
	 * length of the path (char[n][3])
	 * 
	 * @param: void
	 * 
	 * @return: int path.length
	 * 
	 */
	int CountPathSteps();
	
	/*
	 * name: CheckSegmentBelow
	 * determines what the segment exactly below the given coordinates is made of
	 * 
	 * @param: char* coord
	 * points to a char[3], set of coordinates
	 * 
	 * @return: bool
	 * only two choices here, true for cheese and false for air
	 * 
	 */
	bool CheckSegmentBelow(char* coord);
	
	/*
	 * name: GetNeighbours
	 * puts the 3x3x3 cube around given coordinates in a new bool array
	 * NOTE: beware the edge of the cube!
	 * 		 also, maybe only a 3x3x2 cube is needed, unless we allow water to flow up as well
	 * 		 (which makes sense btw)
	 * 		 also... we loose the origin coordinates, cube should be used right away, as long as
	 * 		 we know the center coordinates
	 * 
	 * @param: char* coord
	 * the coordinates of the center segment
	 * 
	 * @return: bool* neighbours
	 * pointer to the bool array
	 * 
	 */
	bool* GetNeighbours(char* coord);
	
	/*
	 * name: WalkPath
	 * follows a (stored) path to verify we're not breaking any rules along the way
	 * 
	 * @param: void
	 * 
	 * @return: bool validPath
	 * true for a valid path, false if something cheesy happened
	 * 
	 */
	bool WalkPath();
	
	/*
	 * name: VerifyStep
	 * same as above, only for a single step
	 * (might end up being redundant, depending on the WalkPath implementation
	 * 
	 * @param: char* curr, char* next
	 * two sets of coordinates, the current segment and the one we wish to go next
	 * 
	 * @return: bool validStep
	 * true if ok, false if not
	 */
	bool VerifyStep(char* curr, char* next);
	
	/*
	 * name: CheckBoundary
	 * takes a look at the neighbours of the segment to make sure
	 * we're not leaving the cube's boundaries
	 * 
	 * @param: char* coord
	 * the segment which's neighbours we want to check
	 * 
	 * @bool: return bool warning
	 * only a single return value for all neighbours
	 * true if all segments within the cube, false as soon as we hit a violation
	 * NOTE: might make more sense to know something about where the error came from (i.e. to the right, the bottom etc.)
	 * 		 again depends on the final implementation, sorry
	 */
	bool CheckBoundary(char* coord);
};
