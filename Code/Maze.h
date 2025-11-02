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
  
  
  
  
  // prof
  // Méthode à coder pour ce travail
  // Tâche #1a
  void display() const;
  // Tâche #1b
  void displayNumberOfDisplacements() const;

  // Tâche #2
  void computeNumberOfDisplacements();

  // Tâche #3
  void getPathToExit(Stack& path) const;

  // Tâche #4
  void findAllPoints(Queue& points)const;




private:
  void recursiveComputeNumberOfDisplacements(int row, int col, int distance);
  void recursiveGetPath(int row, int col, Stack& path) const;
  int width;
  int height;
  char** maze;
  int** numberOfDisplacements;
  int startColumn;
  int startRow;
  int endColumn;
  int endRow;
};

