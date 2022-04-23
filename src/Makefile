CXX=g++
AR=ar
CFLAGS=-g -Wall
OBJS=CPU.o Core.o Mainboard.o Memory.o Program.o RAM.o Sector.o Util.o 

MAIN_SRC = mymain

LIB_SRC1 = myib_func_1
LIB_SRC2 = mylib_func_2

LIB_OUT = libjungchul.a

all :	$(MAIN_SRC)
$(MAIN_SRC) : $(MAIN_SRC).o $(LIB_OUT)
$(CC) -o $(MAIN_SRC) $(MAIN_SRC).o -L. -ljungchul
$(LIB_OUT) : $(LIB_SRC1).o $(LIB_SRC2).o
$(AR) ruv $(LIB_OUT) $(LIB_SRC1).o $(LIB_SRC2).o
$(MAIN_SRC).o : $(MAIN_SRC).c
$(CC) -c $(MAIN_SRC).c
$(LIB_SRC1).o : $(LIB_SRC1).c
$(CC) - c $(LIB_SRC1).c
$(LIB_SRC2).o : $(LIB_SRC2).c
$(CC) -c $(LIB_SRC2).c
clean :
rm - f *.o *.a $(MAIN_SRC)