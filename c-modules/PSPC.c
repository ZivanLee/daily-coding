#include <stdio.h>
#include <pthread.h>
#include "ringbuf.h"

#define BUF_SIZE    128

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
void *process1(void* arg)
{
    RingBuf *r = (RingBuf*)arg;
    while(1)
    {
        pthread_mutex_lock(&lock);
        RingBuf_Write(r);
        pthread_mutex_unlock(&lock);
    }
    
}

void *process2(void* arg)
{
    RingBuf *r = (RingBuf*)arg;
    while(1)
    {
        pthread_mutex_lock(&lock);
        RingBuf_Read(r);
        pthread_mutex_unlock(&lock);
    }
    
}

int main()
{
    pthread_t tid1, tid2;
    RingBuf rb;
    char buf[BUF_SIZE] = {0};
    RingBuf_Init(&rb, buf, BUF_SIZE);
    pthread_create(&tid1, NULL, process1, &rb);
    pthread_create(&tid2, NULL, process2, &rb);
    // pthread_join(tid1, NULL);
    // pthread_join(tid2, NULL);
    while(1)
    {
        pthread_mutex_lock(&lock);
        for(int i = 0; i < rb.size; i++)
        {
            printf("%c\n", buf[i]);
        }
        pthread_mutex_unlock(&lock);
    }
}
