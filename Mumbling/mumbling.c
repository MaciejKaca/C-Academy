#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/**
* Function duplicates letters based on their index. Each index means how many times the letter needs to be duplicated.
* See test cases for examples.
*/

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char* accumulate(const char *word, const int length)
{
    int i,a;
    char *result;
    char sign, upper;
    result="";
    for(i=0;i<length;i++)
    {
        sign=word[i];
        //upper=toupper(word[i]);
        result=concat(result,&sign);
        //printf("\n");
       // printf("%s", result);
        for(a=0;a<i;a++)
        {
           result=concat(result,&sign);
        }
        result=concat(result,"-");
    }
    printf("%s", result);
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
	//test_cases();
    accumulate("abcd", strlen("abcd"));
	return 0;
}