
#include <stdlib.h>

#include <wisper/exception/memoryerror.h>
#include <wisper/exception/outofmemory.h>
#include <wisper/exception/invalidindex.h>

void invalidindex_exception()
{
    exit(2);
}

void memoryerror_exception()
{
    exit(3);	
}

void outofmemory_exception()
{
    memoryerror_exception();
}

void overflow_exception()
{
    exit(4);	
}

