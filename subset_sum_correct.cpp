#include <iostream>
#include <vector>
using namespace std;

void display(const vector<int> &solution);
bool sumsubset(const int a[], int n, int sum, vector<int> &solution, int s = 0, int idx = 0);

bool sumsubset(const int a[], int n, int sum, vector<int> &solution, int s, int idx)
{
    if (s > sum)
        return false;

    if (s == sum)
    {
        display(solution);
        return true;
    }

    for (int i = idx; i < n; i++)
    {
        solution.push_back(a[i]);
        if (sumsubset(a, n, sum, solution, s + a[i], i + 1))
            return true;
        solution.erase(solution.begin() + solution.size() - 1);
    }
    return false;
}

void display(const vector<int> &solution)
{
    // cout << "Yes, the following elements can be used to make the sum 31: ";
    cout << endl;
    for (int i = 0; i < solution.size(); i++)
    {
        cout << solution[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {7, 11, 13, 24};
    int n = sizeof(a) / sizeof(a[0]);
    int sum = 31;
    vector<int> solution;
    if (!sumsubset(a, n, sum, solution))
        cout << "No solution exists" << endl;
    return 0;
}