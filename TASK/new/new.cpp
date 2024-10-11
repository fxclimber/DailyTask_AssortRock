#include <iostream>

int main()
{
    int arr[10][10];


    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i == j)  // 대각선일 때 '*'
                arr[i][j] = 0;
            else if (i < j)  // 세로(y) 쪽 값들 '-'
                arr[i][j] = i;
            else  // 가로(x) 쪽 값들 '*'
                arr[i][j] = j;

            std::cout << arr[i][j];
        }
        std::cout << std::endl;  // 각 행이 끝날 때 줄바꿈
    }

}
