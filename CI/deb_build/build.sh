#!/bin/sh
version=$(git describe --tags --always --abbrev=0 2>/dev/null | { read input; if [ -z "$input" ]; then echo "1.0.0"; else echo "$input"; fi; })

docker build -t build-cpp:deb .
docker run -v "$PWD/../../:/build/" --user build -w "/build/build/debian" build-cpp:deb make version="$version"