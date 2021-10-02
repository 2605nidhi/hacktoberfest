#include <stdio.h>
#include <stdlib.h>
#define INFINITY 9999
#define MAX 10


struct node{
    int vertex;
    int value;
    struct node* next;
};
void dijkstra(struct node **cost,int n,int start){
    int distance[MAX],pred[MAX],visited[MAX];
    int count,mdist,nextnode,i,j;
    struct node* temp;


    for(i=0;i<n;i++)
    {
        visited[i]=0;
        distance[i]=INFINITY;
    }
    
    distance[start]=0;
    visited[start]=1;
    temp=cost[start];
    
    while(temp!= NULL)
    {
        distance[temp->vertex]=temp->value;
        pred[temp->vertex]=start;
        
        temp=temp->next;
    }
    
    count=1;
    while(count < n-1)
    {
    	
        mdist=INFINITY;
        for(i=0;i<n;i++)
        {
            if(distance[i]<mdist && !visited[i])
            {
                mdist=distance[i];
                nextnode=i;
            }
        }
        


        visited[nextnode]=1;
        temp=cost[nextnode];
        while(temp!=NULL)
        {
            if(!visited[temp->vertex])
            {
                if((mdist+ temp->value) < distance[temp->vertex])
                {
                    distance[temp->vertex]= mdist+ temp->value;
                    pred[temp->vertex]=nextnode;
                }
            }
            temp=temp->next;
        }
        count++;
        
    }
    
    for(i=0;i<n;i++)
    {
        if(i!=start)
        {
            printf("Distance from source to %d is :%d\n",i,distance[i]);
        }
    }
    for(i=0;i<n;i++)
    {
        if(i!=start)
        {
            printf("Path from vertex %d to source is : %d ------>",i,i);
            j=pred[i];
            for(;j!=start;)
            {
                printf("%d ------> ",j);
                j=pred[j];
            }
            printf("%d\n",start);
        }
    }
}


int main()
{
    int n,i,a,j;
    struct node *nodes,*prevnode;
    printf("Enter the no of vertices in graph : ");
    scanf("%d",&n);
    struct node** arr=(struct node**)calloc(sizeof(struct node*),n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the no of vertices adjacent to vertex %d  :  ",i);
        scanf("%d",&a);
        for(j=0;j<a;j++)
        {
            printf("\nEnter the vertex and weight  :  ");
            nodes=(struct node*)malloc(sizeof(struct node));
            scanf("%d%d",&nodes->vertex,&nodes->value);
            nodes->next=NULL;
            if(arr[i]==0)
            {
                arr[i]=nodes;
                prevnode=nodes;
            }
            else
            {
                prevnode->next=nodes;
                prevnode=nodes;
            }
        }
    }
    
    int src;
    printf("\nEnter the source vertex  :  ");
    scanf("%d",&src);
    dijkstra(arr,n,src);
    free(arr);
    return 0;
}
