/***************************************************
* Module name: main.cpp
*
*	University of South Carolina
*
* First written  01/01/15 by Steve Rubin.
*
* Module Description: main module of the project
*
***************************************************/

/**************************************************
*	include header files
**************************************************/
#include <stdio.h>
#include "CL/cl.h"
#include "CL/cl_ext.h"
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#include "omp.h"
#include "management.h"
#include <time.h>


/**************************************************
*	Global variable declaration section
**************************************************/
#define NUMBER_OF_WORK_ITEMS 8
//#define  NUMBER_OF_CORES 8
#define CASE_CL_ERROR(NAME) case NAME: return #NAME;


typedef int boolean;
#define true 1
#define false 0



const char* opencl_error_to_str (cl_int error)
{
	switch(error)
	{
		CASE_CL_ERROR(CL_SUCCESS);
		CASE_CL_ERROR(CL_DEVICE_NOT_FOUND);
		CASE_CL_ERROR(CL_DEVICE_NOT_AVAILABLE);
		CASE_CL_ERROR(CL_COMPILER_NOT_AVAILABLE);
		CASE_CL_ERROR(CL_MEM_OBJECT_ALLOCATION_FAILURE);
		CASE_CL_ERROR(CL_OUT_OF_RESOURCES);
		CASE_CL_ERROR(CL_OUT_OF_HOST_MEMORY);
		CASE_CL_ERROR(CL_PROFILING_INFO_NOT_AVAILABLE);
		CASE_CL_ERROR(CL_MEM_COPY_OVERLAP);
		CASE_CL_ERROR(CL_IMAGE_FORMAT_MISMATCH);
		CASE_CL_ERROR(CL_IMAGE_FORMAT_NOT_SUPPORTED);
		CASE_CL_ERROR(CL_BUILD_PROGRAM_FAILURE);
		CASE_CL_ERROR(CL_MAP_FAILURE);
		CASE_CL_ERROR(CL_MISALIGNED_SUB_BUFFER_OFFSET);
		CASE_CL_ERROR(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
		//CASE_CL_ERROR(CL_COMPILE_PROGRAM_FAILURE);
		//CASE_CL_ERROR(CL_LINKER_NOT_AVAILABLE);
		//CASE_CL_ERROR(CL_LINK_PROGRAM_FAILURE);
		//CASE_CL_ERROR(CL_DEVICE_PARTITION_FAILED);
		//CASE_CL_ERROR(CL_KERNEL_ARG_INFO_NOT_AVAILABLE);

		CASE_CL_ERROR(CL_INVALID_VALUE);
		CASE_CL_ERROR(CL_INVALID_DEVICE_TYPE);
		CASE_CL_ERROR(CL_INVALID_PLATFORM);
		CASE_CL_ERROR(CL_INVALID_DEVICE);
		CASE_CL_ERROR(CL_INVALID_CONTEXT);
		CASE_CL_ERROR(CL_INVALID_QUEUE_PROPERTIES);
		CASE_CL_ERROR(CL_INVALID_COMMAND_QUEUE);
		CASE_CL_ERROR(CL_INVALID_HOST_PTR);
		CASE_CL_ERROR(CL_INVALID_MEM_OBJECT);
		CASE_CL_ERROR(CL_INVALID_IMAGE_FORMAT_DESCRIPTOR);
		CASE_CL_ERROR(CL_INVALID_IMAGE_SIZE);
		CASE_CL_ERROR(CL_INVALID_SAMPLER);
		CASE_CL_ERROR(CL_INVALID_BINARY);
		CASE_CL_ERROR(CL_INVALID_BUILD_OPTIONS);
		CASE_CL_ERROR(CL_INVALID_PROGRAM);
		CASE_CL_ERROR(CL_INVALID_PROGRAM_EXECUTABLE);
		CASE_CL_ERROR(CL_INVALID_KERNEL_NAME);
		CASE_CL_ERROR(CL_INVALID_KERNEL_DEFINITION);
		CASE_CL_ERROR(CL_INVALID_KERNEL);
		CASE_CL_ERROR(CL_INVALID_ARG_INDEX);
		CASE_CL_ERROR(CL_INVALID_ARG_VALUE);
		CASE_CL_ERROR(CL_INVALID_ARG_SIZE);
		CASE_CL_ERROR(CL_INVALID_KERNEL_ARGS);
		CASE_CL_ERROR(CL_INVALID_WORK_DIMENSION);
		CASE_CL_ERROR(CL_INVALID_WORK_GROUP_SIZE);
		CASE_CL_ERROR(CL_INVALID_WORK_ITEM_SIZE);
		CASE_CL_ERROR(CL_INVALID_GLOBAL_OFFSET);
		CASE_CL_ERROR(CL_INVALID_EVENT_WAIT_LIST);
		CASE_CL_ERROR(CL_INVALID_EVENT);
		CASE_CL_ERROR(CL_INVALID_OPERATION);
		CASE_CL_ERROR(CL_INVALID_GL_OBJECT);
		CASE_CL_ERROR(CL_INVALID_BUFFER_SIZE);
		CASE_CL_ERROR(CL_INVALID_MIP_LEVEL);
		CASE_CL_ERROR(CL_INVALID_GLOBAL_WORK_SIZE);
		CASE_CL_ERROR(CL_INVALID_PROPERTY);
		//CASE_CL_ERROR(CL_INVALID_IMAGE_DESCRIPTOR);
		//CASE_CL_ERROR(CL_INVALID_COMPILER_OPTIONS);
		//CASE_CL_ERROR(CL_INVALID_LINKER_OPTIONS);
		//CASE_CL_ERROR(CL_INVALID_DEVICE_PARTITION_COUNT);

		default:
		return "UNKNOWN ERROR CODE";
	}
}


void exitWithError(char *errorDescription)
{
	
}

int askUserForInt (char *whatToAsk)
{
	char input[80];
	printf ("%s\n", whatToAsk);
	
	scanf ("%s", input);
	int value = atoi(input);
	if (value == 0)
	{
		printf("wrong value!\n");
		return 0;
	}
	else
	{
		printf("you have said %d\n", value);
		return value;
	}
}


int askUserYesNoQuestion (char *whatToAsk)
{
	char input[80];
	printf ("%s\n", whatToAsk);
	
	scanf ("%s", input);
	if (input[0] == 'Y' || input[0] == 'y')
	{
		return 1;
	}
	else
	{
		return 0;	
	}
}



int compareTwoFloats(float a, float b)
{
	if (fabs(a - b)/b < 0.01)
		return 0;
	else
		return 1;
}

float generateRandomFloat()
{
	return (float)rand()/(float)(RAND_MAX);
}

void printOutAMatrix(int M, int N, float *matrix)
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		printf ("\n");
		for (j = 0; j < N; j++)
		{
			printf ("%0.3f, ", matrix[i * N + j]);
		}
	}
	printf("\n\n");
}

void check_return_status(cl_int status)
{
	if (status != CL_SUCCESS) 
	{
		fprintf(stderr,  "\n\nOpenCL error in file %s line %d, error code %s\n\n\n", __FILE__,__LINE__,opencl_error_to_str(status));
		exit(1);
	}
}


void zeroMatrixOfFloats (float *matrix, int numberOfElements)
{
	for (int i = 0; i < numberOfElements; i++)
	{
		matrix[i] = (float)0.0;
	}
}

/**************************************************
* Function name : int main(void)
* returns : return status of the whole program
* argc : number of arguments
* *argv[] : array of strings representing each argument
* Created by : Steve Rubin
* Date created : 01/01/15
* Description : MAIN function of the project calling the kernel SpMV
* Notes : 
**************************************************/
int main(int argc, char *argv[])
//int main(void)
{


	if(argc != 7)
	{
    	printf("\n\n\nERROR! the command should look like \"./spmv <M> <K> <N> <where to put A> <where to put B> <where to put Y>\" \n\n\n");

    	exit(1);
   	}

	printf("\n\n\n\n\n				THE PROGRAM STARTS EXECUTING HERE\n\n");

	//create the OpenCL environment variables
	cl_context context;
	cl_context_properties properties[3];
	cl_kernel kernel;
	cl_command_queue command_queue;
	cl_program program;
	cl_int err;
	cl_uint num_of_platforms = 0;
	cl_platform_id platform_id;
	cl_device_id device_id;
	cl_uint num_of_devices = 0;
	size_t numberOfGlobalWorkItems, numberOfGlobalLocalItems;
	cl_int i, j, n, k, l;
	cl_event kernel_execution_time;
	int file_size;	
	cl_int errcode_ret;
	int M, K, N;


	/**************************************************
	* overhead which never changes
	*
	*
	*
	*
	**************************************************/
	// retreives a list of platforms available
	err = clGetPlatformIDs(1, &platform_id, &num_of_platforms);
	check_return_status(err);	

	// try to get a supported GPU device
	err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ACCELERATOR, 1, &device_id, &num_of_devices);
	check_return_status(err);
		

	// context properties list - must be terminated with 0
	properties[0]= CL_CONTEXT_PLATFORM;
	properties[1]= (cl_context_properties) platform_id;
	properties[2]= 0;

	// create a context with the DSP device
	context = clCreateContext(properties,1,&device_id,NULL,NULL,&err);
	check_return_status(err);	
	
	// create command queue using the context and device
	command_queue = clCreateCommandQueue(context, device_id, CL_QUEUE_PROFILING_ENABLE, &err);
	check_return_status(err);	
	
	// Creating program from the binary 
	FILE *fp;
	char fileName[] = "./kernel.out";
	size_t binary_size;
	char *binary_buf;
	cl_int binary_status;

	// Load kernel binary 
	fp = fopen(fileName, "r"); // opens filename in a "read" mode
	if (!fp) 
	{
		printf("Error opening the source file");
	}
	
	fseek(fp,0,SEEK_END);
	file_size = ftell(fp);
	fseek(fp,0,SEEK_SET);
	binary_buf = (char *)malloc(file_size);
	binary_size = fread(binary_buf, 1, file_size, fp);
	fclose(fp);
	
	// create kernel program from the kernel binary 
	program = clCreateProgramWithBinary(context, 1, &device_id, (const size_t *)&binary_size,
	(const unsigned char **)&binary_buf, &binary_status, &err);
	free(binary_buf);
		
	// check whether the program was created successfully
	check_return_status(err);	
	
	// compile the program
	err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	//err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	check_return_status(err);	
		
	// specify which kernel from the program to execute
	kernel = clCreateKernel(program, "spmv", &err);
	check_return_status(err);	

	numberOfGlobalWorkItems = 8;	
	numberOfGlobalLocalItems = 1;

	/**************************************************
	* overhead which never changes
	*
	*
	*
	*
	**************************************************/


	int possibleM = atoi(argv[1]);
	int possibleK = atoi(argv[2]);
	int possibleN = atoi(argv[3]);

	


	// setting up the ARM buffers
	float *amrY, *armA, *armB, *armY, *armYideal;


	boolean tryToPutAonMSMC = (argv[4][0] == 'M')?true:false;
	boolean tryToPutBonMSMC = (argv[5][0] == 'M')?true:false;
	boolean tryToPutYonMSMC = (argv[6][0] == 'M')?true:false;

	boolean AonMSMC = tryToPutAonMSMC;
	boolean BonMSMC = tryToPutBonMSMC;
	boolean YonMSMC = tryToPutYonMSMC;




	armY = (float*)__malloc_ddr(sizeof(float) * M * N);
	armA = (float*)__malloc_ddr(sizeof(float) * M * K);
	armB = (float*)__malloc_ddr(sizeof(float) * K * N);
	armYideal = (float*)__malloc_ddr(sizeof(float) * M * N);

	// make random data
	srand((unsigned int)time(NULL));
	for (i = 0 ; i < M*K; i++)
	{
		armA[i] = generateRandomFloat();
		if (i / K >= possibleM)
		{
			armA[i] = (float)0.0;	
		}
	}

	for (i = 0 ; i < K*N; i++)
	{
		armB[i] = generateRandomFloat();
		if (i - (i/N)*N >= possibleN)
		{
			armB[i] = (float)0.0;	
		}
		
	}

	for (i = 0 ; i < M*N; i++)
	{
		armY[i] = (float)1.0;
		armYideal[i] = (float)1.0;
	}

	boolean printoutMatrices = false;
	if(printoutMatrices)
	{
		printf("\nA = \n");
		printOutAMatrix(M, K, armA);
		printf("\nB = \n");
		printOutAMatrix(K, N, armB);
	}

	// setting up the DSP buffers
	cl_mem dspY, dspA, dspB;
	dspA = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, \
		sizeof(float) * M * K, armA, &err);
	dspB = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, \
		sizeof(float) * K * N, armB, &err);
	dspY = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, \
		sizeof(float) * M * N, armY, &err);


	float dspGFLOPs;
	dspGFLOPs = (float)0.0;
	cl_mem GFLOPs = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_USE_HOST_PTR, \
		sizeof(float), &dspGFLOPs, &errcode_ret);



	// set the argument list for the kernel command
	clSetKernelArg(kernel, 0, sizeof(cl_mem), &dspY);
	clSetKernelArg(kernel, 1, sizeof(cl_mem), &dspA);
	clSetKernelArg(kernel, 2, sizeof(cl_mem), &dspB);
	clSetKernelArg(kernel, 3, sizeof(int), &M);
	clSetKernelArg(kernel, 4, sizeof(int), &K);
	clSetKernelArg(kernel, 5, sizeof(int), &N);
	clSetKernelArg(kernel, 6, sizeof(int), &GFLOPs);




	err = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &numberOfGlobalWorkItems, &numberOfGlobalLocalItems, 0, NULL, &kernel_execution_time); // 8 work groups
	check_return_status(err);


	clFinish(command_queue);
	

	//clEnqueueReadBuffer(command_queue, dspY, CL_TRUE, 0, \
           sizeof(float) * M * N, armY, 0, NULL, NULL);


	// multiply matrices on ARM to get the ideal result
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (l = 0; l < K; l++)
				armYideal[i * N + j] += armA[i *  K + l] * armB[l * N + j];
		}
	}



	// compare armY and armYideal
	printf ("..comparinng dsp and arm results...\n");
	int flag = 0;
	for (i = 0; i < M * N; i++)
	{
		if (compareTwoFloats(armYideal[i], armY[i]) == 1)
		{
			printf ("error found %0.3f and %0.3f\n", armYideal[i], armY  [i]);
			flag = 1;
			break;
		}
	}

	if (!flag)
		printf("...DSP and ARM results match...\n!!! SUCCESS !!!\n");
	else
		printf("!!! ERROR!!! DSP and ARM results  DO NOT match...\n!!! FAIL !!!\n");


	printf("\nperformance %f\n", dspGFLOPs);



	if(YonMSMC)
		__free_msmc((void*)armY);
	else
		__free_ddr((void*)armY);

	if(AonMSMC)
		__free_msmc((void*)armA);
	else
		__free_ddr((void*)armA);

	if(BonMSMC)
		__free_msmc((void*)armB);
	else
		__free_ddr((void*)armB);

	__free_ddr((void*)armYideal);
	
	char *failedToAllocateOnMSMC = (char *)"(failed to allocate on MSMC)";
	printf("M = %d,K = %d,N = %d,A was on %s%s,B was on %s%s,Y was on %s%s,GFLOPS = %f,%s\n", M, N, K, AonMSMC?"MSMC" : "DDR", (AonMSMC != tryToPutAonMSMC) ? failedToAllocateOnMSMC: "", BonMSMC?"MSMC" : "DDR", (BonMSMC != tryToPutBonMSMC) ? failedToAllocateOnMSMC: "",  YonMSMC?"MSMC" : "DDR", (YonMSMC != tryToPutYonMSMC) ? failedToAllocateOnMSMC: "",  dspGFLOPs, flag?"FAILED":"PASSED");


	printf("\n\n\n\n\n				THE PROGRAM ENDS EXECUTING HERE\n\n");

	clReleaseProgram(program);
	clReleaseKernel(kernel);
	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);


	
	return 0;
}


