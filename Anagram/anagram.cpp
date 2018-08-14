#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
/**
* Function returns true if word_1 and word_2 are anagrams to each other. Otherwise false.
* Case sensitivity doesn't matter.
*/

int wordWithoutSpaces(const char* word, int length)
{
    int charCount = 0;
    int i;
    for(i = 0; i < length; ++i)
    {
        if(word[i] != ' ')
            charCount++;
    }
    return charCount;
}

bool check_if_anagram(const char* word_1, int length_1,const char* word_2, int length_2)
{
    int i,j,count_1, count_2;
    char *word1 = (char*)malloc(length_1*sizeof(char));
    char *word2 = (char*)malloc(length_2*sizeof(char));

    memset(word1, '\0', sizeof(word1));
    memset(word2, '\0', sizeof(word2));

    strcpy(word1, word_1);
    strcpy(word2, word_2);

    if( wordWithoutSpaces(word_1, length_1) == wordWithoutSpaces(word_2, length_2) )
    {
        for(i=0;i<length_1;i++)
        {
            for(j=0;j<length_2;j++)
            {
                if(word_1[i] == word2[j])
                {
                    word1[i] = ' ';
                    word2[j] = ' ';
                    break;
                }
            }
        }
        if(wordWithoutSpaces(word1, length_1) == wordWithoutSpaces(word2, length_2))
            return true;
        else
            return false;
    }
    else
    {
        return false;
    }
}

void test_cases()
{
    bool answer = check_if_anagram("LordVader", strlen("LordVader"), "VaderLord", strlen("VaderLord"));
    assert(answer == true);

    answer = check_if_anagram("silent", strlen("silent"), "listen", strlen("listen"));
    assert(answer == true);

    answer = check_if_anagram("funeral", strlen("funeral"), "real fun", strlen("real fun"));
    assert(answer == true);

    answer = check_if_anagram("Elon Musk", strlen("Elon Musk"), "Muskmelon", strlen("Muskmelon"));
    assert(answer == false);

    answer = check_if_anagram("Tieto", strlen("Tieto"), "Tietonator", strlen("Tietonator"));
    assert(answer == false);

    answer = check_if_anagram("Football", strlen("Football"), "Basketball", strlen("Basketball"));
    assert(answer == false);

    answer = check_if_anagram("F", strlen("F"), "", strlen(""));
    assert(answer == false);
}

int main()
{
    //check_if_anagram("LordVader", strlen("LordVader"), "VaderLord", strlen("VaderLord"));
    test_cases();
}
