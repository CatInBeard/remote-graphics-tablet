FROM archlinux:latest

RUN pacman -Syu make gcc base-devel git --noconfirm

RUN mkdir /build && useradd build -m && chown build:build /build 

USER build

RUN git config --global --add safe.directory /build