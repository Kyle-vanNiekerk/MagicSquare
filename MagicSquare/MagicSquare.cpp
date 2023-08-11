#include <iostream>
#include <math.h>
#include <string>

bool showDebugInfo = true;
int missingNums[9] = { 0 };
int uniqueNums[9] = { 0 };
int missingCount = 0, uniqueCount = 0;

std::string out;
int cost = 0;

int sumRows[3] = { 0 };
int sumCols[3] = { 0 };
int uniqueNumbers[9] = { 0 };

// Find unique and missing numbers in a matrix
void findUniqueNumbers(int square[3][3])
{
    bool unique = true;
    int count = 0, iterator = 1;
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
            missingNums[missingCount] = iterator;
            missingCount++;
            unique = false;
        }
        if (unique == true)
        {
            uniqueNums[uniqueCount] = iterator;
            uniqueCount++;
        }
    }
    if (showDebugInfo)
    {
        std::string uniqueOut = "";
        std::string missingOut = "";
        for (int i = 0; i < 9; i++)
        {
            if (uniqueNums[i] != 0)
            {
                uniqueOut = uniqueOut + std::to_string(uniqueNums[i]) + "; ";
            }
            if (missingNums[i] != 0)
            {
                missingOut = missingOut + std::to_string(missingNums[i]) + "; ";
            }
        }
        std::cout << "Unique numbers: " + uniqueOut + "\n";
        std::cout << "Missing numbers: " + missingOut + "\n";
        //cost = abs(3-5);
    }
}

// Calculate the sum totals for each of the rows and columns of the given square
void calculateTotals(int square[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sumRows[i] += square[i][j];
            sumCols[i] += square[j][i];
        }
    }
    if (showDebugInfo)
    {
        std::cout << "\nTotals for each row and column:\n";
        std::cout << " _______________________________________\n";
        for (int i = 0; i < 3; i++)
        {
            printf("| Sum of Row %d: %d | Sum of Column %d: %d| \n", i, sumRows[i], i, sumCols[i]);// Table only displays neatly if sums are 2 digits
            std::cout << "|__________________|____________________|\n";
        }
    }
}

// Find rows and columns which have the same sum totals
void findMatchingTotals(int square[3][3])
{
    std::cout << "\nRows and Columns which have the same sum totals:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sumRows[i] == sumCols[j])
                printf("Row %d: %d = Column %d: %d\n", i, sumRows[i], j, sumCols[j]);
        }
    }
    std::cout << "\n";
}

void drawSquare(int square[3][3])
{
    std::string outStr = "";
    std::cout << " ___________\n";
    for (int i = 0; i < 3; i++)
    {
        outStr = "| ";
        for (int j = 0; j < 3; j++)
        {
            outStr = outStr + std::to_string(square[i][j]) + " | ";
        }
        std::cout << outStr+"\n";
    }
}

int main()
{
    showDebugInfo = false;
    // A given square/matrix that is not yet a magic square
    int givenSquare[3][3] =
    {
        {6,3,3},
        {1,5,7},
        {6,7,2}
    };
    if (showDebugInfo)
        drawSquare(givenSquare);
    calculateTotals(givenSquare);
    if (showDebugInfo) 
        findMatchingTotals(givenSquare);
    findUniqueNumbers(givenSquare);
}
