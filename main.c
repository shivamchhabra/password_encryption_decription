#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char pass[50][60], id[50][60];
int top=0;

void chars(int i, char enpass[60])
{
    switch(i)
    {
        case 1:
        strcat(enpass, "!");
        break;
        case 2:
        strcat(enpass, "@");
        break;
        case 3:
        strcat(enpass, "#");
        break;
        case 4:
        strcat(enpass, "$");
        break;
        case 5:
        strcat(enpass, "%");
        break;
        case 6:
        strcat(enpass, "^");
        break;
        case 7:
        strcat(enpass, "&");
        break;
        case 8:
        strcat(enpass, "*");
        break;
        case 9:
        strcat(enpass, "(");
        break;
        case 0:
        strcat(enpass, ")");
        break;
    }
}

void encryption(char pass[20])
{
    int i=0;
    char enpass[60]="";
    while(pass[i]!='\0')
    {
        int en=pass[i++];
        int i,j,k;
       if (en>=100)
       {
         i=en/100;
         en=en%100;
       }
       else
        {
          i=0;
        }
      if(en>=10)
       {
         j=en/10;
         en=en%10;
       }
       else
       {
           j=0;
       }
       k=en;
      chars(i, enpass);
      chars(j, enpass);
      chars(k, enpass);
    }
    printf("Your Encrypted password is\n%s\n", enpass);
    strcpy(pass, enpass);
}

int dechars(char ch)
{
    switch(ch)
    {
     case '!':
        return 1;
        break;
     case '@':
        return 2;
        break;
     case '#':
        return 3;
        break;
     case '$':
        return 4;
        break;
     case '%':
        return 5;
        break;
     case '^':
        return 6;
        break;
     case '&':
        return 7;
        break;
     case '*':
        return 8;
        break;
     case '(':
        return 9;
        break;
     case ')':
        return 0;
        break;

    }
}

void decription(char enpass[60])
{
    char depass[60]="";
    int l=0;
    while(enpass[l]!='\0')
    {
       int i=dechars(enpass[l++]);
       int j=dechars(enpass[l++]);
       int k=dechars(enpass[l++]);
       int itoc=k;
       itoc=i*100+j*10+k;
       char ch=itoc;
       strncat(depass, &ch,1);
    }
    strcpy(enpass,depass);
    printf("decoded password is %s\n", depass);
}

void login()
{
    char id1[60], pass1[60];
    printf("Enter your Id here\n");
    scanf("%s", &id1);
    printf("Enter your password please\n");
    scanf("%s", &pass1);
    int i=0,count=0;
    while(i<=top)
    {
        if(strcmp(id1,id[i])==0)
            {
                count++;
                printf("before decription your password is %s\n", pass[i]);
                decription(pass[i]);
                printf("after decription your password is %s\n", pass[i]);
                if(strcmp(pass[i],pass1)==0)
                {
                    printf("You are logged in!!\nHi %s\n", id1);
                    return;

                }
                else
                {
                    printf("Incorrect password!!\n");
                }
             }

        i++;
    }
    if(count==0)
    {
        printf("Incorrect Id\n");
    }
}

void createacc()
{
    char id1[60], pass1[60];
    printf("Enter your Id here\n");
    scanf("%s", &id1);
    printf("Enter your password please\n");
    scanf("%s", &pass1);
    strcpy(id[top],id1);
    encryption(pass1);
    strcpy(pass[top], pass1);
    top++;
}




int main()
{
    int j,k,check,count=0;
    while(count==0)
    {
      printf("Enter 1-login 2-createaccount 3-stop\n");
      scanf("%d", &check);
      switch(check)
      {
        case 1:login();
        break;
        case 2:createacc();
        break;
        case 3:count++;
        break;
        default:printf("You have pressed wrong key!!");
        break;
      }

    }


}
