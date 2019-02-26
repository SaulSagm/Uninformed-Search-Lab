#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i,height,a=0,b=0,c=0,originb,originc;
    char initial[100],goal[100],letters[4]={'A','B','C','D'};
    
    scanf("%i",&height);
    scanf("%s",&initial);
    scanf("%s",&goal);
    
    for(i=0;i<strlen(initial);i++)
    {
        if(initial[i]==';')
        {
            a++;
        }
    }
    
    char state[height][a+1];
    b=height-1;

    for(i=0;i<strlen(initial);i++)
    {
      if(initial[i]==',')
      {
        b--;
      }
      else
        if(initial[i]==';')
        {
          b=height-1;
          c++;
        }
        else
          if(letters[0]=initial[i]||letters[1]=initial[i]||letters[2]=initial[i]||letters[3]=initial[i])
          {
            state[b][c]=initial[i];
          }
    }
    
    /*for(b=0;b<height;b++)
    {
        for(c=0;c<=a;c++)
        {
            printf("%c \t",state[b][c]);
        }
        printf("\n");
    }*/

    char end[height][a+1];
    b=height-1;
    c=0;
    
    for(i=0;i<strlen(goal);i++)
    {
      if(goal[i]==',')
      {
        b--;
      }
      else
        if(goal[i]==';')
        {
          b=height-1;
          c++;
        }
        else
          if(letters[0]=goal[i]||letters[1]=goal[i]||letters[2]=goal[i]||letters[3]=goal[i])
          {
            end[b][c]=goal[i];
          }
    }
    
    /*for(b=0;b<height;b++)
    {
        for(c=0;c<=a;c++)
        {
            printf("%c \t",end[b][c]);
        }
        printf("\n");
    }*/
    
    for(b=0;b<height;b++)
    {
        for(c=0;c<=a;c++)
        {
            if(state[b][c]!=end[b][c])
            {
              originb=b;
              originc=c;
              b=height;
              c=a+1;
            }
        }
    }
    
    for(b=0;b<height;b++)
    {
        for(c=0;c<=a;c++)
        {
            if(state[originb][originc]==end[b][c]&&state[b][c]==' '&&state[b][c]=='\0')
            {
              printf("(%i,%i)",originc,c);
            }
        }
    }
    
    return 0;
}
