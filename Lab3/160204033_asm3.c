/*
Name: Devopriya Tirtho
ID: 160204033
Lab Group: A2
Session: 03
*/
#include<stdio.h>
#include<string.h>
//Symbol Table -- i(SerialNumber),id,category,type,scope
struct table
{
    int i;
    char id[50];
    char category[50];
    char type[50];
    char scope[50];
};

typedef struct table table;

table symbol_table[10000];
int si=0;//Total Number of findings
int mt=0;
char modified_token[10000];


//Insert Into Table
void insert(char id[], char cat[], char type[], char scope[])
{
    strcpy(symbol_table[si].id, id);
    strcpy(symbol_table[si].category, cat);
    strcpy(symbol_table[si].type, type);
    strcpy(symbol_table[si].scope, scope);
    symbol_table[si].i = ++si;
}

//Deleting Local Variables
void delete_local_variables()
{
    for(int i=0; i<si; i++)
    {
        if(!(strcmp(symbol_table[i].scope, "global")))
            printf("%d.\t%s\t%s\t%s\t\t%s\n", symbol_table[i].i, symbol_table[i].id,symbol_table[i].category, symbol_table[i].type, symbol_table[i].scope);
    }
    printf("\n");
}

//search for same named functions/variables if so skip with the previous string like(')',;....)
int search_table(char id[], char scope[])
{
    int i;
    for(i=0; i<si; i++)
        if( strcmp(symbol_table[i].id, id) == 0 && (strcmp(symbol_table[i].scope, scope)==0 || strcmp(symbol_table[i].category, "func")==0) )
            return symbol_table[i].i;
    return 0;
}


//function for creating symbol table
void create_symbol_table()
{
    char id[50],category[50],type[50],scope[50],new_scope[50];
    int i, j,k, idname, type_name, match, p;
    //default assigning as global
    strcpy(scope, "global");
    strcpy(new_scope, "global");

    for(p=0; p<mt; p++)
    {
        idname=0;
        type_name=0;


        if(modified_token[p] == '[' && modified_token[p+1]=='i' && modified_token[p+2]=='d')
        {
            for(i=p+4; modified_token[i] != ']'; i++)
                id[idname++] = modified_token[i];
            id[idname] = '\0';

            //[id x1][(]
            k = i+2;


            while(modified_token[k]!=')')
            {
                k++;
            }
            if(modified_token[i+2] == '(')
            {
                strcpy(category, "func");
                if(modified_token[k+3] != ';')
                {
                    strcpy(scope, "global");
                    strcpy(new_scope, id);
                }
            }
            else
            {
                strcpy(category, "var");
            }

            j = p-1;
            while(modified_token[j] != '[')
            {
                j--;
            }
            j++;

            for(; modified_token[j] != ']'; j++)
                type[type_name++] = modified_token[j];
            type[type_name] = '\0';


            match = search_table(id, scope);

            if(match==0)
            {
                insert(id, category, type, scope);

            }
            //assigning changed scope
            strcpy(scope, new_scope);
        }

    }

}



//Function for displaying the symbol table
void display()
{
    int i;
    for(i=0; i<si; i++)
        printf("%d.\t%s\t%s\t%s\t\t%s\n", symbol_table[i].i, symbol_table[i].id,symbol_table[i].category, symbol_table[i].type, symbol_table[i].scope);
    printf("\n");
}



int main()
{
    FILE *p1;
    char c;
    char first;
    char second;
    p1=fopen("input.txt","r");
    if(!p1)
    {
        printf("File not found");
    }
    else
    {
        while((c=fgetc(p1))!=EOF)
        {
            //Creating the modified stream of tokens
            if(c=='[')
            {
                first=fgetc(p1);
                second=fgetc(p1);
                if((first=='i')&&(second=='d'))
                {
                    modified_token[mt]='[';
                    mt++;
                    modified_token[mt]='i';
                    mt++;
                    modified_token[mt]='d';
                    mt++;

                    while((c=fgetc(p1))!=']')
                    {
                        modified_token[mt]=c;
                        mt++;
                    }
                    modified_token[mt]=']';
                    mt++;
                }
                else
                {
                    modified_token[mt]='[';
                    mt++;
                    while((c=fgetc(p1))!=' ');
                    while((c=fgetc(p1))!=']')
                    {
                        modified_token[mt]=c;
                        mt++;
                    }
                    modified_token[mt]=']';
                    mt++;
                }
            }

        }

        //Printing the modified stream of tokens
        printf("Modified Token Stream:\n\n%s\n\n", modified_token);

        create_symbol_table();

        printf("\n\nSymbol Table: \n");
        //for display
        display();
        //for deleting local variables
        delete_local_variables();
    }
    return 0;
}
