#include <stdio.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/signal.h>
#include <linux/sched.h>

void main(){
    struct task_struct *task;
    printf("Processes are running...\n");
    printf("State\n");
    for_each_process(task){
        printf("%d\n", task->state);
    }

}
