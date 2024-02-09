#!/bin/bash

mkdir -p cpputest/build & cd cpputest/build
autoreconfig .. -i
../configure
make

exit 0
