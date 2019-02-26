#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i,b,height,a=0,c=0;
    char initial[10],goal[10];
    
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
        switch(state[b][c])
        {
            case(','):
                b--;
            break;
            case(';'):
                b=(height-1);
                c++;
            break;
            case('A'):
                state[b][c]=initial[i];
            break;
            case('B'):
                state[b][c]=initial[i];
            break;
            case('C'):
                state[b][c]=initial[i];
            break;
            case('D'):
                state[b][c]=initial[i];
            break;
            case('('):
                if(initial[i+1]==')')
                {
                    state[b][c]=' ';
                }
            break;
            case('X'):
                state[b][c]=' ';
            break;
        }
    }
    
    for(b=0;b<height;b++)
    {
        for(c=0;c<=a;c++)
        {
            if(state[b][c]!='A'&&state[b][c]!='B'&&state[b][c]!='C'&&state[b][c]!='D');
            {
                state[b][c]='-';
            }
        }
    }
    
    for(b=0;b<height;b++)
    {
        for(c=0;c<=a;c++)
        {
            printf("%c \t",state[b][c]);
        }
        printf("\n");
    }

    return(0);
}
