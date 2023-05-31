#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
using namespace std;

int formingMagicSquare(vector<vector<int>> s)
{
	vector<vector<int>> magicSquares = {
		{8, 1, 6, 3, 5, 7, 4, 9, 2},
		{6, 1, 8, 7, 5, 3, 2, 9, 4},
		{4, 9, 2, 3, 5, 7, 8, 1, 6},
		{2, 9, 4, 7, 5, 3, 6, 1, 8},
		{8, 3, 4, 1, 5, 9, 6, 7, 2},
		{4, 3, 8, 9, 5, 1, 2, 7, 6},
		{6, 7, 2, 1, 5, 9, 8, 3, 4},
		{2, 7, 6, 9, 5, 1, 4, 3, 8}
	};
	vector<int> arr;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			arr.push_back(s[i][j]);
	int minCost = INT_MAX;
	for (const auto& v : magicSquares)
	{
		int sum = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] != v[i])
				sum += abs(arr[i] - v[i]);
		}
		minCost = min(minCost, sum);
	}
	return minCost;
}

int main()
{
	fstream file;
	vector<vector<int>> s;
	file.open("MQ.txt");
	if (file.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			vector<int> row;
			int num;
			for (int j = 0; j < 3; j++)
			{
				file >> num;
				row.push_back(num);
			}
			s.push_back(row);
		}
	}
	else
		cout << "Cannot open file\n";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << s[i][j] << " ";
		}
		cout << endl;
	}


	cout << formingMagicSquare(s);


	


	return 0;
}