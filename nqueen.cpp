
  
#define n 4
#include <stdio.h>
#include <stdbool.h>
void printsolution(int nqueen[n][n])
{
 for(int i=0;i<n;i++)
 {
  for(int j=0;j<n;j++)
  {
    printf("%d",nqueen[i][j]);
   }
   printf("\n");
  }
}
bool isSafe(int nqueen[n][n],int row,int col)
{
 int i,j;
 for(i=0;i<col;i++)
 {
   if(nqueen[row][i])
       return false;
  }     
   for(i=row,j=col;i>=0&&j>=0;i--,j--)
   {
      if(nqueen[i][j])
          return false;
    }
    for(i=row,j=col;j>=0&&i<n;i++,j--)
    {
       if(nqueen[i][j])
         return false;
    }
  return true;
  }
  bool SolveNQueen(int nqueen[n][n],int col)
  {
     if(col>=n)
        return true;
     for(int i=0;i<n;i++)
     {
       if(isSafe(nqueen,i,col))
       {
         nqueen[i][col]=1;
         if(SolveNQueen(nqueen,col+1))
         {
            return true;
          }
          nqueen[i][col]= 0;
        } 
      }
     return false;
   }
   bool solvenq()
   {
     int nqueen[n][n];
     printf("enter the matrix");
     for(int i=0;i<n;i++)
     {
       for(int j=0;j<n;j++)
       {
         scanf("%d",&nqueen[i][j]);
        }
      }   
     if(SolveNQueen(nqueen,0)==false)
     {
       printf("solution not exists");
       return false;
      }
     printsolution(nqueen);
     return true;
   }
   int main()
   {
    solvenq();
    return 0;
   }  
