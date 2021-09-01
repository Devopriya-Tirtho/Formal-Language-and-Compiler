/*
Name: Devopriya Tirtho
ID: 160204033
Lab Group: A2
Exam: Final Quiz Course No: CSE4130 Session: Fall 2019
*/

#include<stdio.h>
#include<string.h>

void E(void);
void A(void);
void B(void);


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
        E();
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


void E()
{
    if(str[i]=='a')
    {
        i++;
        A();
        if(f)
        {
            return;
        }
        else
        {
            return;
        }
    }


    else if(str[i]=='b')
    {
        i++;
        A();
        if(f)
        {
            B();
            if(f)
            {
                return;
            }
            else
            {
                return;
            }
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


void A()
{
    if(str[i]=='b')
    {
        i++;
        f=1;
       if(str[i]=='b')
       {
           A();
       }
        return;
    }
    else
    {
        f=0;
        return;
    }

}

void B()
{
    if(str[i]!='\0')
    {
        if(str[i]=='a')
        {
            f=1;
            i++;
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
        f=1;
        return;
    }
}

















