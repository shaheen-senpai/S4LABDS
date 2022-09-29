// EXP : 6 OS
// Write a c program to simulate the following cpu scheduling algorithms 
// 1) FCFS
// 2) SJF(non preemptive)
// 3)Round Robin(preemptive)
// 4)Priority(preemptive)
// Also display the Average Waiting time and Turn Around time

#include <stdio.h>
#include <stdlib.h>

struct process {
	int pid;
	int br;
	int at;
	int prio;
	int tat;
	int wt;
	int isComp;
	int le;
};

void sort(struct process pr[], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(pr[j].at > pr[j + 1].at) {
				struct process temp = pr[j];
				pr[j] = pr[j + 1];
				pr[j + 1] = temp;
			}
		}
	}
}

void insert(struct process pr[], int n){
	printf("\n Enter constraints of each of the processes : \npid - burst time - arrival time \n");
	for(int i = 0; i < n; i++) {
		scanf("%d", &pr[i].pid);
		scanf("%d", &pr[i].br);
		scanf("%d", &pr[i].at);
		pr[i].isComp = pr[i].wt = pr[i].tat = 0;
		pr[i].le = pr[i].at;
		}

}

void main() {

	printf("\n1.FCFS\n2.SJF\n3.Preemptive Priority Scheduling\n4.Round Robin\n5.Exit\n");
	int n = 0;
	struct process pr[100];
	
	do {

		int ch; scanf("%d", &ch);
		float tata = 0, wta = 0;

		if(ch == 1) {
		printf("\n Enter the number of processes : "); scanf("%d", &n);
		insert(pr, n);
		sort(pr, n);
		
			int ct = pr[0].at + pr[0].br;
			pr[0].wt = 0;
			for(int i = 1; i < n; i++){
				while(pr[i].at > ct)ct++;
				pr[i].wt = ct - pr[i].at;
				ct += pr[i].br;
			}
		}

		if(ch == 2) {
		printf("\n Enter the number of processes : "); scanf("%d", &n);
		insert(pr, n);
		sort(pr, n);
			int currtime = 0;
			int check = 0;

			while(check != n) {
			
			int shortest = -1;
			for(int i = 0; pr[i].at <= currtime && i < n; i++){
				if(pr[i].isComp != 1) shortest = i;
			}
			for(int i = 0; pr[i].at <= currtime && i < n; i++){	
				if(pr[i].isComp == 0 && pr[shortest].br > pr[i].br) shortest = i;
			}
			
			if(shortest != -1) {
				pr[shortest].isComp = 1;
				pr[shortest].wt = currtime - pr[shortest].at;
				currtime = currtime + pr[shortest].br;
				check++;
			}
			else
				currtime++;
			}	
		}

		if(ch == 3) {
		printf("\n Enter the number of processes : "); scanf("%d", &n);
		printf("\n Enter the pid - burst time - arrival time - priority of each of the processes : \n");
		for(int i = 0; i < n; i++) {
			scanf("%d", &pr[i].pid);
			scanf("%d", &pr[i].br);
			scanf("%d", &pr[i].at);
			scanf("%d", &pr[i].prio);
			pr[i].isComp = pr[i].wt = pr[i].tat = 0;
			pr[i].le = pr[i].at;
		}
		sort(pr, n);
			struct process p[n]; for(int i = 0; i < n; i++) p[i] = pr[i];
			int check = 0, currtime = 0;

			while(check != n) {

				int highest = -1;
				for(int i = 0; pr[i].at <= currtime && i < n; i++) {
					if(pr[i].isComp == 0 && highest == -1) highest = i;
					if(pr[i].isComp == 0 && pr[i].prio < pr[highest].prio) highest = i;
				}


				if(highest != -1){
					p[highest].br--;
					pr[highest].wt += currtime - pr[highest].le;
					pr[highest].le = currtime + 1;
					if(p[highest].br == 0){ pr[highest].isComp = 1; check++;}
				}				
				currtime++;
			}
		}
		
		if(ch == 4) {
		printf("\n Enter the number of processes : "); scanf("%d", &n);
		insert(pr, n);
		sort(pr, n);
			struct process p[n];
			struct process q[100];
			
			for(int i = 0; i < n; i++) p[i] = pr[i];
			
			int currtime = 0;
			int tq = 3;
			int check = 0;
			int i = 0, mov = 0, fi = 0;

			while(check != n) {	
							
				while(i < n && pr[i].at <= currtime) q[mov++] = pr[i++];
				if(mov == fi) currtime++;
							
				if(q[fi].br <= tq) {
				int ind;
				for(int k = 0; k < n; k++) 
					if(q[fi].pid == pr[k].pid)
						ind = k;
							
				pr[ind].wt += currtime - pr[ind].le;
				currtime += p[ind].br;							
				p[ind].br = 0;
				pr[ind].isComp = 1;
				pr[ind].le = currtime;
				check++;
				fi++;
				}
				else{
					int ind;
					for(int k = 0; k < n; k++) 
						if(q[fi].pid == pr[k].pid)
							ind = k;						
					p[ind].br -= 3;			
					pr[ind].wt += currtime - pr[ind].le;
					currtime += 3;
					pr[ind].le = currtime;
					while(i < n && pr[i].at <= currtime) q[mov++] = pr[i++];
					q[mov++] = p[ind];
					fi++;
				}
			}
		}
		if(ch == 5) exit(0);
		
		for(int i = 0; i < n; i++){
			pr[i].tat = pr[i].wt + pr[i].br;
			wta += pr[i].wt;
			tata += pr[i].tat;
		}

		printf("\nPid\tBurstTime\tArrivalTime\tPriority\tTurnAroundTime\tWaitingTime\n");
		for(int i = 0; i < n; i++) 
			printf("%d \t%d \t\t%d \t\t%d \t\t%d \t\t%d\n", pr[i].pid, pr[i].br, pr[i].at, pr[i].prio, pr[i].tat, pr[i].wt);
		printf("\nAverage Turnaround time : %.3f", tata/n);
		printf("\nAverage Waiting time : %.3f", wta/n);
		printf("\nReturn/Exit(1/0)\n");
		tata = 0, wta = 0;	

		int ex; scanf("%d", &ex);
		if(ex == 0) break;
	}while(1);
}
