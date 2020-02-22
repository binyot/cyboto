#!/bin/bash
for target in Debug Release; do
	path=build/"$(tr '[:upper:]' '[:lower:]' <<< "$target")"
	mkdir -p $path
	cd $path
	cmake -DCMAKE_BUILD_TYPE=$target ../..
	make
	cd ../..
done

