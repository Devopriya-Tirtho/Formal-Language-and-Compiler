// Name: Devopriya Tirtho
// ID: 160204033
// Lab Group: A2

#include<stdio.h>
int main()
{
    FILE *p1;
    char c;
    int cnt1=0;
    int y=0;
    int x=0;

    p1=fopen("input.txt","r");
    if(!p1)
    {
        printf("File no Found");
    }
    else
    {
       while((c=fgetc(p1))!=EOF)
       {

            if(c=='\n')
            {
                cnt1++;
            }
            if(c=='/')
            {
                c=fgetc(p1);
                if(c=='/')
                {
                    while(((c=fgetc(p1))!='\n'));
                    cnt1=cnt1-1;

                }
            }


           if(c=='#')
           {
               printf("Header Files: ",c);
               while((c=fgetc(p1))!='<');
               while((c=fgetc(p1))!='>')
               {
                   printf("%c",c);
               }
           }

       }
    }
     printf("\n");
 printf("Total Executable Lines: ");
 printf("%d",cnt1);
    fclose(p1);

    return 0;
}

