#################################################################################
# Module name: Makefile
#
#	University of South Carolina
#
# First written  04/28/15 by Steve Rubin.
#
# Module Description: project makefile - compiles the code taking care of dependencies 
#						and then deletes all temporary files apart from kernel.asm and 
#						kernel.out as it is needed by main.cpp during the runtime
#
#################################################################################

EXE         = spmv
CPP_FLAGS   = -O0 -g
CLOCL_FLAGS = -k -O0 -g 
CLEAN		= rm -f *.bc *.if *.map kernel.obj *.o *_bc.asm *.opt

include /usr/share/ti/examples/opencl/make.inc

$(EXE): test.obj kernel.out main.o management.h 
	@$(CPP) -Wall $(CPP_FLAGS) main.o $(LD_FLAGS) $(LIBS) -o $@
	$(CLEAN)

kernel.out: kernel.cl management.h
	clocl -Wall kernel.cl $(CLOCL_FLAGS) test.obj
	
	
main.o: main.cpp 

test.obj: test.c
	cl6x -c $(CPP_FLAGS) test.c -I /usr/share/ti/cgt-c6x/include -I /usr/share/ti/opencl








