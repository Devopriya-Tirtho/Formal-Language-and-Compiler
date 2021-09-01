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
    scanf("%s",str);

    l=strlen(str);

    if(l>=1)
    {
        expr();
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
    term();
    if(f==1)
    {
        if(str[i]=='+')
        {
            i++;
            term();

            return;
        }
        else if(str[i]=='-')
        {
            i++;
            term();
            return;
        }
        else
        {
            return;
        }
    }
    else
    {
        f=0;
        return;
    }
}

void term()
{
    func();

    if(f==1)
    {
        if(str[i]=='*')
        {
            i++;
            func();
            return;
        }
        else if(str[i]=='/')
        {
            i++;
            func();
            return;
        }
        else
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
    if(str[i]=='(')
    {
        i++;
        expr();
        if(f==1)
        {

            if(str[i]==')')
            {
                i++;
                f=1;
                return;
            }
        }
    }
    else if(str[i]=='a'||str[i]=='b'||str[i]=='c'||str[i]=='d'||str[i]=='e')
    {
        i++;
        f=1;
        return;
    }
    else if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4')
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


