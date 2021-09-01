/*
Name: Devopriya Tirtho
ID: 160204033
Lab Group: A2
Exam: Final Quiz Course No: CSE4130 Session: Fall 2019
*/
#include<bits/stdc++.h>
using namespace std;


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


void line_no(char arr[])
{
    int line=1;
    int count1=0;
    FILE *p2;
    p2=fopen("output.txt","w");
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
        fputw(line,p2);
        fputw(count1,p2);

    }
    fclose(p2);



}



        int main()
        {
            FILE *p1;
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

            line_no(modified_token);

            return 0;
        }



