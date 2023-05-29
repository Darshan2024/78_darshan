#include <iostream>

using namespace std;

//int NQueen(int r, int n);
int x[20], count;

int place(int r, int c)
{
    int i;
    for (i = 1; i <= r - 1; i++)
    {
        if (x[i] == c) // column
        {
            return 0;
        }
        else if(abs(x[i] - c) == abs(i - r)) // diagonal
        {
            return 0;
        }
    }
    return 1;
}

int print(int n)
{
    int i, j;
    cout << "\n\nSolution\n\n" << ++count;
    cout<<"\n\n";
   
    for (i = 1; i <= n; i++)
    {
        cout << "\t" << i;
    }
    for (i = 1; i <= n; i++)
    {
        cout << "\n" << i;
        for (j = 1; j <= n; j++)
        {
            if (x[i] == j)
                cout << "\t Q";
            else
                cout << "\t -";
        }
    }
    return 0;
}

int NQueen(int r, int n)
{
    int c, i;
    for (c = 1; c <= n; c++)
    {
        if (place(r, c))
        {
            x[r] = c;
            if (r == n)
            {
                print(n);
            }
            else
            {
                NQueen(r + 1, n);
            }
        }
    }
    return 0;
}

int main()
{
    int i, j, n, r;
    cout << "\n ****** N-Queen Solution *****\n";
    cout << "\n Enter the Queen:-\n";
    cin >> n;
    NQueen(1, n);
    return EXIT_SUCCESS;
}
