FROM archlinux:latest

RUN pacman -Syu make gcc base-devel git --noconfirm

RUN mkdir /build && useradd build && chown build:build /build

RUN git config --global --add safe.directory /build