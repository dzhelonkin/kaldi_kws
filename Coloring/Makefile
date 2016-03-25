# Stefano Gualandi, stefano.gualandi@gmail.com
# last update, May, 2013

CCX_FLAGS = -O2 -DNDEBUG -ggdb -fPIC -Wno-sign-compare -fpermissive
LD_FLAGS = -lm -lpthread

CC_FLAGS = -O3 -std=c++11


CCX    = g++

# Directory for my files
#MYHOME          = ${PWD}
#BIN             = ${MYHOME}
#INCLUDE         = ${MYHOME}
#LIB             = ${MYHOME}
#SRC             = ${MYHOME}

# Gecode directory
GECODE_INCLUDE  = ./gecode-4.4.0/
GECODE_LIB      = -L./gecode-4.4.0/ \
   -lgecodedriver -lgecodeint -lgecodekernel -lgecodeminimodel \
   -lgecodesearch -lgecodeset -lgecodesupport -lgecodefloat

# Cliquer
CLIQUER_DIR = ./cliquer-1.21
CLIQUER_OBJ = ${CLIQUER_DIR}/reorder.o ${CLIQUER_DIR}/cliquer.o ${CLIQUER_DIR}/graph.o
#CLIQUER_LIB = -L${CLIQUER_DIR}/ -lcl 
# My Files
all: vcp

vcp: VCPSolver.cc
	${CCX} ${CC_FLAGS} -c VCPSolver.cc -o VCPSolver.o -I${GECODE_INCLUDE} -I. -I${CLIQUER_DIR}
	${CCX} -o VCPSolver.x VCPSolver.o ${CLIQUER_OBJ}  ${GECODE_LIB} ${LD_FLAGS}

GeCol: GeCol.cc
	${CCX} ${CCX_FLAGS} -c GeCol.cc -o GeCol.o -I${GECODE_INCLUDE} -I. -I${CLIQUER_DIR}
	${CCX} -o GeCol.x GeCol.o ${CLIQUER_OBJ}  ${GECODE_LIB} ${LD_FLAGS}

## DSATUR by M.Trick
dsatur: dsatur.c
	gcc -c dsatur.c -funroll-loops -o dsatur.o -I${CLIQUER_DIR}
	gcc -o dsatur.x dsatur.o ${CLIQUER_OBJ}
