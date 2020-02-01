#pragma once
#include <vector>
#include <string>
#include "Matrix.h"
using namespace std;
class MatrixFactory
{
public:
	static Matrix createMatrix(string input);

private:
	static string extractLastLine(vector<string> &input);

	static vector<int> parseRow(const string &line);

	static pair<int, int> parseCoordinates(const string &data);

	static vector<string> splitInput(const string &input);
};



