#include <iostream>
#include <math.h>
#include <string>

bool showDebugInfo = true;

/*
* TODO:
* Find duplicates?
* Calculate costs
* Solve the Square
*/



#define N 3
void drawSquare(int square[N][N]);
void calculateTotals(int square[N][N]);
void findUniqueNumbers(int square[N][N]);
bool isMagicSquare(int square[N][N]);
int magicCost(int square[N][N]);

int main()
{
    std::string input = "";
    showDebugInfo = true;

    // A given square/matrix that is not yet a magic square
    int givenSquare[N][N] = {
        {6,3,3},
        {1,5,7},
        {6,7,2}
    };

    drawSquare(givenSquare);
    calculateTotals(givenSquare);
    findUniqueNumbers(givenSquare);
    if (isMagicSquare(givenSquare)) {
        std::cout << "This is a magic square!\n";
    } else {
        std::cout << "This is NOT a magic square.\n";
        int cost = magicCost(givenSquare);
        std::cout << "Cost to convert to magic square (sum of differences from magic constant): " << cost << "\n";
    }
    std::cin >> input;

}

// Find unique and missing numbers in a matrix
void findUniqueNumbers(int square[N][N])
{
    int missingNums[N*N] = { 0 };
    int uniqueNums[N*N] = { 0 };
    int missingCount = 0, uniqueCount = 0;
    int count = 0;
    bool unique = true;

    for (int iterator = 1; iterator <= N*N; iterator++) {
        unique = true;
        count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
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
        for (int i = 0; i < N*N; i++)
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
void calculateTotals(int square[N][N])
{
    int sumRows[N] = { 0 };
    int sumCols[N] = { 0 };

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sumRows[i] += square[i][j];
            sumCols[i] += square[j][i];
        }
    }
    if (showDebugInfo)
    {
        std::cout << "\nTotals for each row and column:\n";
        std::cout << " _______________________________________\n";
        for (int i = 0; i < N; i++)
        {
            printf("| Sum of Row %d: %d | Sum of Column %d: %d| \n", i, sumRows[i], i, sumCols[i]);
            std::cout << "|__________________|____________________|\n";
        }
    }

    // Find rows and columns which have the same sum totals
    if (showDebugInfo)
    {
        std::cout << "\nRows and Columns which have the same sum totals:\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (sumRows[i] == sumCols[j])
                    printf("Row %d: %d = Column %d: %d\n", i, sumRows[i], j, sumCols[j]);
            }
        }
        std::cout << "\n";
    }
}


void drawSquare(int square[N][N])
{
    std::string outStr = "";
    for (int i = 0; i < N; i++)
    {
        outStr = "| ";
        for (int j = 0; j < N; j++)
        {
            outStr = outStr + std::to_string(square[i][j]) + " | ";
        }
        std::cout << outStr + "\n";
    }
}

// Implementation of isMagicSquare and magicCost moved here (end of file)
bool isMagicSquare(int square[N][N]) {
    int magicSum = N * (N * N + 1) / 2; // Magic constant for NxN
    // Check rows and columns
    for (int i = 0; i < N; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum)
            return false;
    }
    // Check diagonals
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < N; i++) {
        diag1 += square[i][i];
        diag2 += square[i][N - 1 - i];
    }
    if (diag1 != magicSum || diag2 != magicSum)
        return false;
    return true;
}

int magicCost(int square[N][N]) {
    int magicSum = N * (N * N + 1) / 2;
    int cost = 0;
    // Rows
    for (int i = 0; i < N; i++) {
        int rowSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += square[i][j];
        }
        cost += abs(magicSum - rowSum);
    }
    // Columns
    for (int j = 0; j < N; j++) {
        int colSum = 0;
        for (int i = 0; i < N; i++) {
            colSum += square[i][j];
        }
        cost += abs(magicSum - colSum);
    }
    // Diagonals
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < N; i++) {
        diag1 += square[i][i];
        diag2 += square[i][N - 1 - i];
    }
    cost += abs(magicSum - diag1);
    cost += abs(magicSum - diag2);
    return cost;
}
