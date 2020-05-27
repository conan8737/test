#include"timer_heap.h"
#include<stdexcept>

// todo: g++ -O2 编译可以提升一倍的速度

// todo: 析构函数，析构函数是private还是public

inline void TimerHeap::swim(int k)
{
	int p = k >> 1;
	TimerHeapEntity ev = timers_[k];
	while(k>1 && ev.at < timers_[p].at)
	{
		timers_[k] = timers_[p]; // 之前的逻辑是交换，其实没必要交换，现在的这种实现相比交换提升了1倍
		k = p;
		p = k >> 1;
	}
	timers_[k] = ev;
}

inline void TimerHeap::sink(int k)
{
	int c = k << 1;
	TimerHeapEntity ev = timers_[k];
	while(c <= size_)
	{
		if(c < size_ && timers_[c+1].at < timers_[c].at) c++;
		if(ev.at < timers_[c].at)  break;
		timers_[k] = timers_[c];
		k = c;
		c = k << 1;
	}
	timers_[k] = ev;
}

/*public function*/
void TimerHeap::add(const TimerHeapEntity &v)
{
	// todo: 还有啥更好的动态伸缩方法
	if(size_ == capacity_)
	{
		capacity_ *= 2;
		timers_ = (TimerHeapEntity *)realloc(timers_, sizeof(TimerHeapEntity) *capacity_);
	}
	timers_[++size_].at = v.at;
	swim(size_);
}


TimerHeapEntity TimerHeap::delMin()
{
	if(size_ == 0)
	{
		std::logic_error e("min heap is empty!");
		throw std::exception(e);
	}
	TimerHeapEntity min = timers_[1];
	swap(1, size_--);
	sink(1);
	return min;
}


void TimerHeap::print()
{
	for(int i = 1; i <= size_; i++)
	{
		printf("%f ", timers_[i].at);
	}
	printf("\n");
}