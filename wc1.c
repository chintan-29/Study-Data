#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *words[2000];

    // Read the file; store all words in the list
    int number_of_words = ReadWords("aa.txt", words, 2000);
    int i;
    // Now count and print the number of occurrences for each word
    for (i = 0; i < number_of_words; i++)
    {
        int n = CountOccurrences(words[i], "aa.txt");
        printf("we found the word %s in the file %d times\n", words[i], n);
    }

    // Deallocate dynamically allocated memory
    Cleanup(words, number_of_words);
}
int CountOccurrences(char *words[], const char *filename)
{
  FILE *in_file = fopen(filename, "r");
  char *string;
  int num = 0;
  if (in_file == NULL)
  {
      printf("Error file missing\n");
      exit(-1);
  }
  while(!feof(in_file))//this loop searches the for the current word
  {
      fscanf(in_file,"%s",string);
      if(!strcmp(string,words))//if match found increment num
      num++;
  }
  fclose(in_file);
  return num;
}
int ReadWords(const char *filename, char *words[], int max_number_of_words)
{
    FILE *f = fopen(filename, "rt"); // checking for NULL is boring; i omit it
    int i;
    char temp[100]; // assuming the words cannot be too long

    for (i = 0; i < max_number_of_words; ++i)
    {
        // Read a word from the file
        if (fscanf(f, "%s", temp) != 1)
            break;
        // note: "!=1" checks for end-of-file; using feof for that is usually a bug

        // Allocate memory for the word, because temp is too temporary
        words[i] = strdup(temp);
    }
    fclose(f);

    // The result of this function is the number of words in the file
    return i;
}

/*int main(int argc, char const *argv[])
{
int num =0;
char word[2000];
char *string;

FILE *in_file = fopen("words.txt", "r");

if (in_file == NULL)
{
    printf("Error file missing\n");
    exit(-1);
}

scanf("%s",word);

printf("%s\n", word);

while(!feof(in_file))//this loop searches the for the current word
{
    fscanf(in_file,"%s",string);
    if(!strcmp(string,word))//if match found increment num
    num++;
}
printf("we found the word %s in the file %d times\n",word,num );
return 0;
}*/
