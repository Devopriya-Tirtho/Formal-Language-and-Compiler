#include<stdio.h>
int main(void)
{
    FILE *p1,*p2;
    char c;
    int x=0;
    int y=0;
    int z=0;
    int flag=0;
    int cnt1=0;
    int cnt2=0;


    p1=fopen("test.c","r");
    p2=fopen("output.txt","w");

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
                cnt1++; // FOR SPACE REDUCTION
            }


            if(c=='/')
            {
                // FOR SINGLE & MULTIPLE LINE COMMENT
                c=fgetc(p1);
                if(c=='/'||c=='*')
                {
                    if(c=='/')
                    {
                        cnt2++;

                        while((c=fgetc(p1))!='\n')
                            y=1;
                    }


                    else if(c=='*')
                    {
                        while((c=fgetc(p1))!='*')
                        {
                            z=1;

                        }
                    }
                }
            }


            //CONDITION FOR NOT PRINTING
            if(cnt1==1||c=='\n'||(cnt2>0&&y==1)||z==1)
            {
                x=1;
            }

            //CONDITION FOR PRINTING
            if(x==0)
            {
                fputc(c,p2);
                printf("%c",c);

            }
            x=0;
            cnt2=0;
            z=0;
        }


    }
    fclose(p1);
    fclose(p2);

    return 0;
}
