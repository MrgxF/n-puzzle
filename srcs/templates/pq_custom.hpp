#ifndef	P_QUEUE_CUSTOM_HPP
# define P_QUEUE_CUSTOM_HPP

# include <vector>
# include <algorithm>
# include <iostream>

using namespace std;

template<typename T>
class pq_custom {

private:
	bool	(*f)(T*, T*);
	std::vector<T *>	queue;


public:
	pq_custom<T*>(bool (*func)(T*,T*)):f(func), queue()
	{
	}

	virtual ~pq_custom(){}

	typedef typename std::vector<T*>::iterator	iterator;

	void	push(T* el){
		queue.push_back(el);
		std::push_heap(queue.begin(), queue.end(), f);
	}

	T	*pop(){
		T *tmp = queue.front();

		std::pop_heap(queue.begin(), queue.end(), f);
		queue.pop_back();

		return tmp;
	}

	void sort(){
		std::make_heap(queue.begin(), queue.end(), f);
	}

	bool empty(){
		return queue.empty();
	}

	iterator	begin(){
		return queue.begin();
	}
	iterator	end(){
		return queue.end();
	}

};

template<typename T>
std::ostream	&operator<<(std::ostream &o, pq_custom<T> &c)
{
	for (auto it: c)
		o << it << " ";
	o << endl;
	return o;
}

#endif

