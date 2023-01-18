#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;


void alloc2d(int**& board, int n);
void delete2d(int**& board, int n);
void buildBoard(int**& board, int n, int startX, int startY);
void outputBoard(int**& board, int n, ofstream& fout);
int menu(int& n, int& startX, int& startY);
void outputOptions(int n, int startX, int startY);
int permuteKnight(int**& board, int startX, int startY, int count, int n,
                  ofstream& fout);
bool openOutputFile(ofstream& fout, string fileName);
bool openInputFile(ifstream& fin, string fileName);
void fileOutputHeader(ofstream& fout, int fileCount, int n, int startX,
                      int startY);
void incrementValues(int& n, int& startX, int& startY);
void totalFileOutput(int** board, int& n, int& startX, int& startY,
                     ofstream& fout, int& fileCount);
void totalConsoleOutput(int** board, int& n, int& startX, int& startY,
                        ofstream& fout);
void printUsage();