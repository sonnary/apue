
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
 
void alarm_handler(int sig)
{   
    printf("hello!--sig:%d\n",sig);
}
 
int main()
{
printf("000");
     struct itimerval t;   
     /* 第一次执行前的时间间隔*/
     t.it_value.tv_usec = 0;   
     t.it_value.tv_sec = 3; 
     /* 以后每间再次执行的时间间隔*/
     t.it_interval.tv_usec = 0;    
     t.it_interval.tv_sec = 1;    
         
     if( setitimer(ITIMER_REAL, &t, NULL) < 0 ){
         perror("settimer");        
         return -1;    
     }
     if (signal( SIGALRM, alarm_handler) == SIG_ERR) {
         perror("signal");
         return -1;
    }    
     while(1){        
         pause();    
     }
    return 0;
}

