bin_name = remote-graphics-tablet

link_libs = 
objects = main.o virtualInput.o

DEBUG?=0
STRICT?=1

ifneq ($(DEBUG), 0)
	DEBUG_FLAGS = -g
else
	DEBUG_FLAGS = 	
endif

ifneq ($(STRICT), 0)
	flags = -Wall -Wextra -Werror
else
	flags = -Wall -Wextra
endif

build: $(objects) # Build binary
	g++ $(objects) $(DEBUG_FLAGS) -o $(bin_name) $(link_libs) $(flags)

main.o:
	g++ -c main.cpp $(DEBUG_FLAGS) $(PROFILER_FLAGS) $(flags)
virtualInput.o:
	g++ -c virtualInput.cpp $(DEBUG_FLAGS) $(PROFILER_FLAGS) $(flags)

clean: # Delete all object files
	rm *.o -f