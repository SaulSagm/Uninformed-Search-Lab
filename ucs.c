#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,k=0,m=0;
    int lim,flag=1,rep=0;
    int x,y;
    int cost=0;
    int a=0,b=0;
    int c=0,d=0;
    int e=0,f=0;
    int height,width,length;
    int row1=0,column1=0;
    int row2=0,column2=0;
    int coord[20];
    char initial[20],goal[20],**state,**end;
    
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
        
        state = (char **)malloc(height * sizeof(int *)); 

        for (i = 0; i < height; ++i)
            state[i] = (char *)malloc(width * sizeof(int)); 

        end = (char **)malloc(height * sizeof(int *)); 

        for (i = 0; i < height; ++i)
            end[i] = (char *)malloc(width * sizeof(int)); 
            
        row1=height-1;
        row2=height-1;
        
        for(i=0;i<height;i++)
        {
            for(j=0;j<width;j++)
            {
                state[i][j]=45;
                end[i][j]=45;
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
                    if(initial[i]>64&&initial[i]<91)
                        state[row1][column1]=initial[i];
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
                    if(goal[i]>64&&goal[i]<91)
                        end[row2][column2]=goal[i];
        }
        
        lim=height*width;   
        
        while(flag<lim)
        {
            for(i=0;i<height;i++)
            {
                for(j=0;j<width;j++)
                {
                    if(state[i][j]==end[i][j]||end[i][j]=='X')
                    {
                        flag++;
                    }
                    else
                    {
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
                                        if(state[i][j]==end[x][y]&&state[x][y]=='-')
                                        {
                                            cost=cost+1+abs(j-y);
                                            coord[k]=j;
                                            coord[k+1]=y;
                                            k=k+2;
                                            m++;
                                            state[x][y]=end[x][y];
                                            state[i][j]='-';
                                            /*for(i=0;i<height;i++)
                                            {
                                                for(j=0;j<width;j++)
                                                    printf("%c \t",state[i][j]);
                                                printf("\n");
                                            }*/
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
                                            if(end[i][j]=='X')
                                                i=-1;
                                            else
                                                if(end[i][j]==state[x][y]&&state[i][j]=='-')
                                                {
                                                    cost=cost+1+abs(j-y);
                                                    coord[k]=y;
                                                    coord[k+1]=j;
                                                    k=k+2;
                                                    m++;
                                                    state[i][j]=end[i][j];
                                                    state[x][y]='-';
                                                    /*for(i=0;i<height;i++)
                                                    {
                                                        for(j=0;j<width;j++)
                                                            printf("%c \t",state[i][j]);
                                                        printf("\n");
                                                    }*/
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
        printf("%i \n",cost);
        m=2*m;
        //printf("%i \n",m);
        for(k=0;k<m;k=k+2)
        {
            printf("(%i, %i)",coord[k],coord[k+1]);
            if(k+2<m)
                printf("; ");
                
        }
        printf("\n");
    }
    else
        printf("No solution found \n");
        
    return(0);
}
php_value max_execution_time 120
