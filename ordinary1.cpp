#include<iostream>
#include <sys/time.h>                                                                                           
#include <unistd.h>
#include <stdio.h>


const unsigned long Converter = 1000 * 1000; // 1s == 1000 * 1000 us

int main(void)
{
    int cycle = 0;//执行次数，当n较小时，cycle取较大值
    std::cin >> cycle;
    int n = 0;
    std::cin >> n;
    int* arry, * sum;
    int** matrix;
    arry = new int[n];
    sum = new int[n];
    matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        arry[i] = i;
        for (int j = 0; j < n; j++)
            matrix[i][j] = i + j;
    }



    struct timeval val;//start time
    int ret = gettimeofday(&val, NULL);
    if (ret == -1)
    {
        printf("Error: gettimeofday()\n");
        return ret;
    }



    while (cycle)
    {
        for (int i = 0; i < n; i++)
        {
            sum[i] = 0;
            for (int j = 0; j < n; j++)
            {
                sum[i] += matrix[j][i] * arry[j];
            }
        }
        cycle--;
    }






    struct timeval newVal;//end time
    ret = gettimeofday(&newVal, NULL);
    if (ret == -1)
    {
        printf("Error: gettimeofday()\n");
        return ret;
    }


    printf("start: sec --- %ld, usec --- %ld\n", val.tv_sec, val.tv_usec);
    printf("end:   sec --- %ld, usec --- %ld\n", newVal.tv_sec, newVal.tv_usec);

    unsigned long diff = (newVal.tv_sec * Converter + newVal.tv_usec) - (val.tv_sec * Converter + val.tv_usec);


    printf("diff:  sec --- %ld, usec --- %ld\n", diff / Converter, diff % Converter);//time sub
    std::cout << "travial";
    for (int i = 0; i < n; i++)
    {
        delete[]matrix[i];
    }
    delete[]sum;
    delete[]arry;
    delete[]matrix;
    return 0;
}
