#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char *string;
typedef FILE *stream;
main()
{
    stream instr,f, ft, cft, cft1;


    long int size, n, k;
    int i, ch,j=1;
  char word[81],fn[250], nfn[250], cfn[250], cfn1[250], command[100], command1[250],a,b;
    //printf("enter the file you want to split with full path : ");
    //scanf("%s", fn);
    //printf("enter the number of parts you want to split the file : ");
    //scanf("%ld", &n);
    char count[100][250];
  //char *words[1000];
  //char *string1;
  //fprintf(stderr,"reading input file : %s\n","aa.txt");
  //fflush(stderr);
  //double time1 = CkWallTimer();
  strcpy(command1, "split -n 5 -a 3 -d input/aa.txt input/num");
  system(command1);
    
   for(j=0;j<5;j++) {
	printf("hello");
        //cfn = "num"+j;
        sprintf(cfn, "input/num%.3d", j);
        strcpy(count[j],cfn);
        sprintf(command,"bash wc.sh %s",cfn);
        cft = popen(command,"r");
        //cft = fopen(cfn, "r");
        sprintf(cfn1, "output/outnum%.3d", j);
        cft1 = fopen(cfn1, "w");
        while(1){
                a = fgetc(cft);
                if(a==EOF)
                        break;
                putc(a, cft1);
        }
        pclose(cft);
        fclose(cft1);
//      remove(cfn);
    }


  /*if(instr)
  {
    while(!feof(instr)) {
      if(fscanf(instr, "%80s", word) != EOF) {
                                        count++;        
                                }
    }
  }*/
  //double time2 = CkWallTimer();
  //printf("\n time : %f\n",(time2-time1));
  
}

