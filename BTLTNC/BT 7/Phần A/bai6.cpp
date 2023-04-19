#include <iostream>

using namespace std;

void printResults(int nums[], int n)
{
    for (int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;
}

void generateNumbers(int n, int nums[], int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (j > nums[i-1])
        {
            nums[i] = j;
            if (i == n) printResults(nums, n);
            else
            {
                printResults(nums, i+1);
                generateNumbers(n, nums, i+1);
            }
        }
    }
}

int main(int argc, const char* argv[])
{
    int n = stoi(argv[1]);
    int nums[100] = {0};
    generateNumbers(n, nums, 0);
    return 0;
}
