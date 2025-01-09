bin_name = remote-mouse

pkg_dir = pkg/DEBIAN
bin_dir = pkg/usr/local/bin
version = $(shell git describe --tags --abbrev=0 2>/dev/null || echo "1.0.0")
arch = $(shell uname -m | sed 's/x86_64/amd64/;s/i686/i386/;s/armv7l/armhf/;s/aarch64/arm64/')

build:
	make -C ../../src/
	mv ../../src/$(bin_name) $(bin_name)
	rm -rf pkg
	mkdir -p $(bin_dir)
	mkdir -p $(pkg_dir)
	cp $(bin_name) $(bin_dir)/
	echo "Package: $(bin_name)" > $(pkg_dir)/control
	echo "Version: $(version)" >> $(pkg_dir)/control
	echo "Section: utils" >> $(pkg_dir)/control
	echo "Priority: optional" >> $(pkg_dir)/control
	echo "Architecture:  $(arch)" >> $(pkg_dir)/control
	dpkg-deb --build pkg
	rm -rf $(bin_name) pkg
	mv pkg.deb "${bin_name}-${version}-${arch}.deb"

