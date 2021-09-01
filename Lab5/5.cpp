#include<bits/stdc++.h>
using namespace std;

bool stat(char *inp);
bool loop_stat(char *inp);
bool dcsn_stat(char *inp);
bool asgn_stat(char *inp);
bool expn(char *inp);
bool smpl_expn(char *inp);
bool extn(char *inp);
bool term(char *inp);
bool factor(char *inp);
bool id(char *inp);
bool num(char *inp);
bool extn1(char *inp);

int main()
{
   char inp[100];
   scanf("%s",&inp);

   if(stat(inp)){ printf("Matches grammar\n"); }
   else{ printf("Doesn't matches grammar\n"); }

   return 0;
}

bool asgn_stat(char *inp)
{
   char newx[100]; int c = 0;
   char x[5];
   x[0] = inp[0];//first char
   if(id(x)){//id check
      if(inp[1] == '='){
         for(int i=2; i<strlen(inp); i++){
            newx[c++] = inp[i];//copy full length
         }
         newx[c] = '\0';
         if(expn(newx)){
            return true;
         }
      }
   }
   return false;
}

bool dcsn_stat(char *inp)
{
   //cout << inp << endl;
   char x[100], y[100], z[100]; int c1 = 0, c2 =0, c3 = 0;
   if(inp[0] == 'i' && inp[1] == 'f' && inp[2] == '('){
      int i = 3;
      while(1){
         x[c1++] = inp[i];
         i++;
         if(inp[i] == ')'){break;}
      }
      x[c1] = '\0';
      i++;
      //cout << x << endl;
      if(expn(x)){
         while(1){
            y[c2++] = inp[i];

            i++;
            if(inp[i] == 'e' && inp[i+1] == 'l' && inp[i+2] == 's' && inp[i+3] == 'e'){break;}
         }
         y[c2] = '\0';
         if(stat(y)){
            while(1){
               z[c3++] = inp[i];

               i++;
               if(i >= strlen(inp)){break;}
            }
            z[c3] = '\0';
            if(extn1(z)){
               return true;
            }
         }
      }
   }

   return false;
}

bool loop_stat(char *inp)
{
   char x[100], y[100], z[100], p[100]; int c1 = 0, c2 = 0, c3 =0, c4 = 0;
   if(inp[0] == 'w' && inp[1] == 'h' && inp[2] == 'i' && inp[3] == 'l' && inp[4] == 'e' && inp[5] == '('){
      int i = 6;
      while(1){
         x[c1++] = inp[i];
         i++;
         if(inp[i] == ')'){break;}
      }
      x[c1] = '\0';
      i++;
      if(expn(x)){
         while(1){
            y[c2++] = inp[i];
            i++;
            if(i >= strlen(inp)){break;}
         }
         y[c2] = '\0';
         if(stat(y)){return true;}
      }
   }
   else if(inp[0] == 'f' && inp[1] == 'o' && inp[2] == 'r' && inp[3] == '('){
      int i = 4;
      while(1){
         x[c1++] = inp[i];
         i++;
         if(inp[i] == ';'){break;}
      }
      x[c1] = '\0';
      i++;
      if(asgn_stat(x)){
         while(1){
            y[c2++] = inp[i];
            i++;
            if(inp[i] == ';'){break;}
         }
         i++;
         y[c2] = '\0';
         if(expn(y)){
            while(1){
               z[c3++] = inp[i];
               i++;
               if(inp[i] == ')'){break;}
            }
            i++;
            z[c3] = '\0';
            if(asgn_stat(z)){
               while(1){
                  p[c4++] = inp[i];
                  i++;
                  if(i>=strlen(inp)){break;}
               }
               p[c4] = '\0';
               if(stat(p)){return true;}
            }
         }
      }
   }
   else{
      return false;
   }
}

bool expn(char *inp)
{
   //cout << inp << endl;
   char x[100], y[100]; int c1 = 0, c2 = 0, turn = 1;
   for(int i=0; i<strlen(inp); i++){
      if( (inp[i] == '=' && inp[i+1] == '=') || (inp[i] == '!' && inp[i+1] == '=') || (inp[i] == '>' && inp[i+1] == '=') || (inp[i] == '<' && inp[i+1] == '=') ){
         turn = 2;
      }
      else if(inp[i] == '>' || inp[i] == '<'){
         turn = 2;
      }
      if(turn == 1){
         x[c1++] = inp[i];
      }
      else if(turn == 2){
         y[c2++] = inp[i];
      }

   }
   x[c1] = '\0';
   y[c2] = '\0';
   //cout << x << " " << y << endl;
   if(smpl_expn(x) && extn(y)){ return true;}
   else{ return false;}
}

bool smpl_expn(char *inp)
{
   //cout << inp << endl;
   char x[100], y[100]; int c1 = 0, c2 = 0, turn = 1;
   for(int i=0; i<strlen(inp); i++){
      if( inp[i] == '+' || inp[i] == '-' ){
         turn = 2;
         i++;
      }
      if(turn == 1){
         x[c1++] = inp[i];
      }
      if(turn == 2){
         y[c2++] = inp[i];
      }
      else if(inp[i] == '*' || inp[i] == '/'){break;}
   }
   //a+b ;x=a,y=b;
   x[c1] = '\0';
   y[c2] = '\0';

   if(strlen(y) > 0){
      //cout << x << " " << y << endl;
      if(term(x) && term(y)){ return true;}
      else{ return false;}
   }
   else{
      if(term(x)){ return true;}
      else{ return false;}
   }

}

bool extn(char *inp)
{
   //cout << inp << endl;
   char x[100]; int c1 = 0;
   if(strlen(inp) == 0){return true;}
   if( (inp[0] == '=' && inp[1] == '=') || (inp[0] == '!' && inp[1] == '=') || (inp[0] == '>' && inp[1] == '=') || (inp[0] == '<' && inp[1] == '=')){
      for(int i=2; i<strlen(inp); i++){
         x[c1++] = inp[i];
      }
   }
   else if(inp[0] == '>' || inp[0] == '<'){
      for(int i=1; i<strlen(inp); i++){
         x[c1++] = inp[i];
      }
   }
   x[c1] = '\0';
   //cout << x << endl;
   if(smpl_expn(x)){ return true;}
   return false;
}

bool term(char *inp)
{
   //cout << inp << endl;
   char x[100], y[100]; int c1 = 0, c2 = 0, turn = 1;
   for(int i=0; i<strlen(inp); i++){
      if( inp[i] == '*' || inp[i] == '/' ){
         turn = 2;
         i++;
      }
      if(turn == 1){
         x[c1++] = inp[i];
      }
      if(turn == 2){
         y[c2++] = inp[i];
      }
      else if(inp[i] == '+' || inp[i] == '-'){break;}
   }
   x[c1] = '\0';
   y[c2] = '\0';
   //cout << x << " " << y << endl;
   if(strlen(y) > 0){
      if(factor(x) && factor(y)){ return true;}
      else{ return false;}
   }
   else{
      if(factor(x)){ return true;}
      else{ return false;}
   }

}

bool factor(char *inp)
{
   if(strlen(inp) > 1){
      if(smpl_expn(inp)){return true;}
   }
   if(id(inp) || num(inp)){return true;}
   else{return false;}
}

bool id(char *inp)
{
   //cout << inp << endl;
   if(inp[0] == 'a' || inp[0] == 'b' || inp[0] == 'c' || inp[0] == 'd' || inp[0] == 'e'){ return true;}
   else{ return false;}
}

bool num(char *inp)
{
   if(inp[0] >= '0' && inp[0] <='9'){return true;}
   else{ return false;}
}

bool stat(char *inp)
{
   //cout << inp << endl;
   if(asgn_stat(inp) || dcsn_stat(inp) || loop_stat(inp)){ return true; }
   else{ return false;}
}

bool extn1(char *inp)
{
   char x[100], y[100]; int c1 = 0, c2 = 0;
   if(strlen(inp) == 0){ return true;}
   for(int i=4; i<strlen(inp); i++){
      x[c1++] = inp[i];
   }
   x[c1] = '\0';
   if(stat(x)){ return true;}

   return false;
}
/*
a=b*2+c/3
if(a>=b)
    d=d+1
else
    c=c+1
*/
