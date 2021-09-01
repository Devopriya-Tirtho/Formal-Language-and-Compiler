#include<stdio.h>
int main()
{
    FILE *p1;
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    int x=0;
    int y=0;
    char c;

    p1=fopen("input.txt","r");
    if(!p1)
    {
        printf("the file cannot be opened");
    }
    else
    {
        while((c=fgetc(p1))!=EOF)
        {
            if(c==' ')
            {
                cnt1++;
            }
            if(c=='/')
            {
                c=fgetc(p1);
                if(c=='/')
                {
                    cnt2=1;
                    while(((c=fgetc(p1))!='\n'))
                    {
                        y=1;
                    }
                }
            }

            if(c=='*')
            {

                    while(((c=fgetc(p1))!='*'))
                    {
                        cnt3=1;
                    }
                }



            if(cnt1==1||c=='\n'||(cnt2>0&&y==1)||cnt3==1)
            {
                x=1;
            }
            if(x==0)
            {

                printf("%c",c);

            }
            x=0;

            cnt2=0;
            cnt3=0;


            }

        }
        return 0;
    }

