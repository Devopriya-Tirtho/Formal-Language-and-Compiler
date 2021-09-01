#include<stdio.h>
#include<string.h>

void expr(void);
void term(void);
void func(void);


void stat(void);
void asgn_stat(void);
void dscn_stat(void);
void loop_stat(void);
void expn(void);
void relop(void);
void extn1(void);
void extn(void);


int f=0;
int i=0;
int l;
char str[20];

int main()
{
    printf("\nEnter String for assignment/ Loop/ Conditional Statement:\n");
    scanf("%s",str);

    l=strlen(str);

    if(l>=1)
    {
        stat();
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


void stat()
{
    asgn_stat();
    if(f==1)
    {
        return;
    }
    else
    {
        dscn_stat();
        if(f==1)
        {
            return;
        }
        else
        {
            loop_stat();
            if(f==1)
            {
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


void asgn_stat()
{
    if(str[i]=='i')
    {
        i++;
        if(str[i]=='d')
        {
            i++;
            if(str[i]=='=')
            {
                i++;
                expn();
                if(f==1)

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
                f=0;
                return;
            }
        }
        else
        {
            f=0;
            return;
        }
    }
    else
    {
        f=0;
        return;
    }
}



void expn()
{
    expr();
    if(f==1)
    {
        extn();
        if(f==1)
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

void extn()
{
    if(str[i]=='\0')
    {
        f=1;
        return;
    }
    else
    {
        relop();
        if(f==1)
        {
            expr();
            if(f==1)
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
            f=0;
            return;
        }
    }

}


void dscn_stat()
{
    if(str[i]=='i')
    {
        i++;
        if(str[i]=='f')
        {
            i++;
            if(str[i]=='(')
            {
                i++;
                expn();
                if(str[i]==')')
                {
                    i++;
                    stat();
                    if(f==1)
                    {
                        extn1();
                        if(f==1)
                        {
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
                        f=0;
                        return;
                    }
                }
                else
                {
                    f=0;
                    return;
                }
            }
            else
            {
                f=0;
                return;
            }
        }
        else
        {
            f=0;
            return;
        }
    }
    else
    {
        f=0;
        return;
    }
}

void extn1()
{
    if(str[i]!='\0')
    {
        if(str[i]=='e')
        {
            i++;
            if(str[i]=='l')
            {
                i++;
                if(str[i]=='s')
                {
                    i++;
                    if(str[i]=='e')
                    {
                        i++;
                        stat();
                        if(f==1)
                        {
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
                        f=0;
                        return;
                    }
                }
                else
                {
                    f=0;
                    return;
                }
            }
            else
            {
                f=0;
                return;
            }
        }
        else
        {
            f=0;
            return;
        }
    }
    else
    {
        f=1;
        return;
    }
}

void loop_stat()
{
    if(str[i]=='w')
    {
        i++;
        if(str[i]=='h')
        {
            i++;
            if(str[i]=='i')
            {
                i++;
                if(str[i]=='l')
                {
                    i++;
                    if(str[i]=='e')
                    {
                        i++;
                        if(str[i]=='(')
                        {
                            i++;
                            expn();
                            if(f==1)
                            {
                                stat();
                                if(f==1)
                                {
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
                                return;
                            }
                        }
                        else
                        {
                            f=0;
                            return;
                        }


                    }
                    else
                    {
                        f=0;
                        return;
                    }

                }
                else
                {
                    f=0;
                    return;
                }

            }
            else
            {
                f=0;
                return;

            }
        }
        else
        {
            f=0;
            return;

        }
    }
    else if(str[i]=='f')
    {
        i++;
        if(str[i]=='o')
        {
            i++;
            if(str[i]=='r')
            {
                i++;
                if(str[i]=='(')
                {
                    i++;
                    asgn_stat();
                    if(f==1)
                    {
                        if(str[i]==';')
                        {
                            i++;
                            expn();
                            if(f==1)
                            {
                                if(str[i]==';')
                                {
                                    i++;
                                    asgn_stat();
                                    if(f==1)
                                    {
                                        if(str[i]==')')
                                        {
                                            i++;
                                            stat();
                                            if(f==1)
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
                                            f=0;
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
            else
            {
                f=0;
                return;
            }
        }
        else
        {
            f=0;
            return;
        }

    }
    else
    {
        f=0;
        return;
    }

}

void relop()
{
    if(str[i]=='=')
    {
        i++;
        if(str[i]=='=')
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


    else if(str[i]=='!')
    {
        i++;
        if(str[i]=='=')
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

    else if(str[i]=='<')
    {
        i++;
        f=1;
        return;
    }
    else if(str[i]=='>')
    {
        i++;
        f=1;
        return;
    }

    else if(str[i]=='<')
    {
        i++;
        if(str[i]=='=')
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

    else if(str[i]=='>')
    {
        i++;
        if(str[i]=='=')
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
    else
    {
        f=0;
        return;
    }
}

// smpl_expn-----> expr
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
    else if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9')
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

















































































































