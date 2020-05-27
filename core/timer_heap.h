
#include<stdlib.h>

typedef double tstamp_t;
typedef void (*timer_callback)(void *args);


// typedef struct 
// {
// 	TimerEvent *next;
// 	tstamp_t at;
// 	timer_callback callback;
// 	void *args;
// } TimerEvent;

typedef struct 
{
	tstamp_t at;

} TimerHeapEntity;

class TimerHeap
{
private:
	TimerHeapEntity *timers_;
	int capacity_;
	int size_;
	inline void swap(int i, int j){TimerHeapEntity tmp = timers_[i]; timers_[i] = timers_[j]; timers_[j] = tmp;}
	inline void swim(int k);
	inline void sink(int k);
	void print();
public:
	TimerHeap(): capacity_(1024), size_(0){ timers_ = (TimerHeapEntity *)malloc(sizeof(TimerHeapEntity) * (capacity_ + 1)); }
	TimerHeap(int capacity): capacity_(capacity), size_(0){ timers_ = (TimerHeapEntity *)malloc(sizeof(TimerHeapEntity) * (capacity_ + 1)); }
	void add(const TimerHeapEntity &v);
	TimerHeapEntity min() { return timers_[1]; }
	TimerHeapEntity delMin();
	inline bool isEmpty() { return size_ == 0; }
	inline int size() { return size_; }
};