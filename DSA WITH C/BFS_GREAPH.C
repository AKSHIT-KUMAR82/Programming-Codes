#include<stdio.h>
#include<stdlib.h>

#define MAX 7


void Breadt_first_search(int *visited,int adj[MAX][MAX],int start)
{
    int Queue[MAX+1],front=-1,rear=-1;
    Queue[++rear]=start;
    visited[start]=1;
    int curr;
    while(front!= rear)
    {
        curr=Queue[++front];
        printf("%d ",curr);
        for(int i=0;i<MAX;i++)
        {
            if(adj[curr][i]==1&&visited[i]==0)
            {
                Queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}
int main()
{
    int visited[MAX]={0};
    int adj[MAX][MAX];

    printf("ENTER THE ADJACENCY MATRIX FOR THE GIVEN GRAPH : \n");
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    int start=0;
    Breadt_first_search(visited,adj,start);
    return 0;
}