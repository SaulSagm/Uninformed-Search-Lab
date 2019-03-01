#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i,j;
    int lim,flag=1,rep=0;
    int x,y;
    int a=0,b=0;
    int c=0,d=0;
    int e=0,f=0;
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
            a++;
        else
            if(initial[i]==44)
                e++;
    }
    
    for(i=0;i<c;i++)
    {
        if(goal[i]==59)
            d++;
        else
            if(goal[i]==44)
                f++;
    }
    
    if(a==d&&e<=height-1&&f<=height-1)
    {
        width=a+1;
        
        char *state[height][width];
        char *end[height][width];
        row1=height-1;
        row2=height-1;
        
        for(i=0;i<height;i++)
        {
            for(j=0;j<width;j++)
                state[i][j]=45;
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
                printf("%c \t",state[i][j]);
            printf("\n");
        }
        
        for(i=0;i<height;i++)
        {
            for(j=0;j<width;j++)
                end[i][j]=45;
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
                printf("%c \t",end[i][j]);
            printf("\n");
        }
        
        lim=height*width;   

        /*for(i=0;i<height;i++)
        {
            for(j=0;j<width;j++)
            {
                if(state[i][j]==end[i][j])
                {
                    flag++;
                    printf("Iguales \n");
                }
                else
                {
                    i=height;
                    j=width;
                    printf("No iguales \n");
                }
            } 
        }
        printf("%i",flag);*/
        
        while(flag<lim)
        {
            for(i=0;i<height;i++)
            {
                for(j=0;j<width;j++)
                {
                    if(state[i][j]==end[i][j])
                    {
                        flag++;
                        //if(flag==lim)
                            //printf("Iguales \n");
                    }
                    else
                    {
                        //printf("No iguales \n");
                        i=height;
                        j=width;
                        flag=1;
                        rep=1;
                    }
                }
            }
            
            while(rep==1)
            {
                for(j=0;j<width;j++)
                {
                    for(i=0;i<height;i++)
                    {
                        if(state[i][j]!=end[i][j])
                        {
                            if(state[i][j]=='-')
                            {
                                x=i;
                                y=j;
                                for(j=0;j<width;j++)
                                {
                                    for(i=height-1;i>=0;i--)
                                    {
                                        if(state[i][j]==end[x][y])
                                        {
                                            printf("(%i, %i);",j,y);
                                            state[x][y]=end[x][y];
                                            state[i][j]='-';
                                            i=-1;
                                            j=width;
                                            rep=0;
                                        }
                                    }
                                }
                                i=x;
                                j=y;
                            }
                            else
                                if(end[i][j]=='-')
                                {
                                    x=i;
                                    y=j;
                                    for(j=0;j<width;j++)
                                    {
                                        for(i=height-1;i>=0;i--)
                                        {
                                            if(end[i][j]==state[x][y])
                                            {
                                                printf("(%i, %i);",y,j);
                                                state[i][j]=end[i][j];
                                                state[x][y]='-';
                                                i=-1;
                                                j=width;
                                                rep=0;
                                            }
                                        }
                                    }
                                    i=x;
                                    j=y;
                                }
                        }
                    }
                }
            }
        }
    }
    else
        printf("No solution found \n");
        
    return(0);
}
