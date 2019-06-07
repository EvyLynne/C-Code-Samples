/*
 CLASS:       charGrid
 AUTHOR:       Evelyn Livant
 CREATED:      11-Apr-2019

 DESCRIPTION:  This class takes text files with the dimension of the grid on the
      first line and the grid on the next lines and stores the dimensions in
      integer variables and the grid as a vector of strings. This is for CSC 412
      Spring 2019.

This is 'free' software with the following restrictions:

You may not redistribute this code as a 'sample' or 'demo'. However, you are free
to use the source code in your own code, but you may not claim that you created
the sample code. It is expressly forbidden to sell or profit from this source code
other than by the knowledge gained or the enhanced value added by your own code.

Use of this software is also done so at your own risk. The code is supplied as
is without warranty or guarantee of any kind.

Should you wish to commission some derivative work based on this code provided
here, or any consultancy work, please do not hesitate to contact me.

E-mail: evelynlivant@gmail.com

*/
#include "charGrid.h"


  charGrid::charGrid():height(0), width(0), nodes(0)
  {

  } //default constructor

  charGrid::charGrid(std::ifstream &gridFile, std::ifstream &coordinatesFile){
    /*
      Initializes a grid and a list of coordinates from an input file.
    */
    //read gridFile
    int firstline = 0;
    std::string line = "";

    while ( getline (gridFile, line)){
      if (firstline == 0){
        getDimensions(line);
        firstline++;
      }else {
        gridlines.push_back(line);
      }//endif

    }//while

    //read coordinatesFile
    firstline = 0;
    line = "";

    while ( getline (coordinatesFile, line)){
      if (firstline == 0){
        getCoordinateCount(line);
        firstline++;
      }else {
        coordinates.push_back(line);
      }//endif

    }//while


  } //constructor for grid text file and coordinates text file

  charGrid::charGrid(std::ifstream &infile)
  /*
    Initializes a grid from an input file.
  */
  {
      int firstline = 0;
      std::string line = "";

      while ( getline (infile, line)){
        if (firstline == 0){
          getDimensions(line);
          firstline++;
        }else {
          gridlines.push_back(line);
        }//endif

      }//while
  }//constructor for single grid text file

  void charGrid::getDimensions(std::string str){
    /*
      Args: string containing integer values
      Yields: height and width of grid set to instance varibles
    */

    try {
      if (str.empty()){
        throw std::runtime_error("Unable to process.  No grid parameters provided.");

      }
    }
    catch (const std::runtime_error& e ){
      std::cout << "An exception occurred: " << e.what() << std::endl;
    }//catch
    (void)str;

    std::string temp = "";
    std::stringstream ss;
    int found = 0;
    int counter = 0;

    ss << str;

    while(!ss.eof()){

      ss >> temp;

      if(std::stringstream(temp)>>found){
        if (counter == 0){
            height = found;

        } else {
            width = found;

      }//endif
    }//endif
      temp = "";
      counter++;
    }//while

  }//extractIntegers

  void charGrid::getCoordinateCount(std::string str){
    /*
      Args: string containing integer value
      Yields: number of coordinates in list
    */

    try {
      if (str.empty()){
        throw std::runtime_error("Unable to process.  No node count provided.");

      }
    }
    catch (const std::runtime_error& e ){
      std::cout << "An exception occurred: " << e.what() << std::endl;
    }//catch
    (void)str;

    std::string temp = "";
    std::stringstream ss;
    int found = 0;
    int counter = 0;

    ss << str;

    while(!ss.eof()){

      ss >> temp;

      if(std::stringstream(temp)>>found){
        nodes = found;

      }//endif
      temp = "";
      counter++;
    }//while

  }//getCoordinateCount

  int charGrid::getHeight(){
    return height;
  }//getHeight

  int charGrid::getWidth(){
    return width;
  }//getWidth

  std::vector<std::string> charGrid::getGrid() {
    return gridlines;
  }//getGrid

  std::vector<std::string> charGrid::getCoordinates(){
    return coordinates;
  }//getCoordinates

  int charGrid::getCoords(){
    return nodes;
  }//getCoords
