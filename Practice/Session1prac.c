#include<stdio.h>

int main()
{
    FILE *p1,*p2;
    int i;
    char c;
    p1=fopen("input.txt","r");
    p2=fopen("output.txt","w");
    if(!p1)
    {
        printf("File Not Found");
    }
    else
    {
        while((c=(fgetc(p1)))!=EOF)
        {
            if((c=='(')||(c==')'))
            {
                fputc(c,p2);
            }
        }
    }
    fclose(p1);
    fclose(p2);

    p2=fopen("output.txt","r");
    while((c=(fgetc(p2)))!=EOF)
    {
        printf("%c",c);
    }
    fclose(p2);
    return 0;

}
