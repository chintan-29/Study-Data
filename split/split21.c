#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char *string;

main()
{
    char word[81], a, b;
    char *fn = malloc(205 * sizeof(char));
    char *nfn = malloc(205 * sizeof(char));
    char *cfn = malloc(250 * sizeof(char));
    char *cfn1 = malloc(250 * sizeof(char));
    char *command = malloc(250 * sizeof(char));
    char *command1 = malloc(250 * sizeof(char));
    long int size, n, k;
    int i, ch,j=1;
    FILE *f, *ft, *cft, *cft1, *mrg, *mrg1; //file and temp file
    //char comd[1000];
    char *comd = malloc(10000 * sizeof(char));
    printf("enter the file you want to split with full path : ");
    scanf("%s", fn);
    printf("enter the number of parts you want to split the file : ");
    scanf("%ld", &n);
    char count[10][250];
    f=fopen(fn, "rb");
    if (f==NULL)
    {
        printf("couldn't open file");
        exit(0);
    }

    fseek(f, 0, 2);
    size = ftell(f);
    printf("the size of the file in bytes is : %ld\n", size);

    i = 1;
    k = size/n;
    rewind(f);
    sprintf(nfn, "num%d", i);
    ft = fopen(nfn, "wb");
    while(1)
    {
	
        ch = fgetc(f);
        if (ch==EOF){
	    fclose(ft);
            break;
	}
        fputc(ch, ft);
        if (ftell(f)==(i*k))
        {
            i = i+1;
            fclose(ft);
            sprintf(nfn, "num%d", i);
            ft=fopen(nfn, "wb");
	    
        }
	//fclose(ft);
    }
    
    for(j=1;j<=i;j++) {
        
        //cfn = "num"+j;
	sprintf(cfn, "num%d", j);
	strcpy(count[j],cfn);
	sprintf(command,"bash wc.sh %s",cfn);
	cft = popen(command,"r");
        //cft = fopen(cfn, "r");
	sprintf(cfn1, "num01%d", j);
        cft1 = fopen(cfn1, "w");
	while(1){
      		a = fgetc(cft);
		if(a==EOF)
			break;
      		putc(a, cft1);
   	} 
        pclose(cft);
	fclose(cft1);
    }
   /* for(j=1;j<=i;j++) {
	printf("\ncount[%d] : %s",j,count[j]);
	strcat(comd," ");
	strcat(comd,count[j]);
	printf("\nccomd : %s",comd);
	}

	sprintf(command1,"bash merge.sh %s",comd);
	mrg = popen(command,"r");
	mrg1 = fopen("out.txt","r");
	while(1){
      		b = fgetc(mrg);
		if(b==EOF)
			break;
      		putc(b, mrg1);
   	} 
        pclose(mrg);
	fclose(mrg1);*/
	free(comd);
	free(command);
	free(fn);
	free(nfn);
	free(cfn);
	free(cfn1);
	free(command1);
 
}
