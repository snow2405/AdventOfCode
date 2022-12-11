// Copyright Lion Six 2022

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ifstream data;
    data.open("../data.txt");

    int currentCount = 0;
    vector<int> elfCalories;

    for (string line; getline(data, line);)
    {
        if (line == "")
        {
            elfCalories.push_back(currentCount);
            currentCount = 0;
        }
        else
        {
            currentCount += stoi(line);
        }
    }

    sort(elfCalories.begin(), elfCalories.end());

    cout << elfCalories[elfCalories.size() - 1] + elfCalories[elfCalories.size() - 2] + elfCalories[elfCalories.size() - 3] << endl;
    return 0;
}