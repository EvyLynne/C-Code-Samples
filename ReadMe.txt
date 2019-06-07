The charGrid class are container objects that hold properties of the text grids used by URI
Associate Professor Jean-Yves Herve' in CSC 412.  An open file stream can be passed to the constructor which
will unpack the file contents and set up the object.  This is written to process integer values, but
can easily be modified for doubles or floats.

This class provides support for files of these sturctures:

13 15
1.0 6.0 7.0 8.0 9.0 0.0 3.0 4.0 2.0 4.0 6.0 7.0 1.0 6.0 3.0
4.0 5.0 6.0 1.0 2.0 4.0 0.0 9.0 6.0 7.0 3.0 2.0 1.0 3.0 4.0
2.0 4.0 5.0 7.0 8.0 9.0 0.0 2.0 1.0 4.0 2.0 3.0 4.0 1.0 3.0
5.0 1.0 3.0 2.0 2.0 5.0 6.0 8.0 9.0 0.0 2.0 3.0 4.0 7.0 8.0
9.0 4.0 4.0 5.0 6.0 7.0 9.0 1.0 2.0 8.0 3.0 6.0 7.0 8.0 2.0
5.0 6.0 7.0 8.0 9.0 1.0 2.0 3.0 4.0 3.0 8.0 2.0 0.0 3.0 0.0
6.0 8.0 9.0 1.0 5.0 2.0 8.0 4.0 9.0 3.0 6.0 7.0 6.0 7.0 2.0
5.0 6.0 8.0 9.0 2.0 4.0 6.0 9.0 2.0 5.0 7.0 8.0 1.0 3.0 4.0
7.0 5.0 7.0 8.0 3.0 2.0 6.0 8.0 2.0 9.0 0.0 2.0 4.0 6.0 7.0
2.0 6.0 8.0 4.0 5.0 2.0 3.0 9.0 0.0 3.0 2.0 6.0 7.0 8.0 2.0
4.0 5.0 8.0 2.0 4.0 7.0 9.0 2.0 4.0 2.0 3.0 4.0 5.0 2.0 3.0
5.0 6.0 7.0 8.0 2.0 4.0 5.0 6.0 9.0 3.0 2.0 8.0 4.0 7.0 3.0
8.0 9.0 2.0 5.0 8.0 4.0 0.0 6.0 7.0 2.0 8.0 4.0 6.0 8.0 4.0

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
