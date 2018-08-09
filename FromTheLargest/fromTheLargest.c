#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/**
* Given a number, return the maximum number that could be formed with digits of the number given.
* For example: number = 7389, return 9873
*/

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int number_of_digits(int number)
{
    int size=0;
    while(number)    
    {
        size++;
        number /= 10;
    }
    return size;
}

int *digit_from_number(int number)
{
    int size=0;
    int i=0;
    int number_for_count=number;
    int *digits=(int *)malloc(sizeof(int)*number_of_digits(number));
    while(number)    
    {
        digits[i++]=number%10;
        number /= 10;
    }
    return digits;
}

int form_the_largest_number(int number)
{
    int result=0;
    int i;
    int *digits=(int *)malloc(sizeof(int)*number_of_digits(number));
    digits=digit_from_number(number);

    qsort(digits, number_of_digits(number), sizeof(int), cmpfunc);
    for (i = 0; i < number_of_digits(number); i++)
        result = 10 * result + digits[i];

	return result;
}

void test_cases()
{
	int result = form_the_largest_number(213);
	assert(result == 321);

	result = form_the_largest_number(7389);
	assert(result == 9873);

	result = form_the_largest_number(63729);
	assert(result == 97632);

	result = form_the_largest_number(566797);
	assert(result == 977665);
}

int main()
{
	test_cases();
}
