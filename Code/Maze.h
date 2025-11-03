#pragma once

#include <string>
#include "Stack.h"
#include "Queue.h"
class Maze
{
public:
  static const int CELL_WIDTH = 4;
  static const char WALL = '*';
  static const char PATH = ' ';
  static const char START = 'D';
  static const char END = 'F';

  // prof
  // Méthodes fournies
  Maze();
  ~Maze();
  int getWidth() const;
  int getHeight() const;
  char getAt(int row, int col) const;
  int getNumberOfDisplacementToReachCoordinates(int row, int col) const;
  void parseFromMemory(std::string content);
  void initMaze();
  bool isValid() const;
  
  void display() const;
  void displayNumberOfDisplacements() const;
  void computeNumberOfDisplacements();
  void getPathToExit(Stack& path) const;
  void findAllPoints(Queue& points)const;

private:
  void recursiveComputeNumberOfDisplacements(int row, int col, int distance);
  void recursiveGetPath(int row, int col, Stack& path) const;
  void recusriveFindAllPoints(int row, int col, Queue& points) const;
  int width;
  int height;
  char** maze;
  int** numberOfDisplacements;
  int startColumn;
  int startRow;
  int endColumn;
  int endRow;
};

