#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<long long int> l0 = {71, 56, 50, 73};
list<long long int> l1 = {70, 89, 82};
list<long long int> l2 = {52, 95};
list<long long int> l3 = {94, 64, 69, 87, 70};
list<long long int> l4 = {98, 72, 98, 53, 97, 51};
list<long long int> l5 = {79};
list<long long int> l6 = {77, 55, 63, 93, 66, 90, 88, 71};
list<long long int> l7 = {54, 97, 87, 70, 59, 82, 59};

int monkeysActivity[] = {0, 0, 0, 0, 0, 0, 0, 0};

int Inspection(long long int item, int monkey)
{

    long long int output = 0;
    switch (monkey)
    {
    case 0:
        monkeysActivity[monkey]++;
        output = item * 11;
        break;

    case 1:
        monkeysActivity[monkey]++;
        output = item + 1;
        break;

    case 2:
        monkeysActivity[monkey]++;
        output = item * item;
        break;

    case 3:
        monkeysActivity[monkey]++;
        output = item + 2;
        break;

    case 4:
        monkeysActivity[monkey]++;
        output = item + 6;
        break;

    case 5:
        monkeysActivity[monkey]++;
        output = item + 7;
        break;

    case 6:
        monkeysActivity[monkey]++;
        output = item * 7;
        break;

    case 7:
        monkeysActivity[monkey]++;
        output = item + 8;
        break;
    }
    return output;
}

void TestInspection(long long int item, int monkey)
{

   // item = item / 3;
    switch (monkey)
    {
    case 0:
        if (item % 13 == 0)
        {
            l0.pop_front();
            l1.push_back(item);
        }
        else
        {
            l0.pop_front();
            l7.push_back(item);
        }
        break;
    case 1:
        if (item % 7 == 0)
        {
            l1.pop_front();
            l3.push_back(item);
        }
        else
        {
            l1.pop_front();
            l6.push_back(item);
        }
        break;
    case 2:
        if (item % 3 == 0)
        {
            l2.pop_front();
            l5.push_back(item);
        }
        else
        {
            l2.pop_front();
            l4.push_back(item);
        }
        break;
    case 3:
        if (item % 19 == 0)
        {
            l3.pop_front();
            l2.push_back(item);
        }
        else
        {
            l3.pop_front();
            l6.push_back(item);
        }
        break;
    case 4:
        if (item % 5 == 0)
        {
            l4.pop_front();
            l0.push_back(item);
        }
        else
        {
            l4.pop_front();
            l5.push_back(item);
        }
        break;
    case 5:
        if (item % 2 == 0)
        {
            l5.pop_front();
            l7.push_back(item);
        }
        else
        {
            l5.pop_front();
            l0.push_back(item);
        }
        break;
    case 6:
        if (item % 11 == 0)
        {
            l6.pop_front();
            l2.push_back(item);
        }
        else
        {
            l6.pop_front();
            l4.push_back(item);
        }
        break;
    case 7:
        if (item % 17 == 0)
        {
            l7.pop_front();
            l1.push_back(item);
        }
        else
        {
            l7.pop_front();
            l3.push_back(item);
        }
        break;
    }
}

int main()
{
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            switch (j)
            {
            case 0:
                while (l0.size() > 0)
                {

                    long long int newitem = Inspection(l0.front(), j);
                    TestInspection(newitem, j);
                }
                break;
            case 1:
                while (l1.size() > 0)
                {
                    long long int newitem = Inspection(l1.front(), j);
                    TestInspection(newitem, j);
                }
                break;
            case 2:
                while (l2.size() > 0)
                {
                    long long int newitem = Inspection(l2.front(), j);
                    TestInspection(newitem, j);
                }
                break;
            case 3:
                while (l3.size() > 0)
                {
                    long long int newitem = Inspection(l3.front(), j);
                    TestInspection(newitem, j);
                }
                break;
            case 4:
                while (l4.size() > 0)
                {
                    long long int newitem = Inspection(l4.front(), j);
                    TestInspection(newitem, j);
                }
                break;
            case 5:
                while (l5.size() > 0)
                {
                    long long int newitem = Inspection(l5.front(), j);
                    TestInspection(newitem, j);
                }
                break;
            case 6:
                while (l6.size() > 0)
                {
                    long long int newitem = Inspection(l6.front(), j);
                    TestInspection(newitem, j);
                }
                break;
            case 7:
                while (l7.size() > 0)
                {
                    long long int newitem = Inspection(l7.front(), j);
                    TestInspection(newitem, j);
                }
                break;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        cout << "Monkey " << i << " has inspected " << monkeysActivity[i] << " items." << endl;
    }
    sort(begin(monkeysActivity), end(monkeysActivity));

    cout << "Total Monkey Buisness " << monkeysActivity[6] * monkeysActivity[7] << endl;
}