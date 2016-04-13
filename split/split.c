#include<stdio.h>
#include<stdlib.h>

main()
{
    char fn[250], nfn[250], word[81], cfn[250], cfn1[250];
    long int size, n, k;
    int i, ch,j=1;
    FILE *f, *ft, *cft, *cft1; //file and temp file

    printf("enter the file you want to split with full path : ");
    scanf("%s", fn);
    printf("enter the number of parts you want to split the file : ");
    scanf("%ld", &n);
    int count[10];
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
        if (ch==EOF)
            break;
        fputc(ch, ft);
        if (ftell(f)==(i*k))
        {
            i = i+1;
            fclose(ft);
            sprintf(nfn, "num%d", i);
            ft=fopen(nfn, "wb");
	    
        }
    }
    
    for(j=1;j<=i;j++) {
        count[j] = 0;
        //cfn = "num"+j;
	sprintf(cfn, "num%d", j);
        cft = fopen(cfn, "r");
	sprintf(cfn1, "num1%d", j);
        cft1 = fopen(cfn1, "wb");
	if(cft) {
            while(!feof(cft)) {
      	        if(fscanf(cft, "%80s", word) != EOF) {
	           count[j]++;	/* got a word, so increment count */
	        }
            }
            fclose(cft);
            printf("\nfile : num%d has word count : %d\n",j,count[j]);
        }
	fprintf(cft1,"%d",count[j]);
	fclose(cft1);
    }
    for(j=1;j<=i;j++){
        printf("\n count[%d] : %d",j,count[j]);
    }
}
