#!/bin/sh

echo "Compiling sources ..."
gcc -o bin/browser *.c *.h `pkg-config --libs --cflags gtk+-3.0 glib-2.0`
echo "Compiled successfully, executable in bin/"
