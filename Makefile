# 컴파일 옵션
CC = g++
CXXFLAGS = 
LDFLAGS =

# 라이브러리 생성 옵션
AR = ar
ARFLAGS = rc
MAKELIB = $(AR) $(ARFLAGS)
LIB = libVirtualComputer.a

# 경로
VCSRC_DIR = /workspace/VirtualComputer/src/VirtualComputer
VCOBJ_DIR = /workspace/VirtualComputer/obj/VirtualComputer

# 소스코드
VCSRCS_Utils = $(wildcard $(VCSRC_DIR)/Utils/*.cpp)
VCSRCS_MainModule = $(wildcard $(VCSRC_DIR)/MainModule/*.cpp)
VCSRCS_ALL = $(VCSRCS_Utils) $(VCSRCS_MainModule)

# 오브젝트파일
VCSRCS = $(notdir $(wildcard $(VCSRC_DIR)/*.cpp))
VCOBJS = $(VCSRCS:.cpp=.o)
VCOBJECTS = $(patsubst %.o,$(VCOBJ_DIR)/%.o,$(VCOBJS))
VCDEPS = $(VCOBJECTS:.o=.d)

# 만들기
$(VCOBJ_DIR)/%.o : $(VCSRC_DIR)/../%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -MD

$(LIB) : $(VCOBJECTS)
	$(MAKELIB) $(LIB) $(VCOBJ_DIR)/%.o

-include $(VCDEPS)