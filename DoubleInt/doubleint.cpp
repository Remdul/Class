#include <iostream>
#include <string>
#include <random>
// curb stutter
// * = contents, no * = pointer itself

int *fillDoubleInt(int FILL_COUNT)
{
    int *memInt = new int[FILL_COUNT];
//    double memDoub = new double[FILL_COUNT];
    int randomInt;

    for (int i = 0; i < FILL_COUNT; i++)
    {
        randomInt = (rand() % 10) + 1;
        memInt[i] = randomInt;
    }
    return memInt;
}

int calcFull(int* filledMemInt, int FILL_COUNT)
{
    int total;
    for (int i = 0; i < FILL_COUNT; i++)
    {
        total += filledMemInt[i];
        std::cout << filledMemInt[i] << std::endl;
    }
    delete [] filledMemInt;
    return total;
}
int main()
{
    int FILL_COUNT = 100;
    int *filledMemInt = NULL;
    filledMemInt = fillDoubleInt(FILL_COUNT);
    int totalNums = calcFull(filledMemInt, FILL_COUNT);
    std::cout << totalNums << std::endl;
    //delete[] filledMemInt;
}
