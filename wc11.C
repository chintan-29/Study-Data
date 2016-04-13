#include "stdio.h"
#include "string.h"
#include "stdlib.h"
typedef FILE *stream;
typedef char *string;


int countWords(const char *fileName, char *words[])
{
  stream f;
  char word[100];
  int count= 0,i=0;
  f = fopen(fileName,"r");
  if(f)
  {
    while(!feof(f)) {
      if(fscanf(f,"%s",word)!= EOF) {
        printf("%s\n",word);
        strcpy(words[count],word);
        count++;
      }
    }
  }
  fclose(f);
  return count;
}
// int addWords(const char *fileName, int count)
// {
//   stream f;
//   char word[100];
//   char *words;
//   int count= 0;
//   f = fopen(fileName,"r");
//   if(f)
//   {
//     while(!feof(f)) {
//       if(fscanf(f,"%80s",word)!= EOF) {
//         count++;
//       }
//     }
//   }
//   fclose(instr);
//   return count;
// }
int main()
{
  stream instr;
  int count = 0;
  int i,j;
  char word[81];
  char *words[1000];
  char *string1;
  fprintf(stderr,"reading input file : %s\n","aa.txt");
  fflush(stderr);
  count = countWords("aa.txt",words);
  printf("%d\n",count);
  free(words);
  //instr=fopen("aa.txt", "r");
  //count = ReadWords("aa.txt",words,1000);
  // if(instr)
  // {
  //   while(!feof(instr)) {
  //     if(fscanf(instr, "%80s", word) != EOF) {
  //
	// 				count++;	/* got a word, so increment count */
  //         strcpy(words[i],word);
  //         printf("aaa %s\n",words[i]);
	// 			}
  //   }
  // }


 //  for(i=0;i<count;i++)
 // {
 //   int num = 0;
 //   while(!feof(instr))//this loop searches the for the current word
 //   {
 //    fscanf(instr,"%s",string1);
 //    if(!strcmp(string1,words[i]))//if match found increment num
 //    num++;
 //  }
 //  printf("we found the word %s in the file %d times\n",words[i],num );
 // }
 //  fclose(instr);
 //  printf("\nCount : %d\n",count);
  //while(!instr->eof())
  //{
  //  instr >>word;
  //  count++;
  //}
  printf("Hello World \n");

return 0;
}
// int ReadWords(const char *filename, char *words[], int max_number_of_words)
// {
//     FILE *f = fopen(filename, "rt"); // checking for NULL is boring; i omit it
//     int i;
//     char temp[100]; // assuming the words cannot be too long
//
//     for (i = 0; i < max_number_of_words; ++i)
//     {
//         // Read a word from the file
//         if (fscanf(f, "%s", temp) != 1)
//             break;
//         // note: "!=1" checks for end-of-file; using feof for that is usually a bug
//
//         // Allocate memory for the word, because temp is too temporary
//         strcpy(words[i],temp);
//         //words[i] = strdup(temp);
//     }
//     fclose(f);
//
//     // The result of this function is the number of words in the file
//     return i;
// }
