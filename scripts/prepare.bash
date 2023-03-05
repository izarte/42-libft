#!/bin/bash

name="deliverable"

if [ -d "${name}" ]; then rm -Rf ${name}; fi

mkdir -p "${name}"

for folder in "bonus" "libc" "aditional"
do
	cp "$folder"/*  "${name}"
done

cp scripts/deliverable_Makefile "${name}"/Makefile

cp include/* "${name}"