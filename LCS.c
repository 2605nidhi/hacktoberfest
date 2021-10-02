#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char all_lcs[50][100];
int len=0;

void pLCS(int m, int n, char*a , char*b, int **t, char*s, int l)
{
	
	if(m==0||n==0)
	{
		int i;
		for(i=0;i<len;i++) 
		{
			if(strcmp(all_lcs[i],s)==0) return ; 
		}
		printf("\n");
		for(i=l-1;i>=0;i--)
		{
			 printf("%c",s[i]);
			 all_lcs[len][l-1-i]=s[l-i-1];
		 }
		
		len++;
		return;
	}
	if(a[m-1]==b[n-1]) 
	{
		s[l]=a[m-1];
		pLCS(m-1, n-1, a,b,t,s,l+1);
	}
	else if(t[m-1][n]>t[m][n-1]) pLCS(m-1,n,a,b,t,s,l);
	else if(t[m-1][n]<t[m][n-1]) pLCS(m,n-1,a,b,t,s,l);
	else
	{
		pLCS(m-1,n,a,b,t,s,l);
		pLCS(m,n-1,a,b,t,s,l);
	}
}

int LCS(char*a, char*b, int m,int n)
{
	int i,j;
	int **t=(int**)malloc(sizeof(int*)*(m+1));
	for (i=0;i<=m;i++) t[i]=(int*)malloc(sizeof(int)*(n+1));
	char e[m+1][n+1];
	for(i=0;i<=m;i++) t[i][0]=0;
	for(i=1;i<=n;i++) t[0][i]=0;
		
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i-1]==b[j-1])
			{
				t[i][j]=1+t[i-1][j-1];
				e[i][j]='D';
			}
			else if(t[i-1][j]>t[i][j-1])
			{
				t[i][j]=t[i-1][j];
				e[i][j]='U';
			}
			else
			{
				t[i][j]=t[i][j-1];
				e[i][j]='L';
			}
		}
	}
	
	printf("\n Matrix t is :\n");
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++) printf("%d\t",t[i][j]);
		printf("\n");
	}
	
	printf("\n Matrix b is :\n");
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++) printf("%c\t",e[i][j]);
		printf("\n");
	}
	char*s=(char*)malloc(sizeof(char)*100);
	printf("\n LCS are :  ");
	
	pLCS(m,n,a,b,t,s,0);
	
	return t[m][n];
}

int main()
{
	printf("\n Enter the size of strings:");
	int m,n;
	scanf("%d%d",&m,&n);
	char a[m],b[n];
	printf("Enter the strings :");
	scanf("%s %s",a,b);
	int ans=LCS(a,b,m,n);
	printf("\n\nLength of LCS is %d",ans);
	return 0;
}
