#include<iostream>
#include<climits>
#include<conio.h> 

#define n 7
int parent[n]; 

using namespace std;
 
void printMST(int a[n], int b[n], int weight[n]) 
{
    int Minweight = 0; 
    for (int i = 0; i < n - 1; i++)
    {
        cout<<"Edge: "<<a[i]<<"-"<<b[i]<<" "
             <<"cost: "<<weight[i]<<endl;
        Minweight += weight[i];
    }
    cout<<"Minimum Weight is "<<Minweight<< endl; 
}
int findParent(int node)
{
    while(parent[node] >= 0)
    {
    	node = parent[node];
	} 
    return node;
}
void kruskal(int cost[n][n]) 
{
    fill_n(parent, n, -1);
    int u, v, k = 0, count = 0;
    int firstNode, secondNode;
    int a[n]; 
    int b[n]; 
    int weight[n];
    int minimum;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cost[i][j] == 0) 
                cost[i][j] = INT_MAX;
    while(count < n-1)
    {
        minimum = INT_MAX; 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < minimum)
                {
                    minimum = cost[i][j];
                    firstNode = i; 
                    secondNode = j; 
                }
            }
        }
        u = findParent(firstNode);
        v = findParent(secondNode);
        if (u != v) 
        {
            parent[v] = u;
            a[k] = firstNode; 
            b[k] = secondNode; 
            weight[k] = cost[firstNode][secondNode]; 
            count++;
            k++;
        }
        cost[firstNode][secondNode] = cost[secondNode][firstNode] = INT_MAX;
    }
    printMST(a, b, weight); 
}
int main()
{
    int cost[n][n] = {
        {0,2,0,7,0,2,0},
        {2,0,1,4,3,5,0},
        {0,1,0,0,4,4,0},
        {7,4,0,0,1,0,5},
        {0,3,4,1,0,0,7},
        {2,5,4,0,0,0,0},
        {0,0,0,5,7,0,0}
    }; 
    cout<<"=====MA TRAN TRONG SO======="<<'\n'; 
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           	cout<<cost[i][j]<<"   "; 
		}
		cout<<'\n'; 
	}
	cout<<'\n'; 
	cout<<"=======THUAT TOAN KRUSKAL========="<<'\n'; 
    kruskal(cost);
    getch(); 
    return 0;
}
