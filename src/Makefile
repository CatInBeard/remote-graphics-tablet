bin_name = remote_mouse

link_libs = 
objects = main.o virtualInput.o server.o consoleReflectionObserver.o connectionObserver.o mouseControllObserver.o cli.o CLIAuthorizationController.o communicationControllObserver.o iptools.o

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
server.o:
	g++ -c server.cpp $(DEBUG_FLAGS) $(PROFILER_FLAGS) $(flags)
consoleReflectionObserver.o:
	g++ -c consoleReflectionObserver.cpp $(DEBUG_FLAGS) $(PROFILER_FLAGS) $(flags)
connectionObserver.o:
	g++ -c connectionObserver.cpp $(DEBUG_FLAGS) $(PROFILER_FLAGS) $(flags)
mouseControllObserver.o:
	g++ -c mouseControllObserver.cpp $(DEBUG_FLAGS) $(PROFILER_FLAGS) $(flags)
cli.o:
	g++ -c cli.cpp $(DEBUG_FLAGS) $(PROFILER_FLAGS) $(flags)
CLIAuthorizationController.o:
	g++ -c CLIAuthorizationController.cpp $(DEBUG_FLAGS) $(PROFILER_FLAGS) $(flags)
communicationControllObserver.o:
	g++ -c communicationControllObserver.cpp $(DEBUG_FLAGS) $(PROFILER_FLAGS) $(flags)	
iptools.o:
	g++ -c iptools.cpp $(DEBUG_FLAGS) $(PROFILER_FLAGS) $(flags)	

clean: # Delete all object files
	rm *.o -f