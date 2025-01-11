#!/bin/sh

docker build -t build-cpp:fedora .
docker run -v "$PWD/../../:/build/" --user build -w "/build/build/rpm" build-cpp:fedora make