#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/**
* Function duplicates letters based on their index. Each index means how many times the letter needs to be duplicated.
* See test cases for examples.
*/

float sum(int end)
{
    return ((float)((1+end)/2)*end);
}

char* accumulate(const char *word, const int length)
{
    int i,a, count=1;
    char *result=malloc(sizeof(char)*(sum(length)+length-1));
    char sign, upper;
    result[0]=toupper(word[0]);
    for(i=1;i<length;i++)
    {
        result[count]='-';
        count++;
        result[count]=toupper(word[i]);
        count++;
        for(a=0;a<i;a++)
        {
           result[count]= tolower(word[i]);
           count++;
        }
    }
    return result;
}

void test_cases()
{
	char* result = accumulate("abcd", strlen("abcd"));
	assert(strcmp(result, "A-Bb-Ccc-Dddd") == 0);

	result = accumulate("cwAt", strlen("cwAt"));
	assert(strcmp(result, "C-Ww-Aaa-Tttt") == 0);
}

int main(int argc, char *argv[])
{
	test_cases();
	return 0;
}