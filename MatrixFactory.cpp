

#include "MatrixFactory.h"
#include <sstream>
using namespace std;
Matrix MatrixFactory::createMatrix(string input) {
	vector<string> parsedInput = splitInput(input);
	vector<vector<int>> matrix;
	parsedInput.pop_back();
	//keeping the init and goal states separately, for convenience
	string goalData = extractLastLine(parsedInput);
	string initData = extractLastLine(parsedInput);
	//allocate space for the rows in advance, for efficiency
	matrix.reserve(parsedInput.size());
	for (const auto &line : parsedInput) {
		if (!line.empty())
			matrix.push_back(parseRow(line));
	}
	pair<int, int> initPair = parseCoordinates(initData);
	double costInit = matrix[initPair.first][initPair.second];
	pair<int, int> goalPair = parseCoordinates(goalData);
	double costGoal = matrix[goalPair.first][goalPair.second];
	State<pair<int, int>> init = State<pair<int, int>>(initPair, costInit, NULL, NOT);
	State<pair<int, int>> goal = State<pair<int, int>>(goalPair, costGoal, NULL, NOT);
	return Matrix(matrix, init, goal);
}

vector<int> MatrixFactory::parseRow(const string &line) {
	vector<int> lineAsInt;
	string token;
	stringstream ss(line);
	while (getline(ss, token, ',')) {
		if (!token.empty())
			lineAsInt.push_back(stoi(token));
	}
	return lineAsInt;
}

string MatrixFactory::extractLastLine(vector<string> &input) {
	string temp = input.back();
	input.pop_back();
	return temp;
}

pair<int, int> MatrixFactory::parseCoordinates(const string &data) {
	string coordinate;
	int first, second;
	stringstream ss(data);
	getline(ss, coordinate, ',');
	first = stoi(coordinate);
	getline(ss, coordinate);
	second = stoi(coordinate);
	return make_pair(first, second);
}

vector<string> MatrixFactory::splitInput(const string &input) {
	string temp;
	vector<string> result;
	stringstream ss(input);
	while (getline(ss, temp))
		result.push_back(temp);
	return result;
}


/*#include "MatrixFactory.h"



MatrixFactory::MatrixFactory()
{
}


MatrixFactory::~MatrixFactory()
{
}*/