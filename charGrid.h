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
#ifndef _charGrid_h
#define _charGrid_h

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <fstream>


class charGrid{
public:
  //constructors
  charGrid();
  charGrid(std::ifstream &gridFile, std::ifstream &coordinatesFile);
  charGrid(std::ifstream &infile);

  //Helper method to return the height and width from a string
  void getDimensions(std::string str);
  //Helper method to store the number of coordinates
  void getCoordinateCount(std::string str);

  //Getter methods
  int getHeight();
  int getWidth();
  std::vector<std::string> getGrid();
  std::vector<std::string> getCoordinates();
  int getCoords();

private:
  int height;
  int width;
  int nodes;
  std::vector <std::string> gridlines;
  std::vector<std::string> coordinates;

};

#endif
