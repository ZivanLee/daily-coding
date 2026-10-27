#ifndef __RING_BUF_H
#define __RING_BUF_H

typedef struct {
    char* buf;
    int size;
    int start;
    int end;
} RingBuf;

void RingBuf_Init(RingBuf* r, char* buf, int size);
int IsEmpty(RingBuf* r);
int IsFull(RingBuf* r);
int RingBuf_Write(RingBuf* r);
int RingBuf_Read(RingBuf* r);
#endif