#include "stdafx.h"
#include "Maze.h"
#include <stdexcept>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <limits>
#include "LibProfTP2.h"
const char Maze::WALL;
const char Maze::PATH;
const char Maze::START;
const char Maze::END;
const int Maze::CELL_WIDTH;


#pragma region Code fourni
Maze::Maze()
  : width(-1), height(-1), startColumn(-1), startRow(-1), endColumn(-1), endRow(-1), numberOfDisplacements(nullptr), maze(nullptr)
{
}

Maze::~Maze()
{
  for (int i = 0; i < height; ++i)
  {
    delete[] maze[i];
  }
  delete[] maze;

  for (int i = 0; i < height; ++i)
  {
    delete[] numberOfDisplacements[i];
  }
  delete[] numberOfDisplacements;
}

int Maze::getWidth() const
{
  return width;
}

int Maze::getHeight() const
{
  return height;
}

void Maze::parseFromMemory(std::string mazeContent)
{
  std::istringstream is(mazeContent);
  char c;
  is >> width >> height;
  // Espace après la hauteur
  is.get(c);
  initMaze();

  for (int i = 0; i < height; ++i)
  {
    for (int j = 0; j < width; ++j)
    {
      is.get(c);
      if (!(is))
      {
        throw std::runtime_error("Failed to read maze data.");
      }
      else if (c != '\n')
      {
        maze[i][j] = c;
        if (c == START)
        {
          startRow = i;
          startColumn = j;
        }
        if (c == END)
        {
          endRow = i;
          endColumn = j;
        }
      }
      else
        j--;
    }
  }
}

char Maze::getAt(int row, int col) const
{
  if (row < 0 || row >= height || col < 0 || col >= width)
  {
    throw std::out_of_range("Index out of bounds");
  }
  return maze[row][col];
}

int Maze::getNumberOfDisplacementToReachCoordinates(int row, int col) const
{
  if (nullptr == numberOfDisplacements)
  {
    throw std::runtime_error("Costs not initialized. Call computeCosts() first.");
  }
  return numberOfDisplacements[row][col];
}

bool Maze::isValid() const
{
  return width > 2 && height > 2 && startColumn != -1 && startRow != -1 && endColumn != -1 && endRow != -1;
}


void Maze::initMaze()
{
  if (maze != nullptr)
  {
    for (int i = 0; i < height; ++i)
    {
      delete[] maze[i];
    }
    delete[] maze;
  }
  maze = new char* [height];
  for (int i = 0; i < height; ++i)
  {
    maze[i] = new char[width];
  }

  numberOfDisplacements = new int* [height];
  for (int i = 0; i < height; ++i)
  {
    numberOfDisplacements[i] = new int[width];
  }
}
#pragma endregion
#pragma region Code à produire
void Maze::display() const
{
  // PROF
  // A METTRE EN COMMENTAIRES ET REMPLACER PAR LE CODE ADEQUAT
  for(int i = 0; i < height; i++) 
  {
    for(int k = 0; k < width; k++) 
    {
        std::cout << setw(CELL_WIDTH) << getAt(i, k);
    }
    std::cout << std::endl;
  }
  
  //LibProfTP2::displayMaze(maze, width, height, CELL_WIDTH);
}
void Maze::displayNumberOfDisplacements() const
{
  // PROF
  // A METTRE EN COMMENTAIRES ET REMPLACER PAR LE CODE ADEQUAT
  LibProfTP2::displayNumberOfDisplacements(numberOfDisplacements, width, height, CELL_WIDTH);
}

void Maze::recursiveComputeNumberOfDisplacements(int row, int col, int distance)
{
    if (row < 0 || col < 0 || row >= height || col >= width) { return; }
    if (getAt(row, col) == WALL) { return; }
    if(this->numberOfDisplacements[row][col] <= distance) { return; }
    numberOfDisplacements[row][col] = distance;

    recursiveComputeNumberOfDisplacements(row - 1, col, distance + 1);
    recursiveComputeNumberOfDisplacements(row + 1, col, distance + 1);
    recursiveComputeNumberOfDisplacements(row, col - 1, distance + 1);
    recursiveComputeNumberOfDisplacements(row, col + 1, distance + 1);
}

void Maze::computeNumberOfDisplacements()
{
    for(int i = 0; i< height; i++) 
    {
        for(int j = 0; j < width; j++) 
        {
            numberOfDisplacements[i][j] = LONG_MAX;
        }
    }

    recursiveComputeNumberOfDisplacements(startRow, startColumn, 0);
    //int start = numberOfDisplacements[startColumn][startRow];
  // PROF
  // A METTRE EN COMMENTAIRES ET REMPLACER PAR LE CODE ADEQUAT
  //LibProfTP2::computeNumberOfDisplacements(numberOfDisplacements, maze, width, height, startRow, startColumn,endRow, endColumn );
}



void Maze::getPathToExit(Stack& path) const
{
  // PROF
  // A METTRE EN COMMENTAIRES ET REMPLACER PAR LE CODE ADEQUAT
  LibProfTP2::getPathToExit(numberOfDisplacements, maze, width, height, startRow, startColumn,endRow, endColumn, path);
}

void Maze::findAllPoints(Queue& points) const
{
  // PROF
  // A METTRE EN COMMENTAIRES ET REMPLACER PAR LE CODE ADEQUAT
  LibProfTP2::findAllPoints(maze, width, height, startRow, startColumn, points);
}



#pragma endregion