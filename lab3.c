#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i,j;
    int a=0,b=0,c=0;
    int height,width;
    int row=0,column=0;
    char initial[10],goal[10];
    
    scanf("%i",&height);
    scanf("%s",&initial);
    scanf("%s",&goal);

    b=strln(initial);
    c=strln(goal);

    for(i=0;i<strlen(initial);i++)
    {
        if(initial[i]==';')
        {
            a++;
        }
    }
    width=a+1;
    
    char *state[height][width];
    row=height-1;
    
    for(i=0;i<b;i++)
    {
        switch(initial[i])
        {
            case(44):
                row--;
            break;
            case(59):
                row=height-1;
                column++;
            break;
            case(65):
                state[row][column]=65;
            break;
            case(66):
                state[row][column]=66;
            break;
            case(67):
                state[row][column]=67;
            break;
            case(68):
                state[row][column]=68;
            break;
            case(40):
                if(initial[i+1]==41)
                {
                    state[row][column]=32;
                }
            break;
            case(88):
                state[row][column]=32;
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
