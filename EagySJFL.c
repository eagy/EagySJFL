/* 
 * File:   EagySJFL.c
 * Author: Daniel Eagy
 */

#include <stdio.h>
#include <stdlib.h>

struct Process {
    int ID;
    int tau;
    float alpha;
    int *burst;
    int size; 
};

FILE *fp;
int turnaround = 0;
int numProcesses;
int numTicks;

struct Process* process = NULL;


void schedule(struct Process* process); 

int main(int argc, char** argv) {
    fp = fopen("sample_data1", "r");

    char buff[256];


    int line = 0;

    while (fgets(buff, 255, (FILE*) fp)) {
        if (line == 0) {
            numTicks = atoi(buff);
            line++;
            continue;
        }
        if (line == 1) {
            numProcesses = atoi(buff);
            break;
        }
    }

    process = (struct Process*) malloc(numProcesses * sizeof (struct Process));

    int i, j;
    for (i = 0; i < numProcesses; i++) {
        process[i].burst = malloc(sizeof(int)*numTicks);
        process[i].size = numTicks;
        
        line = 0; 
        while (fgets(buff, 255, (FILE*) fp)) {
            if (line == 0) {
                process[i].ID = atoi(buff);
                line++;
                continue;
            }
            else if (line == 1) {
                process[i].tau = atoi(buff);
                line++;
                continue;
            }
            else {
                process[i].alpha = atof(buff);
                break;
            }
        }
        
        printf("ID %d, Tau %d, Alpha %f\n", process[i].ID, process[i].tau, process[i].alpha);
        
        for (j = 0; j < numTicks; j++) {
            fgets(buff, 255, (FILE*) fp);
            process[i].burst[j] = atoi(buff);
            
            //printf("Tick %d, Burst %d\n", j, process[i].burst[j]);
            
        }
    }

    //printf("Ticks:\t%d\tProcesses:\t%d\n", numTicks, numProcesses);
    close(process);
    close(fp);
    return (EXIT_SUCCESS);
}

void schedule(struct Process* process) {
    int i, j; 
    int numBursts = numTicks*numProcesses; 
}