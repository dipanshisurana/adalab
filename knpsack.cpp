#include<iostream> 
using namespace std;  

int max(int a, int b) 
 { 
   return (a > b)? a : b; 
 } 
  
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 
  
int main() 
{ 
    int val[3],wt[3],W;
    cout<<"Enter the weights:"; 
    for(int i=0;i<3;i++)
    cin>>wt[i];
    cout<<"Enter the values:";
    for(int i=0;i<3;i++)
    cin>>val[i];
    cout<<"Enter the knapsack capacity:";
    cin>>W;
    int n = sizeof(val)/sizeof(val[0]); 
    cout<<"Solution:"<<knapSack(W, wt, val, n)<<"\n"; 
    return 0; 
} 