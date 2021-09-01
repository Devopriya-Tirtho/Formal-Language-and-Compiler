#include<bits/stdc++.h>
using namespace std;

int main()
{
    FILE *p = fopen("inp.txt","r");
    FILE *q = fopen("out.txt", "w");
    char ch;
    int cnt = 1;
    while((ch = fgetc(p)) !=EOF)
    {
        if(ch == '\n')
        {
            fputc(ch,q);
            fprintf(q, "%d ", cnt);
            cnt++;
        }
        else if(ch == '/')
        {
            ch = fgetc(p);
            if(ch == '*')
            {
                bool x = false;
                while(1)
                {
                    ch = fgetc(p);
                    if(x && ch == '/')
                    {
                        break;
                    }
                    else
                    {
                        x = false;
                    }
                    if(ch == '*')
                    {
                        x = true;
                    }
                }
            }
            else
            {
                fputc('/', q);
                fputc(ch, q);
            }
        }
        else
        {
            fputc(ch, q);
        }

    }
    fclose(p);
    fclose(q);

    char temp[100], prev[100];
    int t1 = 0, t2 = 0;
    cnt = 0;
    int turn = 0;
    p = fopen("out.txt", "r");
    int ln = 0;
    char tempc;
    stack<char> st;
    stack<char> ifelse;
    while((ch = fgetc(p)) !=EOF)
    {
        if(ch == '\n')
        {
            ln++;
        }
        if(ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')
        {
            if( ch == '(' || ch == '{' || ch == '[' )
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                if(st.empty())
                {
                    cout << "Unbalanced braces at line " << ln << endl;
                }
                else
                {
                    char x = st.top();
                    if(x != '(')
                    {
                        cout << "Unbalanced braces at line " << ln << endl;
                    }
                    else
                    {
                        st.pop();
                    }
                }
            }
            else if (ch == '}')
            {
                if(st.empty())
                {
                    cout << "Unbalanced braces at line " << ln << endl;
                }
                else
                {
                    char x = st.top();
                    if(x != '{')
                    {
                        cout << "Unbalanced braces at line " << ln << endl;
                    }
                    else
                    {
                        st.pop();
                    }
                }
            }
            else if (ch == ']')
            {
                if(st.empty())
                {
                    cout << "Unbalanced braces at line " << ln << endl;
                }
                else
                {
                    char x = st.top();
                    if(x != '[')
                    {
                        cout << "Unbalanced braces at line " << ln << endl;
                    }
                    else
                    {
                        st.pop();
                    }
                }
            }
        }
      if(ch == tempc)
        {
            if(ch != '=' && !isalnum(ch) && ch != '(' && ch != ')' && ch != '{' && ch != '}' && ch != '[' && ch != ']')
            {
                cout << "Duplication of tokens at line " << ln << endl;
            }
        }
        tempc = ch;
        if(ch == ' ' || ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == '\n')
        {
            if(!strcmp(temp,"if"))
            {
                ifelse.push('i');
            }
            if(!strcmp(temp,"else"))
            {
                if(ifelse.empty())
                {
                    cout << "Unbalanced if else at line " << ln << endl;
                }
                else
                {
                    ifelse.pop();
                }
            }
            if(t1 > 0)
            {
                //printf("%s\n",temp);
                if(!strcmp(temp,prev))
                {
                    cout << "Duplication of tokens at line " << ln << endl;
                }
            }
            memset(prev, 0, sizeof prev);
            for(int i=0; i<strlen(temp); i++)
            {
                prev[i] = temp[i];
            }
            memset(temp, 0, sizeof temp);
            t1 = 0;
        }
        else
        {
            temp[t1++] = ch;
        }
    }


}
