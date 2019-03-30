#include<stdio.h>
#include<pthread.h>
#include<conio.h>

int current[5][5], maxclaim[5][5], avl[5];
int alloc[5] = {0, 0, 0, 0, 0};
int maxres[5], running[5], safe=0;
int count = 0, i, j, exec, k = 1,r,p;

pthread_mutex_t q;

void *f1(void *args)
{
pthread_mutex_lock(&q);
   //or (i = 0; i < p; i++) {
        running[i] = 1;
        count++;

  printf("\nEnter maximum resource table:\n");

 for(j = 0; j<r; j++) {

            scanf("%d", &maxclaim[i][j]);
}

printf("\nEnter allocated resource table:\n");

        for(j = 0; j < r; j++) {
            scanf("%d", &current[i][j]);
        }
pthread_mutex_unlock(&q);

}

int main()
{
    printf("\nEnter the number of resources: ");
    scanf("%d", &r);

    for (i = 0; i < r; i++) {
        printf("\nEnter the resource for instance %d: ", k++);
        scanf("%d", &maxres[i]);
    }
    printf("\nEnter the number of processes: ");
    scanf("%d", &p);

    pthread_mutex_init(&q,NULL);
    pthread_t v[p];
    for(i=0;i<p;i++)
    {
        pthread_create(&v[i],NULL,f1,NULL);
    }

    for(i=0;i<p;i++)
    {
        pthread_join(v[i],NULL);
    }


printf("\nThe resource of instances: ");
    for (i = 0; i < r; i++) {
        printf("\t%d", maxres[i]);
    }

    printf("\nThe allocated resource table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            printf("\t%d", current[i][j]);
        }

        printf("\n");
    }

    printf("\nThe maximum resource table:\n");
    for (i = 0; i < p; i++) {
        for (j =0;j<r;j++) {
            printf("\t%d", maxclaim[i][j]);
        }

        printf("\n");
    }

    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            alloc[j] += current[i][j];
        }
    }

    printf("\nAllocated resources:");
    for (i = 0; i < r; i++) {
        printf("\t%d", alloc[i]);
    }


    for (i = 0; i < r; i++) {
        avl[i] = maxres[i] - alloc[i];
    }

    printf("\nAvailable resources:");
    for (i = 0; i < r; i++) {
        printf("\t%d", avl[i]);
    }
    printf("\n");


while (count != 0) {
        safe = 0;
        for (i = 0; i < p; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (maxclaim[i][j] - current[i][j] > avl[j]) {
                        exec = 0;
                        break;
                    }
                }
                if (exec) {
                    printf("\nProcess%d is executing\n", i + 1);
                    running[i] = 0;
                    count--;
                    safe = 1;

                    for (j = 0; j < r; j++) {
                        avl[j] += current[i][j];
                    }

                    break;
                }
            }
        }
        if (!safe) {
            printf("\nThe processes are in unsafe state.\n");
            break;
        }
         else {
            printf("\nThe process is in safe state");
            printf("\n available resources are :");

            for (i = 0; i < r; i++) {
                printf("\t%d", avl[i]);
            }

            printf("\n");
        }
    }

}
