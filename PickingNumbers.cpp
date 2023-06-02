#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int pickingNumbers(vector<int> a)
{
	vector<vector<int>> list;
	for (int i = 0; i < a.size() - 1; i++)
	{
		vector<int> greater;
		vector<int> less;
		greater.push_back(a[i]);
		less.push_back(a[i]);
		for (int j = i + 1; j < a.size(); j++)
		{
			if (a[j] == a[i] + 1) greater.push_back(a[j]);
			if (a[j] == a[i] - 1) less.push_back(a[j]);
			if (a[j] == a[i])
			{
				greater.push_back(a[j]);
				less.push_back(a[j]);
			}
		}
		list.push_back(greater);
		list.push_back(less);
	}
	int max = list[0].size();
	for (const auto& v : list)
	{
		if (v.size() > max)
			max = v.size();
	}
	return max;
}

int main()
{
	vector<int> a;
	int n;
	cin >> n;
	while (n--)
	{
		int num;
		cin >> num;
		a.push_back(num);
	}
    cout << pickingNumbers(a);




	return 0;
}