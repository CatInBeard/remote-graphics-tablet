FROM fedora:latest

RUN yum install gcc gcc-c++ rpm-build rpm-devel rpmlint make rpmdevtools git -y

RUN mkdir /build && useradd build && chown build:build /build