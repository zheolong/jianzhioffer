#include<stdio.h>
#include<stdlib.h>
#include<string>

void reverse(char data[], int start, int end);
void reverse_sentence(char data[]);

int main(void)
{
    char sentence[] = "I am student";
    reverse_sentence(sentence);
    printf("%s",sentence);
}

void reverse_sentence(char data[])
{
    if (data == NULL)
        return;

    int n = strlen(data);

    int word_start = 0;
    int word_end = 0;
    
    while (word_start <= word_end && word_end <= n - 1)
    {
        while(word_end <= n-1 && data[word_end] != ' ') word_end++;
        reverse(data, word_start, word_end - 1);
        word_start = ++word_end;
    }

    reverse(data, 0, n-1);
}

void reverse(char data[], int start, int end)
{
    if (start >= end)
        return;

    int i = start;
    int j = end;
    while(i < j) {
        char tmp = data[i]; 
        data[i] = data[j];
        data[j] = tmp;
        i++;
        j--;
    }
}
