bin_name = remote-mouse

build:
	make -C ../../src/
	mv ../../src/$(bin_name) $(bin_name)
	makepkg -r
	make -C ../../src/ clean
	rm pkg -rf
	rm src -rf
	rm $(bin_name)