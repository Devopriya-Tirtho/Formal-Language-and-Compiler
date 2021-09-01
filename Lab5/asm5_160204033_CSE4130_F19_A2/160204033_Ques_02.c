#include<stdio.h>
#include<string.h>

void A(void);
void X(void);


int f=0;
int i=0;
int l;
char str[20];

int main()
{
    printf("\nEnter String to check:\n");
    scanf("%s",str);

    l=strlen(str);

    if(l>=1)
    {
        A();
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


void A()
{
    if(l==2)
    {
        if(str[i]=='a'&&str[i+1]=='d')
        {
            i=2;
            f=1;
            return;
        }
        else
        {
            f=0;
            return;
        }
    }
    else
    {
        if(str[i]=='a')
        {
            i++;
            X();
            if(f=1 && str[i]=='d')
            {
                i++;
                //printf("%d%c",i,str[i]);
                f=1;
                return;
            }
            else
            {
                f=0;
                return;
            }
        }
    }
}

void X()
{
    if(str[i]=='b')
    {
        i++;
        if(str[i]=='b')
        {
            i++;
            f=1;
            X();
        }
        else if(str[i]=='c')
        {
            i++;
            f=1;
            X();
        }
        else
        {
            f=0;
            return;
        }
    }
    else if(str[i]!='b')
    {
        //i++;
        f=1;
        return;
    }


}






































