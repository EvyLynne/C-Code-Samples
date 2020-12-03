The charGrid class are container objects that hold properties of the text grids used by URI
Associate Professor Jean-Yves Herve' in CSC 412.  An open file stream can be passed to the constructor which
will unpack the file contents and set up the object.  This is written to process integer values, but
can easily be modified for doubles or floats.

This class provides support for files of these sturctures:

13 15
1 6 7 8 9 0 3 4 2 4 6 7 1 6 3
4 5 6 1 2 4 0 9 6 7 3 2 1 3 4
2 4 5 7 8 9 0 2 1 4 2 3 4 1 3
5 1 3 2 2 5 6 8 9 0 2 3 4 7 8
9 4 4 5 6 7 9 1 2 8 3 6 7 8 2
5 6 7 8 9 1 2 3 4 3 8 2 0 3 0
6 8 9 1 5 2 8 4 9 3 6 7 6 7 2
5 6 8 9 2 4 6 9 2 5 7 8 1 3 4
7 5 7 8 3 2 6 8 2 9 0 2 4 6 7
2 6 8 4 5 2 3 9 0 3 2 6 7 8 2
4 5 8 2 4 7 9 2 4 2 3 4 5 2 3
5 6 7 8 2 4 5 6 9 3 2 8 4 7 3
8 9 2 5 8 4 0 6 7 2 8 4 6 8 4

11
4 1
2 3
5 3
5 6
2 6
11 3
7 9
11 10
9 12
10 14
3 12

Member functions:
(constructors)
charGrid();
charGrid(std::ifstream &gridFile, std::ifstream &coordinatesFile);
charGrid(std::ifstream &infile);

Element access:
void getDimensions(std::string str);
void getCoordinateCount(std::string str);
int getHeight();
int getWidth();
std::vector<std::string> getGrid();
std::vector<std::string> getCoordinates();
int getCoords();

Code sample:

try {
    ifstream gridFile ("grid");
    ifstream coordinatesFile("coordinates");

   if(gridFile.is_open() && coordinatesFile.is_open()){
        charGrid grid(gridFile, coordinatesFile);
        gridFile.close();
        coordinatesFile.close();
        }else {
     throw std::runtime_error("Unable to open file.");

  }//endif
} catch (const std::runtime_error& e ) {
  cout << "An exception occurred: " << e.what() << endl;
} //try

std::vector<string> graph = graph.getGrid();
std::vector<string> coordinates = graph.getCoordinates();
int nodes = graph.getCoords();
int height = graph.getHeight();
int width = graph.getWidth();
