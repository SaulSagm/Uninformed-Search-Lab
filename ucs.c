#include <stdlib.h>//Libraries
#include <stdio.h>
#include <string.h>

int main()
{
    int i,j,k=0,m=0;//Variable for cycle "for"
    int lim,flag=1,rep=0;//Variables for initiating or stoping a cycle
    int x,y;
    int cost=0;//Cost for moving a container from one stack to another, it accumulates
    int a=0,b=0;
    int c=0,d=0;
    int e=0,f=0;
    int height,width,length;
    int row1=0,column1=0;
    int row2=0,column2=0;
    int coord[20];
    char initial[20],goal[20],**state,**end;
    
    scanf("%i",&height);//Giving the maximum height
    scanf("%s",&initial);//Write the initial state of the system
    scanf("%s",&goal);//Write the goal state of the system

    b=strlen(initial);//Lenght of string initial and goal.
    c=strlen(goal);
    
    for(i=0;i<b;i++)
    {
        if(initial[i]==59)//Counts the number of ';'
            a++;
        else
            if(initial[i]==44)//Counts the number of ','
                e++;
    }
    
    for(i=0;i<c;i++)
    {
        if(goal[i]==59)//Counts the number of ';'
            d++;
        else
            if(goal[i]==44)//Counts the number of ','
                f++;
    }
    
    if(a==d&&e<=height-1&&f<=height-1)//Makes sure the number of ';' are similar between goal and initial.
    {                                   //Also makes sure the number of lines dont surpass the maixmum height
        width=a+1;
        
        state = (char **)malloc(height * sizeof(int *)); //Establish the size of the matrix state.

        for (i = 0; i < height; ++i)
            state[i] = (char *)malloc(width * sizeof(int)); 

        end = (char **)malloc(height * sizeof(int *)); //Establish the size of the matrix state.

        for (i = 0; i < height; ++i)
            end[i] = (char *)malloc(width * sizeof(int)); 
            
        row1=height-1;
        row2=height-1;
        
        for(i=0;i<height;i++)
        {
            for(j=0;j<width;j++)
            {
                state[i][j]=45;//Initializes the matrixes with '-'
                end[i][j]=45;
            }
        }
        
        for(i=0;i<b;i++)
        {
            if(initial[i]==44)//Analizes the string initial to know were to ubicate each container in the matrix state.
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
            if(goal[i]==44)//Analizes the string goal to know were to ubicate each container in the matrix end.
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
                    if(state[i][j]==end[i][j]||end[i][j]=='X')//Checks if the matrices are equal, if they are equal,
                    {                                           //then the goal is reached, if not it needs to be revised.
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
            
            while(rep==1)//The cycle starts if there is a difference between the matrixes
            {
                for(j=0;j<width;j++)
                {
                    for(i=0;i<height;i++)
                    {
                        if(state[i][j]!=end[i][j])
                        {
                            if(state[i][j]=='-')//If state has a space
                            {
                                x=i;//Record the coordinates
                                y=j;
                                for(j=0;j<width;j++)
                                {
                                    for(i=height-1;i>=0;i--)
                                    {
                                        if(state[i][j]==end[x][y]&&state[x][y]=='-')//If the value in state is equal to end in the recorded coordinates
                                        {                                           //then the change is done
                                            cost=cost+1+abs(j-y);//Cost function
                                            coord[k]=j;//Initial stack
                                            coord[k+1]=y;//Next stack
                                            k=k+2;
                                            m++;
                                            state[x][y]=end[x][y];//Changing values
                                            state[i][j]='-';
                                            /*for(i=0;i<height;i++)
                                            {
                                                for(j=0;j<width;j++)
                                                    printf("%c \t",state[i][j]);
                                                printf("\n");
                                            }*/
                                            i=-1;//End cycle
                                            j=width;//End cycle
                                            rep=0;//End cycle
                                        }
                                    }
                                }
                                i=x;
                                j=y;
                            }
                            else
                                if(end[i][j]=='-')//If state has a space
                                {
                                    x=i;//Record the coordinates
                                    y=j;
                                    for(j=0;j<width;j++)
                                    {
                                        for(i=height-1;i>=0;i--)
                                        {
                                            if(end[i][j]=='X')//Ignore the any X value
                                                i=-1;
                                            else
                                                if(end[i][j]==state[x][y]&&state[i][j]=='-')//If the value in state is equal to end in the recorded coordinates
                                                {
                                                    cost=cost+1+abs(j-y);//Cost function
                                                    coord[k]=y;//Initial stack
                                                    coord[k+1]=j;//Next stack
                                                    k=k+2;
                                                    m++;
                                                    state[i][j]=end[i][j];//Change values
                                                    state[x][y]='-';
                                                    /*for(i=0;i<height;i++)
                                                    {
                                                        for(j=0;j<width;j++)
                                                            printf("%c \t",state[i][j]);
                                                        printf("\n");
                                                    }*/
                                                    i=-1;//End cycle
                                                    j=width;//End cycle
                                                    rep=0;//End cycle
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
        printf("%i \n",cost);//The total cost is printed
        m=2*m;
        //printf("%i \n",m);
        for(k=0;k<m;k=k+2)
        {
            printf("(%i, %i)",coord[k],coord[k+1]);//The coordinates are printed in a specific format
            if(k+2<m)
                printf("; ");
                
        }
        printf("\n");
    }
    else
        printf("No solution found \n");//If the number of ';' were not equal and the number of ',' were above the height, then there is no solution
        
    return(0);
}
