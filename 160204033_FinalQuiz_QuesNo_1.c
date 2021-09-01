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



//Unbalanced curly Braces error check
void line_no(char arr[])
{
    int count1=0;

    for(int i=0; i!=mt; i++)
    {
        //counting line number
        if(arr[i] == '\n')
        {
            line++;
        }
        for(; arr[i]!='\n'; i++)
        {
            if((arr[i]=='<'&&arr[i+1]=='=')||(arr[i]=='='&&arr[i+1]=='=')||(arr[i]=='<'&&arr[i+1]!='='))
            {
                if((arr[i]=='<'&&arr[i]=='='))
                {
                    count1++;
                }
                if ((arr[i]=='='&&arr[i]=='='))
                {
                    count1++;
                }

            if((arr[i]=='<'&&arr[i+1]!='='))
            {
                count1++;
            }
        }
        }
        printf("Line no. %d : %d",line,count1);








        int main()
        {
            FILE *p1,*p2,*p3,*p4,*p5,*p6;
            char c;
            p1=fopen("input.txt","r");
            if(!p1)
            {
                printf("File not found");
            }
            else
            {
                put_array(p1);
            }
            fclose(p1);

            line_no(char arr[]);

            return 0;
        }



