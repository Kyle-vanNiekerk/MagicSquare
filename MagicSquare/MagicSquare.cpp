#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int missing[9] = { 0 };

int * getUniqueNumbers(int square[3][3])
{
    int result[9] = { 0 };
    bool unique = true;
    int count = 0, missingCount = 0, uniCount = 0, iterator = 1;
    for (iterator; iterator < 10; iterator++)
    {
        unique = true;
        count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (unique == false)
                    break;

                if (square[i][j] == iterator)
                    count++;

                if (count >= 2)
                {
                    unique = false;
                    break;
                }
            }
        }
        if (count == 0)
        {
            missing[missingCount] = iterator;
            missingCount++;
            unique = false;
        }
        if (unique == true)
        {
            result[uniCount] = iterator;
            uniCount++;
            cout << "unique: " + to_string(iterator) + "\n";
        }
    }
    for (size_t i = 0; i < 9; i++)
    {
        if (missing[i] != 0)
        {
            cout << "Missing: " + to_string(missing[i]) + "\n";
        }
    }
    return result;
}

int main()
{
    string out;
    int cost = 0;

    int sumRows[3] = {0};
    int sumCols[3] = {0};
    int uniqueNumbers[9] = {0};

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

    // Find unique numbers
    int * unique = getUniqueNumbers(givenSquare);
    //cout << "Unique numbers: ";
    for (int i = 0; i < 9; i++)
    {
        if (unique[i] != 0)
        {
            //cout << to_string(unique[i]) + "; ";
        }   
    }
    cout << "\n";

    //out = to_string(givenSquare[1][1]);
    //cost = abs(3-5);

    //std::cout << out+"\n";
}
