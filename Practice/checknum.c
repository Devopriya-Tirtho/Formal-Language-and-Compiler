#include<stdio.h>
#include<ctype.h>

int main()
{
    FILE *p1;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int flag4=0;
    int flag5=0;
    int flag6=0;
    int x=0;
    char c;

    p1=fopen("input.txt","r");
    if(!p1)
    {
        printf("there is no input file");
    }
    else
    {
      while((c=fgetc(p1))!=EOF)
      {
          if((c=='.'))
          {
              flag1=1;
              printf("%c",c);
          }
          else if(isdigit(c))
          {
              flag2=1;
              printf("%c",c);
          }
          if(flag1==1)
          {
              c=fgetc(p1);

              if(!isdigit(c))
              {
                  flag3=0;
              }
              else if(isdigit(c))
              {
                  printf("%c",c);
                  printf("%c",c);

                    flag3=1;
              }
          }

          if(flag2=1)
          {
              c=fgetc(p1);
              if(isdigit(c))
              {

                    flag3=1;
              }
              else if((c=='.')&&(isdigit(c=fgetc(p1))))
              {


                    flag3=1;
              }
          }
      if (flag3==1)
      {
          printf("%c",c);
      }
      flag3=0;
      flag1=0;
      flag2=0;
      }



    }
fclose(p1);
return 0;
}
