bin_name = remote-mouse

all: build clean

build: build-bin
	rm pkg -rf
	rm src -rf
	mv ../../src/$(bin_name) $(bin_name)
	makepkg -r
build-bin:
	make -C ../../src/
clean: clean-bin
	rm pkg -rf
	rm src -rf
	rm $(bin_name)
clean-bin:
	make -C ../../src/ clean