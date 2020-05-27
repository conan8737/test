#include"../core/timer_heap.h"
#include <sys/time.h> // gettimeofday、timeval
#include <stdio.h>

// 获取当前时间的函数，微妙级
double get_now_time()
{
    struct timeval now_tv;
	gettimeofday(&now_tv, NULL);
    return now_tv.tv_sec + (now_tv.tv_usec / 1000000.0);
}

void test_reverse_order_add(int count)
{
    TimerHeap *heap = new TimerHeap();
    double start_time = get_now_time();
    TimerHeapEntity event;
    int c = count;
    while(c--)
    {
        event.at = c;
        heap->add(event);
    }
    double end_time = get_now_time();

    printf("total: %d, spend: %f\n", count, end_time-start_time);

    int min = -999999;
    while(!heap->isEmpty())
    {
        event = heap->delMin();
        if(event.at < min)
        {
            printf("error, min: %d, at: %f\n", min, event.at);
            exit(EXIT_FAILURE);
        }
        min = event.at;
    }
    printf("order add pass test\n");
}


int main()
{
    test_reverse_order_add(100000000);
}
