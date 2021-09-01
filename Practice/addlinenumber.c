#include<stdio.h>
int main()
{
    FILE *p1,*p2;
    char c;
    char i[10]={1,2,3,4,5,6,7,8,9,10,11};

    p1=fopen("input.txt","r");
    p2=fopen("output.txt","w");
    if(!p1)
    {
        printf("File no Found");
    }
    else
    {
        fputc(i[0],p2);
       while((c=fgetc(p1))!=EOF)
       {
            while((c!='\n'))
            {
                fputc(c,p2);
                c=fgetc(p1);
                if(c=='\n')
                {
                    fputc('\n',p2);
                    for(int j=1;j<10;j++)
                    {
                        fputc(i[j],p2);
                        break;
                    }

                }
            }


       }
    }
    fclose(p1);
    fclose(p2);

    p2=fopen("output.txt","r");
    while((c=fgetc(p1))!=EOF)
    {
        printf("%c",c);
    }
    fclose(p2);
    return 0;
}
