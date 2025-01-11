version = $(shell git describe --tags --always --abbrev=0 2>/dev/null | { read input; if [ -z "$$input" ]; then echo "1.0.0"; else echo "$$input"; fi; })
all:
	echo $(version)