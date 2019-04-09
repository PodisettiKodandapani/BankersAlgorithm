#include<stdio.h>
#include<pthread.h>
#include<conio.h>
#include<stdlib.h>
pthread_mutex_t q;
int current_allocation[100][100];
int maximum_resources[100], state_to_run[100], safe=0;
int count = 0, i, j, exec, k = 1,r,p,zx;
int  maximum_claimed_by_thread[5][5];
int c=0;
int safeseq[100][100];
int alloc[5] = {0, 0, 0, 0, 0};
int safescore[100];
int s;
int available[5];
void *Resource_Allocation(void *args)
{
pthread_mutex_lock(&q);
        state_to_run[i] = 1;
        count++;
        int v=i;
        v=v+1;
printf("\nEnter maximum resources for thread%d:\n",v);

            for(j = 0; j<r; j++) {
            int t=j;
            printf("R%d : ",t+1);
            scanf("%d", &maximum_claimed_by_thread[i][j]);
            }
printf("\nEnter allocated resources for thread%d:\n",v);

        for(j = 0; j < r; j++) {
        int t=j;
        printf("R%d : ",t+1);
        scanf("%d", &current_allocation[i][j]);
        }
pthread_mutex_unlock(&q);
}

int main()
{
printf("\n\n\n********************************************* BANKERS ALGORITHM IMPLEMENTATION USING  MULTIPLE THREADS********************************************\n");
printf("\nEnter the number of user threads you want to create : \n=>");
scanf("%d", &p);
printf("\nEnter the number of resources in bank : \n=>");
scanf("%d", &r);
                    for (i = 0; i < r; i++) {
                    printf("\nEnter the maximum  number of instances for R%d in your system :\n=>", k++);
                    scanf("%d", &maximum_resources[i]);
                    }

printf("\n\n*********************************THREADREQUESTING RESOURCES************************************************\n");
    pthread_mutex_init(&q,NULL);
    pthread_t v[p];
    for(i=0;i<p;i++)
    {
        pthread_create(&v[i],NULL,Resource_Allocation,NULL);
        pthread_join(v[i],NULL);
    }
printf("\n\n*********************************** OUTPUT SECTION**********************************************\n\n");

printf("\nThe number of threads that requested for resources are : \n=>%d",p);
printf("\n\nThe resources in your bank : \n");

                for (i = 0; i < r; i++) {
                        int t=i;
                        printf("=>R%d : ",t+1);
                        printf("%d\n", maximum_resources[i]);
                        }

printf("\n--------------------------------------------------------------------------------------------------------------\n");
printf("\nThe Allocated Resource Table:\n");
printf("\n---------------------------------------------------------------------------------------------------------------\n");

                    for(j=0;j<r;j++){
                    int r=j;
                    printf("\tR%d",r+1);
                    }
printf("\n---------------------------------------------------------------------------------------------------------------\n");
                for (i = 0; i < p; i++) {
                int l=i;
                printf("\nP%d",l+1);
                for (j = 0; j < r; j++) {
                printf("\t%d", current_allocation[i][j]);
                }
                printf("\n");
                }
printf("\n-----------------------------------------------------------------------------------------------------------\n");
printf("\nThe Maximum Resource Table:\n");
printf("\n-------------------------------------------------------------------------------------------------------------\n");
                for(j=0;j<r;j++){
                int r=j;
                printf("\tR%d",r+1);
                }
printf("\n-------------------------------------------------------------------------------------------------------------\n");
                for (i = 0; i < p; i++) {
                int l=i;
                printf("\nP%d",l+1);
                for (j =0;j<r;j++) {
                printf("\t%d", maximum_claimed_by_thread[i][j]);
                }
                printf("\n");
                }
                for (i = 0; i < p; i++) {
                for(j=0;j<r;j++){
                safeseq[i][j] =(maximum_claimed_by_thread[i][j] - current_allocation[i][j]);
                }
                }
printf("\n---------------------------------------------------------------------------------------------------------\n");
printf("\nThe Remaining Need Table is: \n");
printf("\n------------------------------------------------------------------------------------------------------\n");
                for(j=0;j<r;j++){
                int r=j;
                printf("\tR%d",r+1);
                }
printf("\n----------------------------------------------------------------------------------------------------------\n");
                for (i = 0; i < p; i++) {
                int l=i;
                printf("\nP%d",l+1);
                for(j=0;j<r;j++){
                printf("\t%d",safeseq[i][j]);
                }
                printf("\n");
                }
                for (i = 0; i < p; i++) {
                for (j = 0; j < r; j++) {
                alloc[j] += current_allocation[i][j];
                }
                }
printf("*************************************************************************************************");
printf("\n\nThe Total requested resources by Threads:\n");
                for (i = 0; i < r; i++) {
                int r=i;
                printf("\n==>R%d=",r+1);
                printf("%d\n", alloc[i]);
                }
                for (i = 0; i < r; i++) {
                available[i] = maximum_resources[i] - alloc[i];
                }
printf("\n\nThe total Available resources after the requests by Threads: \n");
                for (i = 0; i < r; i++) {
                int r=i;
                printf("\n==>R%d=",r+1);
                printf("%d\n", available[i]);
                }
printf("\n");
printf("\n************************ ALLOCATION AND SAFE SEQUENCE******************************");
                        while (count != 0) {
                                safe = 0;
                                for (i = 0; i < p; i++) {
                                if (state_to_run[i]) {
                                exec = 1;
                                for (j = 0; j < r; j++) {
                                if (maximum_claimed_by_thread[i][j] - current_allocation[i][j] > available[j]) {
                                exec = 0;
                                break;
                                }
                                }

                if (exec) {
                    printf("\n=>Thread%d is executing....\n", i + 1);
                    zx=i+1;
                    safescore[c]=zx;
                    c++;
                    //c++;
                    state_to_run[i] = 0;
                    count--;
                    safe = 1;

                    for (j = 0; j < r; j++) {
                        available[j] += current_allocation[i][j];
                    }
                    break;
                }
            }
        }
                if (!safe) {
                printf("\nThe processes are in unsafe state.\n");
                goto ending;
                }
                else {
                printf("\n=>The BANK is in safe state\n");
                printf("\n=>available resources are :\n");
                for (i = 0; i < r; i++) {
                int t=i;
                printf("\tR%d : ",t+1);
                printf("%d\n", available[i]);
                }
                printf("\n");
                }
    }
printf("\n\nTHE BANK IS IN SAFE STATE - THE SAFE SEQUENCE FOUND IS\n=>\n<");
            for (i = 0; i < p; i++) {
            printf("Thread");
            printf("%d ;",safescore[i]);
            }
            printf(">\n");
            ending:
            exit;
}
