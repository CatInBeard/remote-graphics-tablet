# Remote-mouse [![CodeFactor](https://www.codefactor.io/repository/github/catinbeard/remote-mouse/badge)](https://www.codefactor.io/repository/github/catinbeard/remote-mouse)  [![archlinux package builder](https://github.com/CatInBeard/remote-mouse/actions/workflows/arch_build.yaml/badge.svg)](https://github.com/CatInBeard/remote-mouse/actions/workflows/arch_build.yaml) [![debian package builder](https://github.com/CatInBeard/remote-mouse/actions/workflows/deb_build.yaml/badge.svg)](https://github.com/CatInBeard/remote-mouse/actions/workflows/deb_build.yaml) [![RPM package builder](https://github.com/CatInBeard/remote-mouse/actions/workflows/rpm_build.yaml/badge.svg)](https://github.com/CatInBeard/remote-mouse/actions/workflows/rpm_build.yaml) [![cppcheck static analysis](https://github.com/CatInBeard/remote-mouse/actions/workflows/cppcheck.yaml/badge.svg)](https://github.com/CatInBeard/remote-mouse/actions/workflows/cppcheck.yaml)  
Remote mouse utility allows you to control a virtual mouse/touchpad/graphics tablet from another computer, phone, or tablet.

## Communication
Go to [docs/comminication.md](./docs/communication.md) to read more about communication protocol

## Install
You can use packages from release:  
Go to [github.com/CatInBeard/remote-mouse/releases](https://github.com/CatInBeard/remote-mouse/releases)
### Archlinux
1. Download remote-mouse-XXX.pkg.tar.zst from latest release
2. run `pacman -U remote-mouse-XXX.pkg.tar.zst` to install from package
### Debian/Ubuntu (.deb)
1. Download remote-mouse-XXX.deb from latest release
2. run `dpkg -i remote-mouse-XXX.deb` to install from package
### Fedora/CentOS (.rpm) package
1. Download remote-mouse-XXX.rpm from latest release
2. run `rpm -i remote-mouse-XXX.rpm` to install from package

## Build
### Manual build
To build: 
1. `git clone https://github.com/CatInBeard/remote-mouse/`
2. `cd remote-mouse`
3. `cd src`
4. `make`
4. `make install`

### Archlinux package
1. `git clone https://github.com/CatInBeard/remote-mouse/`
2. `cd remote-mouse`
3. `cd build/archlinux`
4. `make`
5. `pacman -U remote-mouse-XXX.pkg.tar.zst`

### Debian/Ubuntu (.deb) package
1. `git clone https://github.com/CatInBeard/remote-mouse/`
2. `cd remote-mouse`
3. `cd build/debian`
4. `make`
5. `dpkg -i remote-mouse-XXX.deb`

### Fedora/CentOS (.rpm) package
1. `git clone https://github.com/CatInBeard/remote-mouse/`
2. `cd remote-mouse`
3. `cd build/rpm`
4. `make`
5. `rpm -i remote-mouse-XXX.rpm`

### Build all packages
You can build packages for different systems with docker. To do it run `build.sh` in:
1. CI/arch_build
2. CI/deb_build 
3. CI/rpm_build 
