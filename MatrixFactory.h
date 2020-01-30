//
// Created by linor on 29/01/2020.
//

#include <string>
#include "Matrix.h"
using namespace std;
class MatrixFactory {
private:
    //static vector<string> createVectorOfStrings(const string &string1);
    static pair<int, int> parseCoordinates(const string &data);
    static vector<int> parseRow(const string &line);
    static string extractLastLine(vector<string> &input);	
	static vector<string> splitInput(const string &input);
public:
    static Matrix createMatrix(string inputData);
};

