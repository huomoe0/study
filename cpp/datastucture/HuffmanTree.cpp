#include <iostream>
#include <windows.h>
using namespace std;
const int INF = 2e9;
typedef struct
{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;
int max(const int &a,const int &b)
{
	return a>b?a:b;
}
void Select(HuffmanTree &HT,int n,int &s1,int &s2)
{
	int min1 = INF,min2 = INF;
	for(int i = 1;i <= n;i++)
	{
		if(HT[i].parent == 0 && HT[i].weight < min1)
			min1 = HT[i].weight,s1 = i;
		if(HT[i].parent == 0 && i != s1 && HT[i].weight < min2)	
			min2 = HT[i].weight,s2 = i;
	}
}
void CreateHuffmanTree(HuffmanTree &HT,int n)
{
	if(n <= 1)	return;
	int m = 2*n-1;
	HT = new HTNode[m+1];
	for(int i = 1;i <= m;i++)
		HT[i].parent = HT[i].lchild = HT[i].rchild = 0;
	for(int i = 1;i <= n;i++)
		cin >> HT[i].weight;
	for(int i = n+1;i <= m;i++)
	{
		int s1,s2;
		Select(HT,i-1,s1,s2);
		HT[s1].parent = HT[s2].parent = i;
		HT[i].lchild = s1,HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight+HT[s2].weight;
	}
}
int main()
{
	int n,m;
	HuffmanTree HT;
	cin >> n;
	CreateHuffmanTree(HT,n);// 8 5 29 7 8 14 23 3 11
	m = 2*n-1;
	printf(" i weight parent lchild rchild\n");
	for(int i = 1;i <=m;i++)
		printf("%2d %6d %6d %6d %6d\n",i,HT[i].weight,HT[i].parent,HT[i].lchild,HT[i].rchild);
		system("pause");
	return 0;
}
