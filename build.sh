#!/bin/sh
set -e

. ./config.sh

for SRC in $SRC_PATH; do
	(cd $SRC && DESTDIR="$ROOT" $MAKE)
done
