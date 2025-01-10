#!/bin/sh

docker build -t build-cpp:deb .
docker run -v "$PWD/../../:/build/" --user build -w "/build/build/debian" build-cpp:deb make