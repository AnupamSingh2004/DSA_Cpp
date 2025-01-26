#include <bits/stdc++.h>
using namespace std;

long long squareRootInteger(int x)
{

    int s = 0;
    int e = x;
    int mid = s + (e - s) / 2;
    long long ans = -1;
    while (s <= e)
    {
        long long square = mid * mid;

        if (square == x)
        {
            return mid;
        }
        if (square < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSol)
{

    double factor = 1;
    double ans = tempSol;

    for (size_t i = 0; i < precision; i++)
    {
        factor = factor / 10;

        for (double j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{

    int a;
    cin >> a;

    long long tempSol = squareRootInteger(a);
    cout << morePrecision(a, 3, tempSol) << endl;
    return 0;
}