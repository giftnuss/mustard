#!/bin/bash

#gcc -Wall -I ./include main.c

. functions

compile bool.c
compile tap.c
compile exceptions.c
compile list_of_nodes.c
compile node.c
compile public.c
compile textnode.c
compile text.c
compile symbol.c
compile leaf.c
compile symbolleaf.c
compile bitfield64.c
compile bitlist64.c
compile bitmap.c
compile list_of_leaves.c
#rm build/message.o
compile message.c
compile application.c
compile my.c
compile tags.c
compile tag.c
compile attribute.c
compile document.c

ar -v -r wisper.a build/*.o

#compile_sdl application_sdl.c

#build_and_run taptest.c
#build_and_run main.c

#build_and_run sample/01/hello.c
#build_sdl blinky.c


