#!/bin/bash
sed -n -e '7,8p' README.md > List.md
sed -n -e '9,$p' README.md | sort -n -k2 -t '|' >> List.md
#sed -i '3d' List.md
