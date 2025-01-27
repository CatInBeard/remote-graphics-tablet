#!/bin/sh

git fetch origin main --tags
version=$(git tag --list --sort=-creatordate | grep -E '^[0-9]+\.[0-9]+\.[0-9]+$' | head -1 | { read input; if [ -z "$input" ]; then echo "1.0.0"; else echo "$input"; fi; })

docker build -t build-cpp:deb .
docker run -v "$PWD/../../:/build/" --user build -w "/build/build/debian" build-cpp:deb make version="$version"