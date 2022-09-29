// EXP : 9 OS
// Memory Allocation methods
// First Fit
// Worst Fit
// Best Fit

#include<stdio.h>
#include<stdlib.h>
void process_input(int *nb,int blocks[100],int *np,int processes[100],int allocated[100]){
   printf("Enter the number of blocks: ");
   scanf("%d",nb);
   printf("Enter the sizes of blocks: \n");
   for(int i=0;i<*nb;i++){
   printf("\tBlock %d: ",i+1);
   scanf("%d",&blocks[i]);
   }
   printf("Enter the number of processes: \n");
   scanf("%d",np);
   printf("Enter the memory required by the processes: \n");
   for(int i=0;i<*np;i++){
   printf("\tProcess %d: ",i+1);
   scanf("%d",&processes[i]);
   }
   for(int i=0;i<*np;i++){
   allocated[i]=-1;
   }
  }
  
  void display(int np,int processes[100],int allocated[100]){
  printf("Process ID\t\tProcess Size\t\tBlock No.\n");
  for(int i=0;i<np;i++){                            // print the blocks nigga
  printf("%d\t\t\t%d\t\t\t",i+1,processes[i]);
  if(allocated[i]==-1){
    printf("NOt allocated\n");
    }
    else{
      printf("%d\n",allocated[i]+1);
      }
     }
    }
    
    void firstfit(){
      int nb,blocks[100];
      int np,processes[100],allocated[100];
      process_input(&nb,blocks,&np,processes,allocated);
      for(int i=0;i<np;i++){
        for(int j=0;j<nb;j++){
          if(blocks[j]>=processes[i]){
            allocated[i]=j;
            blocks[j]-=processes[i];
            printf("Process %d allocated in block %d\n",i+1,j+1);
            break;
            }
           }
          }
          printf("\n FIRST fIT MEMORY ALLOCATION\n");
          display(np,processes,allocated);
          }
          
     void bestfit(){
        int nb,blocks[100];
        int np,processes[100],allocated[100];
        process_input(&nb,blocks,&np,processes,allocated);
        for(int i=0;i<np;i++){
        int min=1000000;
        int index=-1;
        for(int j=0;j<nb;j++){
          if(blocks[j]>=processes[i] && blocks[j]<min){
             min=blocks[j];
             index=j;
             }
           }
           if(index!=-1){
              allocated[i]=index;
              blocks[index]-=processes[i];
              printf("Process %d allocated in block %d\n",i+1,index+1);
              }
             }
             printf("\n BEST FIT MEMORY ALLOCATION\n");
             display(np,processes,allocated);
             }
             
     void worstfit(){
        int nb,blocks[100];
        int np,processes[100],allocated[100];
        process_input(&nb,blocks,&np,processes,allocated);
        for(int i=0;i<np;i++){int max=-1;
        int index=-1;
        for(int j=0;j<nb;j++){
          if(blocks[j]>=processes[i] && blocks[j]>max){
            max=blocks[j];
            index=j;
            }
           }
           if(index!=-1){
             allocated[i]=index;
             blocks[index]-=processes[i];
             printf("Process %d allocated in block %d \n",i+1,index+1);
             }
         }
         printf("WORST FIT MEMORY ALLOCATION\n");
         display(np,processes,allocated);
        }
        
        void main(){
            int choice=0;
            do{
            printf("\n\nMENU\n\n1.FIRST FIT\n2.BEST FIT\n3.WORST FIT\n4.EXIT\nEnter your choice\n");
            scanf("%d",&choice);
            switch(choice){
              case 1: firstfit();
                      break;
              case 2: bestfit();
                      break;
              case 3: worstfit();
                      break;
              case 4: printf("Exiting.\n");
                      break;
              default: printf("Invalid choice\n");
             }
            }while(choice!=4);
          }
        
              
           
          
        
          
      
    
   
