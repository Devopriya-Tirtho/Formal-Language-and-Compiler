/*
Name: Devopriya Tirtho
ID: 160204033
Lab Group: A2
Session: 04
Question: Lab Assignment(04)
*/
#include<bits/stdc++.h>
using namespace std;

char tnum[20];
int num=1;
char modified_token[10000];
int mt=0;



//File to array
void put_array(FILE *f1)
{
    char c;
    char next;
    while((c=fgetc(f1))!=EOF)
    {
        modified_token[mt]=c;
        mt++;
    }
    modified_token[mt]='\0';
    fclose(f1);
    printf("Code Stream:\n\n%s\n\n", modified_token);

}


//putting line number
void put_line_number(FILE *f1,FILE *f2)
{
    char c;
    while((c=fgetc(f1))!=EOF)
    {
        itoa(num,tnum,10);

        for(int i=0; i<strlen(tnum); i++)
        {
            fputc(tnum[i],f2);
        }
        fputc(':',f2);
        while(c!='\n')
        {
            fputc(c,f2);
            c=fgetc(f1);
        }
        fputc('\n',f2);
        num++;
    }
    fclose(f1);
    fclose(f2);
}


//remove extra spaces and comments
void remove_comment_extra_space(FILE *f1,FILE *f2)
{
    char c;
    while((c=fgetc(f1))!=EOF)
    {
        if((c=='/')&&(c=fgetc(f1)=='*'))
        {
            while((c=fgetc(f1))!='/');
            c=fgetc(f1);
        }
        if(c==' ')
        {
            fputc(c,f2);
            while((c=fgetc(f1))==' ');

        }
        fputc(c,f2);
    }
    fclose(f1);
    fclose(f2);
}


//Unbalanced curly Braces error check
void error_check(char arr[])
{
    int cnt3=0;
    char c;
    int cnt1=0;
    int cnt2=0;
    int cnt4=0;
    int flag=0;
    char line_num;
    char line_num1;
    int line=1;
    stack<char> st;
    int len =0;

    for(int i=0; i!=mt; i++)
    {
        //counting line number
        if(arr[i] == '\n')
        {
            line++;
        }

        //error fixing for unmatched braces
        if(arr[i] == '(' || arr[i] == ')' || arr[i] == '{' || arr[i] == '}' || arr[i] == '[' || arr[i] == ']')
        {
            if( arr[i] == '(' || arr[i] == '{' || arr[i] == '[' )
            {
                st.push(arr[i]);
            }
            else if (arr[i] == ')')
            {
                if(st.empty())
                {
                    printf("Misplaced ')' at Line: %d\n",line);
                }
                else
                {
                    char x = st.top();
                    if(x != '(')
                    {
                        printf("Misplaced ')' at Line: %d\n",line);
                    }
                    else
                    {
                        st.pop();
                    }
                }
            }
            else if (arr[i] == '}')
            {
                if(st.empty())
                {
                    printf("Misplaced '}' at Line: %d\n",line);
                }
                else
                {
                    char x = st.top();
                    if(x != '{')
                    {
                        printf("Misplaced '}' at Line: %d\n",line);
                    }
                    else
                    {
                        st.pop();
                    }
                }
            }
            else if (arr[i] == ']')
            {
                if(st.empty())
                {
                    printf("Misplaced ']' at Line: %d\n",line);
                }
                else
                {
                    char x = st.top();
                    if(x != '[')
                    {
                        printf("Misplaced ']' at Line: %d\n",line);
                    }
                    else
                    {
                        st.pop();
                    }
                }
            }
        }


        //unmatched else check
        if(arr[i]=='i'&&arr[i+1]=='f'&&(arr[i+2]==' '||arr[i+2]=='('))
        {
            cnt3=1;
        }

        if(arr[i]=='e'&&arr[i+1]=='l'&&arr[i+2]=='s'&&arr[i+3]=='e'&&(arr[i+4]==' '||arr[i+4]=='('||arr[i+4]!='('))
        {
            if(cnt3==0)
            {
                printf("Unmatched else at line: %d \n",line);
            }
            else
            {
                cnt3=0;
            }
        }


        //checking the extra ; in for loop
        if(arr[i]=='f'&&arr[i+1]=='o'&&arr[i+2]=='r'&&(arr[i+3]==' '||arr[i+4]=='(')||(arr[i+3]=='('))
        {
            for(int l=i+3; arr[l]!=')'; l++)
            {
                if(arr[l]==';')
                {
                    cnt4++;
                    if(cnt4>2)
                    {
                        printf("Error in for loop for unbalanced ; at line: %d\n",line);
                    }

                }

            }
            cnt4=0;
        }


        //checking duplication of tokens for operators, semi-colons and commas
        if(arr[i]==';'||arr[i]=='='||arr[i]=='+'||arr[i]=='-'||arr[i]=='*'||arr[i]=='/'||arr[i]=='%'||arr[i]=='.'||arr[i]==','||arr[i]=='<'||arr[i]=='<'||arr[i]=='"')
        {

            //duplication of semi colons
            if(arr[i]==';')
            {

                if((arr[i-1]=='('||arr[i-1]==' ')&&arr[i-2]=='r'&&arr[i-3]=='o'&&arr[i-4]=='f')
                {
                    break;
                }
                for(int m=i+1; arr[m]!=';';)
                {
                    if(isalnum(arr[m]))
                    {
                        flag=1;

                    }
                    m++;
                }
                if (flag==0)
                {
                    printf("Duplicate Token at line: %d\n",line);
                }
                flag=0;
            }
        }


        //duplication of =..... same for other operators .. checked if in if-else or for loop
        if(arr[i]=='=')
        {
            for(int j=i; arr[j]!=':'; j--)
            {
                if(arr[j]=='f')
                {
                    if(arr[j-1]=='i')
                    {
                        if(arr[j-2]==' ')
                        {
                            break;
                        }
                    }
                }
            }
            for(int j=i; arr[j]!='\n'; j--)
            {
                if(arr[j]=='r')
                {
                    if(arr[j-1]=='o')
                    {
                        if(arr[j-2]=='f')
                        {
                            if(arr[j-3]==' ')
                            {
                                break;
                            }
                        }
                    }
                }
            }
            for(int m=i+1; arr[m]!='=';)
            {
                if(isalnum(arr[m]))
                {
                    flag=1;

                }
                m++;
            }
            if (flag==0)
            {
                printf("Duplicate Token at line: %d\n",line);
            }
            flag=0;
        }




        //duplication check for int keyword
        if(arr[i]=='i'&&arr[i+1]=='n'&&arr[i+2]=='t')
        {
            if(arr[i+3]==' ')
            {
                if(arr[i+4]==arr[i]&&arr[i+5]==arr[i+1]&&arr[i+6]==arr[i+2]&&arr[i+7]==' ')
                {
                    printf("Duplicate Token at line: %d\n",line);
                }
            }

        }


        //duplication check for float keyword
        if(arr[i]=='f'&&arr[i+1]=='l'&&arr[i+2]=='o'&&arr[i+3]=='a'&&arr[i+4]=='t')
        {
            if(arr[i+5]==' ')
            {
                if(arr[i+6]==arr[i]&&arr[i+7]==arr[i+8]&&arr[i+9]==arr[i+10]&&arr[i+11]==' ')
                {
                    printf("Duplicate Token at line: %d\n",line);
                }
            }

        }


        //duplication check for double keyword
        if(arr[i]=='d'&&arr[i+1]=='o'&&arr[i+2]=='u'&&arr[i+3]=='b'&&arr[i+4]=='l'&&arr[i+5]=='e')
        {
            if(arr[i+6]==' ')
            {
                if(arr[i+7]==arr[i]&&arr[i+8]==arr[i+1]&&arr[i+9]==arr[i+2]&&arr[i+10]==arr[i+3]&&arr[i+11]==arr[i+4]&&arr[i+11]==arr[i+5]&&arr[i+11]==' ')
                {
                    printf("Duplicate Token at line: %d\n",line);
                }
            }

        }


    }

    printf("\n");
}


int main()
{
    FILE *p1,*p2,*p3,*p4,*p5,*p6;
    char c;
    p1=fopen("input.txt","r");
    p2=fopen("output1.txt","w");
    if(!p1)
    {
        printf("File not found");
    }
    else
    {
        put_line_number(p1,p2);

    }

    fclose(p1);
    fclose(p2);

//function call for removing comment and spaces
    p3=fopen("output1.txt","r");
    p4=fopen("output2.txt","w");
    remove_comment_extra_space(p3,p4);



    fclose(p3);
    fclose(p4);

//Put the file in array
    p5=fopen("output2.txt","r");
    put_array(p5);
    fclose(p5);


//error check
    error_check(modified_token);


    return 0;
}


