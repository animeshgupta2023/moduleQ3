#include <linux/module.h>     
#include <linux/kernel.h>   
#include<linux/sched/signal.h>	
#include <linux/init.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("ANIMESH-GUPTA");
MODULE_DESCRIPTION("counting currently running processes"); 


static int __init counting_running_processes(void)
{    
    struct task_struct *t;
    int count = 0;
    for_each_process(t){
    	if (t->__state == TASK_RUNNING) {
            count++;
        }
    }
    printk(KERN_INFO "Number of running processes are: %d",count);
    return 0;
}


static void __exit display_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.");
}

module_init(counting_running_processes);      
module_exit(display_cleanup);