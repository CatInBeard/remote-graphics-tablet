bin_name = remote-mouse

pkg_dir = pkg/DEBIAN
bin_dir = pkg/usr/local/bin
version ?= $(shell git describe --tags --always --abbrev=0 2>/dev/null | { read input; if [ -z "$$input" ]; then echo "1.0.0"; else echo "$$input"; fi; })
arch = $(shell uname -m | sed 's/x86_64/amd64/;s/i686/i386/;s/armv7l/armhf/;s/aarch64/arm64/')

all: build clean

build: build-bin
	rm -rf pkg
	mkdir -p $(bin_dir)
	mkdir -p $(pkg_dir)
	mv ../../src/$(bin_name) $(bin_name)
	cp $(bin_name) $(bin_dir)/

	echo "Package: $(bin_name)" > $(pkg_dir)/control
	echo "Version: $(version)" >> $(pkg_dir)/control
	echo "Section: utils" >> $(pkg_dir)/control
	echo "Priority: optional" >> $(pkg_dir)/control
	echo "Maintainer: 35694214+CatInBeard@users.noreply.github.com" >> $(pkg_dir)/control
	echo "Description: Remote mouse utility allows you to control a virtual mouse/touchpad/graphics tablet from another computer, phone, or tablet." >> $(pkg_dir)/control
	echo "Architecture:  $(arch)" >> $(pkg_dir)/control
	dpkg-deb --build pkg
	mv pkg.deb "${bin_name}-${version}-${arch}.deb"

clean: clean-bin
	rm -rf pkg
	rm -rf $(bin_name) pkg

build-bin:
	make -C ../../src/

clean-bin:
	make -C ../../src/ clean