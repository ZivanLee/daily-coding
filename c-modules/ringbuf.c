#include <stdio.h>
#include <stdlib.h>
#include "ringbuf.h"

void RingBuf_Init(RingBuf* r, char* buf, int size)
{
    r->buf = buf;
    r->size = size;
    r->start = 0;
    r->end = 0;
}


int IsEmpty(RingBuf* r)
{
    if(r->start == r->end)
    {
        return 1;
    }
    return 0;
}

int IsFull(RingBuf* r)
{
    if((r->end+1) % r->size == r->start)
    {
        return 1;
    }
    return 0;
}

int RingBuf_Write(RingBuf* r)
{
    if(!IsFull(r))
    {
        int start = r->start;
        r->buf[r->start] = 'a';
        r->start++;
        return abs(r->start - start)%r->size;
    }
    else {
        return 0;
    }
}

int RingBuf_Read(RingBuf* r)
{
    if(!IsEmpty(r))
    {
        int end = r->start;
        r->buf[r->start] = 'a';
        r->end++;
        return abs(r->end - end)%r->size;
    }
    else {
        return 0;
    }
}
