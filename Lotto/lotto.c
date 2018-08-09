#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
/** 
* Function returns an array of 5 elements.
* Those 5 elements are created randomly in the range 1 - 49.
* Numbers can't repeat.
*/
int* Lotto_drawing()
{
    int *numbers=(int *)malloc(sizeof(int)*5);
    int i, a, random, flag, count=0;
    time_t t;
    srand((unsigned) time(&t));

    for(i=0;i<5;i++)
    {
        numbers[i]=0;
    }

    while(count!=5)
    {
       random=rand() % 49 + 1;
       flag=0;
       for(a=0;a<5;a++)
       {
           if(a!=count)
           {
               if(random==numbers[a])
               {
                    flag=1;
               }
           }
       }
        if(flag==0)
        {
            numbers[count]=random;
            count++;
        }
    }
    return(numbers);
}

bool check_lotto(int *numbers)
{
    int i, a;
    for(i=0;i<5;i++)
    {
        for(a=0;a<5;a++)
        {
            if(a!=i && numbers[a] == numbers[i] || numbers[i]>=49 || numbers[i]<=1) 
                return true;
        }
    }
    return false;
}

/* Please create test cases for this program. test_cases() function can return void, bool or int. */
bool test_cases()
{
    assert(check_lotto(Lotto_drawing()) == false);
}


int main()
{
    test_cases();
    //Lotto_drawing();
}
