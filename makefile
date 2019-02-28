vpath %.hpp include/openal
#vpath %.cpp src

override CXXFLAGS += --std=c++17
CPPFLAGS = -I include/openal
LIBNAME := openal-wrapper
libfile := lib$(LIBNAME).a

srcs := src/bridge.cpp
objects := $(srcs:.cpp=.o)

$(libfile) : $(libfile)($(objects))

.PHONY : $(srcs)

clean:
	rm -f $(objects) $(libfile)

