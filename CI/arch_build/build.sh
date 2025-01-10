#!/bin/sh

docker build -t build-cpp:arch .
docker run -v "$PWD/../../:/build/" --user build -w "/build/build/archlinux" build-cpp:arch make