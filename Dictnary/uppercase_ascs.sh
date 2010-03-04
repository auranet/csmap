#!/bin/bash

ls *.asc | while read filename; do ln -s "$filename" "$(echo $filename | tr '[:lower:]' '[:upper:]')"; done
