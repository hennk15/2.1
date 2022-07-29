#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    const int n = 100;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = (i + j); //assign values
    long start = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count(); //get time in ms
    
    int sum = 0; //random operation
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                for (int l = 0; l < n; l++)
                    sum += *(*(a + i) + j);

long end = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count(); //end timer
std::cout << "Time in milliseconds: " << end - start << endl;
}