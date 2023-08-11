#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main()
{
    string out;
    int cost = 0;

    int sumRows[3] = {0,0,0};
    int sumCols[3] = {0,0,0};

    // A given square/matrix that is not yet a magic square
    int givenSquare[3][3] =
    {
        {6,3,3},
        {1,5,7},
        {6,7,2}
    };

    // Calculate the sum totals for each of the rows and columns of the given square
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sumRows[i] += givenSquare[i][j];
            sumCols[i] += givenSquare[j][i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        printf("Sum of Row %d: %d\tSum of Column %d: %d\n", i, sumRows[i], i, sumCols[i]);
    }
    // Find rows and columns which have the same sum totals
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sumRows[i] == sumCols[j])
                printf("Row %d: %d = Column %d: %d\n", i, sumRows[i], j, sumCols[j]);
        }
    }

    //out = to_string(givenSquare[1][1]);
    //cost = abs(3-5);

    //std::cout << out+"\n";
}
