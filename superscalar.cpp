#include<iostream>
#include <sys/time.h>                                                                                           
#include <unistd.h>
#include <stdio.h>


const unsigned long Converter = 1000 * 1000; // 1s == 1000 * 1000 us

int main(void)
{
    int cycle = 0;//执行次数，当n较小时，cycle取较大值
    std::cin >> cycle;
    int n = 0, sum = 0, sum1 = 0, sum2 = 0;
    std::cin >> n;
    int* arry = new int[n];
    for (int i = 0; i < n; i++)
    {
        arry[i] = i;
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
        sum1 = 0;
        sum2 = 0;
        for (int i = 0; i < n; i += 2)
        {
            sum1 += arry[i];
            sum2 += arry[i + 1];
        }
        cycle--;
    }
    sum = sum1 + sum2;





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
    std::cout << "superscalar";
    delete[]arry;
    return 0;
}
