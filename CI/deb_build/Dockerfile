FROM debian:latest

RUN apt update && apt install build-essential git -y

RUN mkdir /build && useradd build && chown build:build /build