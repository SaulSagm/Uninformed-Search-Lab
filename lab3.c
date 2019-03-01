#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i,j;
    int a=0,b=0;
    int c=0,d=0;
    int height,width;
    int row1=0,column1=0;
    int row2=0,column2=0;
    char initial[20],goal[20];
    
    scanf("%i",&height);
    scanf("%s",&initial);
    scanf("%s",&goal);

    b=strlen(initial);
    c=strlen(goal);

    for(i=0;i<b;i++)
    {
        if(initial[i]==59)
        {
            a++;
        }
    }
    width=a+1;
    
    char *state[height][width];
    char *end[height][width];
    row1=height-1;
    row2=height-1;
    
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            state[i][j]=45;
        }
    }
    
    for(i=0;i<b;i++)
    {
        if(initial[i]==44)
            row1--;
        else
            if(initial[i]==59)
            {
                row1=height-1;
                column1++;
            }
            else
                if(initial[i]==65)
                    state[row1][column1]='A';
                else
                    if(initial[i]==66)
                        state[row1][column1]='B';
                    else
                        if(initial[i]==67)
                            state[row1][column1]='C';
                        else
                            if(initial[i]==68)
                                state[row1][column1]='D';
    }
    
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            printf("%c \t",state[i][j]);
        }
        printf("\n");
    }
    
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            end[i][j]=45;
        }
    }
    
    for(i=0;i<c;i++)
    {
        if(goal[i]==44)
            row2--;
        else
            if(goal[i]==59)
            {
                row2=height-1;
                column2++;
            }
            else
                if(goal[i]==65)
                    end[row2][column2]='A';
                else
                    if(goal[i]==66)
                        end[row2][column2]='B';
                    else
                        if(goal[i]==67)
                            end[row2][column2]='C';
                        else
                            if(goal[i]==68)
                                end[row2][column2]='D';
    }
    
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            printf("%c \t",end[i][j]);
        }
        printf("\n");
    }
    
    if(state[0][1]==end[0][1])
        printf("Iguales");
    else
        printf("Diferentes");
    
    return(0);
}
