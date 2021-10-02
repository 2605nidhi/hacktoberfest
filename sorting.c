#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void disp_write(int *arr,int p,int n,char *fname)
{
    int i;
    FILE *fp=fopen(fname,"a");
    fprintf(fp,"\nPass %d\n",p);
    for(i=0;i<n;i++)
    {
        fprintf(fp,"\t%d",arr[i]);
    }
    fclose(fp);
}
void bubble(int n)
{
    int *arr=(int*)malloc(sizeof(int)*n);
    int count =n;
    FILE *ftr= fopen("numbers.txt","r");
    int i=-1,j;
    while(--count>=0)
    {
        fscanf(ftr," %d",&arr[++i]);
    }
    fclose(ftr);
    FILE *fp = fopen("bubble.txt","w");
    fprintf(fp,"BUBBLE SORT\n");
    fclose(fp);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        disp_write(arr,i,n,"bubble.txt");
    }
}
void m_bubble(int n)
{
    int *arr=(int*)malloc(sizeof(int)*n);
    int count =n;
    FILE *ftr= fopen("numbers.txt","r");
    int i=-1,j;
    while(--count>=0)
    {
        fscanf(ftr," %d",&arr[++i]);
    }
    fclose(ftr);
    FILE *fp = fopen("m_bubble.txt","w");
    fprintf(fp,"MODIFIED BUBBLE SORT\n");
    fclose(fp);
    for(i=0;i<n;i++)
    {
        int f=0;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                f=1;
            }
        }
        disp_write(arr,i,n,"m_bubble.txt");
        if(f==0) break;
    }
}
void cocktail(int n)
{
    int *arr=(int*)malloc(sizeof(int)*n);
    int count =n;
    FILE *ftr= fopen("numbers.txt","r");
    int i=-1,j;
    while(--count>=0)
    {
        fscanf(ftr," %d",&arr[++i]);
    }
    fclose(ftr);
    FILE *fp = fopen("cocktail.txt","w");
    fprintf(fp,"COCKTAIL SHAKER SORT\n");
    fclose(fp);
    for(i=0;i<n;i++)
    {
        int f=0;
        for(j=i;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                f=1;
            }
        }
        for(j=n-i-2;j>=i;j--)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                f=1;
            }
        }
        disp_write(arr,i,n,"cocktail.txt");
        if(f==0) break;
    }
}
void selection(int n)
{
    int *arr=(int*)malloc(sizeof(int)*n);
    int count =n;
    FILE *ftr= fopen("numbers.txt","r");
    int i=-1,j;
    while(--count>=0)
    {
        fscanf(ftr," %d",&arr[++i]);
    }
    fclose(ftr);
    FILE *fp = fopen("select.txt","w");
    fprintf(fp,"SELECTION SORT\n");
    fclose(fp);
    for(i=0;i<n;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j]) min=j;
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        disp_write(arr,i,n,"select.txt");
    }
}
int partition(int *arr,int p,int r)
{
    int i=p,j;
    for(j=p;j<r-1;j++)
    {
        if(arr[j]<=arr[r-1])
        {
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i]=arr[r-1];
    arr[r-1]=temp;
    return i;
}
void q_write(int *arr,int p,int n,char *sname)
{
    int i;
    FILE *fp=fopen("quick.txt","a");
    fprintf(fp,"\n%s\n",sname);
    for(i=p;i<=n;i++)
    {
        fprintf(fp,"\t%d",arr[i]);
    }
    fclose(fp);
}
void quicksort(int *arr,int p,int r)
{
    if(p<r)
    {
        int q=partition(arr,p,r);
        q_write(arr,p,q,"left subarray");
        quicksort(arr,p,q);
        q_write(arr,q+1,r-1,"right subarray");
        quicksort(arr,q+1,r);
        q_write(arr,p,r-1,"whole array");
    }
}

int sorting()
{
    int n,ch,i,num;
    printf("\nEnter n\n");
    scanf("%d",&n);
    int *hash=(int*)malloc(sizeof(int)*n*2);;
    FILE *fptr = fopen("numbers.txt","w");
    printf("Generating random numbers . . . .\n");
    int count=0;
    for(i=0;i<n;i++)
    {
        int a=rand()%(2*n+1);
        if(hash[a]==1) i--;
        else
        {
            fprintf(fptr," %d",a);
            hash[a]=1;
        }
    }
    fclose(fptr);
    FILE *ftr= fopen("numbers.txt","r");
    while(--count>=0)
    {
        fscanf(ftr," %d",&num);
        printf(" %d\t",num);
    }
    fclose(ftr);
    clock_t t;
    double time_taken;
    int *quick=(int*)malloc(sizeof(int)*n);

    while(1)
    {
        printf("\n1. Bubble Sort \n2. Modified Bubble Sort \n3.Cocktail Shaker Sort \n4. Selection Sort \n5. Quicksort \n6. Exit \nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                t=clock();
                bubble(n);
                t=clock()-t;
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                printf("\nTime taken is %f",time_taken);
                break;
            case 2:
                t=clock();
                m_bubble(n);
                t=clock()-t;
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                printf("\nTime taken is %f",time_taken);
                break;
            case 3:
                t=clock();
                cocktail(n);
                t=clock()-t;
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                printf("\nTime taken is %f",time_taken);
                break;
            case 4:
                t=clock();
                selection(n);
                t=clock()-t;
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                printf("\nTime taken is %f",time_taken);
                break;
            case 5:
                t=clock();
                FILE *ftr= fopen("numbers.txt","r");
                i=-1;
                count =n;
                while(--count>=0)
                {
                    fscanf(ftr," %d",&quick[++i]);
                }
                fclose(ftr);
                FILE *fp = fopen("quick.txt","w");
                fprintf(fp,"QUICKSORT\n");
                fclose(fp);
                quicksort(quick,0,n);
                t=clock()-t;
                time_taken = ((double)t)/CLOCKS_PER_SEC;
                printf("\nTime taken is %f",time_taken);
                break;
            case 6:
                exit(1);
        }
    }
    return 0;
}
