CC = g++
CXXFLAGS = 
LDFLAGS =

AR = ar
ARFLAGS = rc
MAKELIB = $(AR) $(ARFLAGS)
LIB = libVirtualComputer.a

VCSRC_DIR = /workspace/VirtualComputer/src/VirtualComputer
VCOBJ_DIR = /workspace/VirtualComputer/obj/VirtualComputer

VCSRCS_Utils = $(wildcard $(VCSRC_DIR)/Utils/*.cpp)
VCSRCS_MainModule = $(wildcard $(VCSRC_DIR)/MainModule/*.cpp)
VCSRCS_ALL = $(VCSRCS_Utils) $(VCSRCS_MainModule)

VCOBJS = $(wildcard $(VCOBJ_DIR)/*.o)
VCDEPS = $(VCOBJECTS:.o=.d)

$(VCOBJ_DIR)/%.o : $(VCSRC_DIR)/MainModule/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

$(LIB) : $(VCOBJS)
	$(MAKELIB) $(LIB) $(VCOBJS)

-include $(VCDEPS)