/***************************************************
* Module name: kernel.cl
*
*	University of South Carolina
*
* First written  01/01/15 by Steve Rubin.
*
* Module Description: OpenCL SpMV kernel
*
***************************************************/



/**************************************************
*	include header files
**************************************************/
#include  <dsp_c.h>
#include "edmamgr.h"
#include "management.h"
#define SEM_DIRECT 0x2640000 + 0x100
#define SEM_QUERY 0x2640000 + 0x300

unsigned int sem_query (int sem) 
{
	return *((volatile unsigned int *)(SEM_QUERY)+sem);
}


void sem_unlock (int sem) 
{
	*((volatile unsigned int *)(SEM_DIRECT)+sem)=1;
}


void sem_lock (int sem) 
{
	while (*((volatile unsigned int *)(SEM_DIRECT)+sem)!=1) //printf("foo")
	;

}




/**************************************************
* Function name : spmv
*
* returns : void 
* y : pointer to Y array of type float
*
* Created by : Steve Rubin
* Date created : 01/05/15
* Description : kernel performing SpMV caclulation
* Notes : the only kernel function used in the whole project
**************************************************/

__kernel void spmv(
					__global float* restrict Y,
					__global float* restrict A,
					__global float* restrict B,
					const int M,
					const int K,
					const int N,
					__global float* restrict GFLOPs
					)
{

	int global_id = get_global_id(0);

	printf ("Hi! i am core #%d\n", global_id);
	//timlUtildMatMul_32f(Y, A, B, M, K, N, GFLOPs);
	//printf("address of y is %d\n", y);

}


