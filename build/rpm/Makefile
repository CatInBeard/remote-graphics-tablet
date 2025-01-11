bin_name = remote-mouse
version ?= $(shell git describe --tags --always --abbrev=0 2>/dev/null | { read input; if [ -z "$$input" ]; then echo "1.0.0"; else echo "$$input"; fi; })
release = 1
arch = $(shell uname -m)

spec_file = $(bin_name).spec
rpm_file = $(bin_name)-$(version)-$(release)-$(arch).rpm

all: build clean

build: build-bin
	mv ../../src/$(bin_name) $(bin_name)
	echo "Name: $(bin_name)" > $(spec_file)
	echo "Version: $(version)" >> $(spec_file)
	echo "Release: $(release)" >> $(spec_file)
	echo "Summary: Remote input" >> $(spec_file)
	echo "License: MIT" >> $(spec_file)
	echo "URL: https://github.com/CatInBeard/remote-mouse" >> $(spec_file)
	echo "Group: Applications/Utilities" >> $(spec_file)
	echo "BuildRoot: %{_tmppath}/%{name}" >> $(spec_file)
	echo "" >> $(spec_file)
	echo "%description" >> $(spec_file)
	echo "Remote mouse utility allows you to control a virtual mouse/touchpad/graphics tablet from another computer, phone, or tablet." >> $(spec_file)
	echo "" >> $(spec_file)
	echo "%prep" >> $(spec_file)
	echo "cp $(CURDIR)/$(bin_name) ." >> $(spec_file)
	echo "" >> $(spec_file)
	echo "%install" >> $(spec_file)
	echo "mkdir -p %{buildroot}%{_bindir}" >> $(spec_file)
	echo "cp $(bin_name) %{buildroot}%{_bindir}/$(bin_name)" >> $(spec_file)
	echo "" >> $(spec_file)
	echo "%files" >> $(spec_file)
	echo "%{_bindir}/$(bin_name)" >> $(spec_file)
	echo "" >> $(spec_file)
	rpmbuild -bb --target $(arch) $(spec_file)
	cp ~/rpmbuild/RPMS/$(arch)/* .


clean: clean-bin
	rm -f $(spec_file)
	rm -f $(bin_name)

build-bin:
	make -C ../../src/

clean-bin:
	make -C ../../src/ clean