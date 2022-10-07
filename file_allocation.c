// Exp 11 OS
// file allocation strategies
// a) Sequential
// b) Indexed
// c) Linked

//DISCLAIMER THIS CODE HAS **BUGS** (NOT ERRORS SO IT SHALL EXECUTE FINE) AND I DIDNT GET TIME TO FIX IT ! :(

#include<stdio.h>

#define SEQ 0
#define LINK 1
#define INDEX 2

struct memory{
	int taken;
	int next;
};
struct file{
	int start;
	int size;
	int type;
	int index[100];
};
int Seq(struct memory memory[],int msize,struct file file);
int Linked(struct memory memory[],int msize,struct file file);
int Indexed(struct memory memory[],int msize,struct file files[],int ftop);
int Display(struct memory memory[],int msize,struct file files[],int ftop);
int main(){
	int msize=100,ftop=0;
	struct memory memory[msize];
	struct file files[10];
	for(int i=0;i<msize;i++)
		memory[i].taken=0;
	int choice;
	printf("0.To Exit and Display\n1.Sequential\n2.Linked\n3.Indexed\nEnter Choice:");
	scanf("%d",&choice);
	while(choice){
		printf("Enter the starting location and size of the file ");
		scanf("%d %d",&files[ftop].start,&files[ftop].size);
		
		switch(choice){
		case 1:
			if(Seq(memory,msize,files[ftop])){
				printf("Successfully allocated file %d \n",ftop+1);
				files[ftop].type=SEQ;
				ftop++;
			}
			else{
				printf("Failed to allocate file %d \n",ftop+1);
			}
			break;
		
		case 2:
			if(Linked(memory,msize,files[ftop])){
				printf("Successfully allocated file %d \n",ftop+1);
				files[ftop].type=LINK;
				ftop++;
			}
			else{
				printf("Failed to allocate file %d \n",ftop+1);
			}
			break;
		case 3:
			if(Indexed(memory,msize,files,ftop)){
				printf("Successfully allocated file %d \n",ftop+1);
				files[ftop].type=INDEX;//printf(" type %d",files[ftop].type);
				ftop++;
			}
			else{
				printf("Failed to allocate file %d \n",ftop+1);
			}
			break;	
		}
		
		printf("Enter Choice:\n");
		scanf("%d",&choice);
	}
	Display(memory,msize,files,ftop);
}

int Seq(struct memory memory[],int msize,struct file file){
	//Check if the files are allocated or not
	for(int i=file.start;i<file.start+file.size;i++){
		if (memory[i].taken)
			return 0;
	}

	for(int i=file.start;i<file.start+file.size;i++)
		memory[i].taken=1;
	return 1;			
	
}

int Linked(struct memory memory[],int msize,struct file file){
	if(memory[file.start].taken){
		return 0;
	}
	else{memory[file.start].taken=1;}
	int curr=file.start;
	int next;
	int fill=file.size-1;
	for(int i=0;i<file.size-1;i++){
		for(int j=0;j<102;j++){			
			next=j;	
			if(j==101){
				printf("No sufficient space in memory !!");
				return 0;
			}
			if(memory[next].taken)
				continue;
			else{
				memory[curr].next=next;
				curr=next;
				memory[curr].taken=1;
				fill--;
				break;
			}
		}		
	}
	return 1;
}

int Indexed(struct memory memory[],int msize,struct file files[],int ftop){
	printf("Enter the indexes:");
	for(int i=0;i<files[ftop].size;i++){
		scanf("%d",&(files[ftop].index[i]));
		if(memory[files[ftop].index[i]].taken)
			return 0;
	
	}
	for(int i=0;i<files[ftop].size;i++){
		memory[files[ftop].index[i]].taken=1;
	}		
	return 1;
}

int Display(struct memory memory[],int msize,struct file files[],int ftop){
	for(int i=0;i<ftop;i++){
		printf("\nFile %d type %d: ",i+1,files[i].type);
		if(files[i].type==SEQ){
			printf("(Sequential)");
			for(int j=files[i].start;j<files[i].start+files[i].size;j++){
				printf("%d ",j);
			}
		}
		else if(files[i].type==LINK){
			int next=files[i].start;
			printf("(Linked)");
			for(int j=0;j<files[i].size;j++){
				printf("%d ",next);
				next=memory[next].next;
			}
		}
		else if(files[i].type==INDEX){
		printf("(Indexed)");
			for(int j=0;j<files[i].size;j++){
				printf("%d ",files[i].index[j]);
			}
		}
	}
	
}
