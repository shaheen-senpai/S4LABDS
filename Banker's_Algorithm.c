// EXP : 8 OS
// Banker's Algorithm
#include <stdio.h>
int main()
{
  int n, m, i, j, k;
  // n = Number of processes
  // m = Number of resources
  printf("Enter the number of process\n");
    scanf("%d",&n);
  printf("Enter the number of resources\n");
    scanf("%d",&m);
  
  int alloc[n][m];// Allocation Matrix
  printf("Enter the allocation matrix\n");
  for(i=0;i<n;i++){
  	for(j=0;j<m;j++){
        	scanf("%d",&alloc[i][j]);
        	}
      }
      
  int max[n][m];// MAX Matrix
  printf("Enter the max matrix\n");
  for(i=0;i<n;i++){
  	for(j=0;j<m;j++){
  		scanf("%d",&max[i][j]);
        	}
      }
      
  int avail[m];// Available Resources
  printf("enter the available Resources\n");
  for(i=0;i<m;i++){
        scanf("%d",&avail[i]);
      }

  int f[n], ans[n], ind = 0;
  for (k = 0; k < n; k++) {
    f[k] = 0;
  }
  
  int need[n][m];//Need Matrix
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      need[i][j] = max[i][j] - alloc[i][j];
  }
  
  int y = 0;
  for (k = 0; k < 5; k++) {
    for (i = 0; i < n; i++) {
      if (f[i] == 0) {

        int flag = 0;
        for (j = 0; j < m; j++) {
          if (need[i][j] > avail[j]){
            flag = 1;
            break;
          }
        }

        if (flag == 0) {
          ans[ind++] = i;
          for (y = 0; y < m; y++)
            avail[y] += alloc[i][y];
          f[i] = 1;
        }
      }
    }
  }
  int flag = 1;
  
  printf("Alloc Matrix\tMax Matrix \tNeed Matrix\n");
  for(i=0;i<n;i++){
  	for(j=0;j<m;j++){
  		printf("%d ",alloc[i][j]);
        	}
        printf("\t\t");
        for(j=0;j<m;j++){
  		printf("%d ",max[i][j]);
        	}
        printf("\t\t");
        for(j=0;j<m;j++){
  		printf("%d ",need[i][j]);
        	}
        printf("\n");	
      }
  
  for(int i=0;i<n;i++)
  {
  if(f[i]==0)
  {
    flag=0;
    printf("The following system is not safe");
    break;
  }
  }
  
  if(flag==1)
  {
  printf("Following is the SAFE Sequence\n");
  for (i = 0; i < n - 1; i++)
    printf(" P%d ->", ans[i]);
  printf(" P%d", ans[n - 1]);
  }

  return (0);
}
