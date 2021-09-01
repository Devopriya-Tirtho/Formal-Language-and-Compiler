#include<stdio.h>
#include<string.h>

void expr(void);
void term(void);
void func(void);


int f=0;
int i=0;
int l;
char str[20];

int main()
{
    printf("\nEnter String to check expression:\n");
    scanf("%s",str);

    l=strlen(str);

    if(l>=1)
    {
        func();
    }

    else
    {
        printf("\nInvalid String\n");
    }

    if(l==i && f)
    {
        printf("\nValid String\n");
    }
    else
    {
        printf("\nInvalid String\n");
    }

    return 0;

}

void expr()
{
    if(str[i]!='\0')
    {
        term();
        if(f)
        {
            return;
        }
        else
        {
            f=0;
            return;
        }
    }
    else if(str[i]=='\0')
    {
        //i++;
        f=1;
        return;
    }
}
void term()
{
    if(str[i]=='a')
    {
        i++;
        f=1;
        return;
    }
    else
    {
        f=0;
        return;
    }
}

void func()
{
    if(str[i]=='b')
    {
        i++;
        expr();
        if(f)
        {
            return;
        }
        else
        {
            return;
        }
    }
}




