#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <sched.h>
#include <time.h>

#define BILLION 1E9

void* countA(void *argv){
	struct timespec start,stop;
	clock_gettime(CLOCK_REALTIME,&start);
   	struct sched_param param;
  	param.sched_priority = 0;
   	int a = pthread_setschedparam(pthread_self(), SCHED_OTHER, &param);
   	printf("Success A = %d\n",a);

  	long temp = 4294967296;

  	for(long i=0;i<temp;i++){
 
  	}


	clock_gettime(CLOCK_REALTIME,&stop);
	double c = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec)/BILLION;
        printf("a took %f seconds to execute \n", c);
}

void* countB(void *argv){

	
	struct timespec start,stop;
	clock_gettime(CLOCK_REALTIME,&start);
	struct sched_param param;
	param.sched_priority = 50;
  	int b = pthread_setschedparam(pthread_self(), SCHED_FIFO, &param);
  	printf("Success B = %d\n",b);
  	long temp = 4294967296;

  	for(long i=0;i<temp;i++){
  
  	}
  	
	clock_gettime(CLOCK_REALTIME,&stop);
	double c = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec)/BILLION;
        printf("b took %f seconds to execute \n", c);
}


void* countC(void* argv){
	
	
	struct timespec start,stop;
	clock_gettime(CLOCK_REALTIME,&start);
	struct sched_param param;
	param.sched_priority = 50;
  	int c = pthread_setschedparam(pthread_self(), SCHED_RR, &param);
  		printf("Success C = %d\n",c);
  	long temp = 4294967296;

  	for(long i=0;i<temp;i++){
  		
  	}
  	
	clock_gettime(CLOCK_REALTIME,&stop);
	double d = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec)/BILLION;
        printf("c took %f seconds to execute \n", d);
}


int main(){
	pthread_t ptid1;
	pthread_t ptid2;
	pthread_t ptid3;


	pthread_create(&ptid1,NULL,&countA,NULL);
	pthread_create(&ptid2,NULL,&countB,NULL);
	pthread_create(&ptid3,NULL,&countC,NULL);
	


 	pthread_join(ptid2,NULL);
	
	pthread_join(ptid1,NULL);

	pthread_join(ptid3,NULL);
	

	
	pthread_exit(NULL);

	
}
