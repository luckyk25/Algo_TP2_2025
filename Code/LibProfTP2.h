#pragma once
#include "Stack.h"
#include "Queue.h"
class LibProfTP2
{
public:

  static void displayMaze(char **maze, int width, int height, int cellWidth);
  static void displayNumberOfDisplacements(int** numberOfDisplacements, int width, int height, int cellWidth);
  static void computeNumberOfDisplacements(int** numberOfDisplacements, char** maze, int width, int height, int startRow, int startColumn, int endRow, int endColumn);
  static void getPathToExit(int ** numberOfDisplacements, char ** maze, int width, int height, int startRow, int startColumn, int endRow, int endColumn, Stack& stack);
  static void findAllPoints(char ** maze, int width, int height, int startRow, int startColumn, Queue& points);
};
