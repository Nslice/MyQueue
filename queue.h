#ifndef QUEUE_H_
#define QUEUE_H_

template<typename Type>
class Queue
{
private:
	struct Node
	{
		Type data;
		Node* pNext;
		Node* pPrev;

		Node(Type data = Type(), Node* next = nullptr, Node* prev = nullptr)
		{
			this->data = data;
			this->pNext = next;
			this->pPrev = prev;
		}
	};

    Node* head;     // pointer to front of Queue
    Node* tail;     // pointer to rear of Queue
    int items;      // current number of items in Queue
    
	
public:
    Queue(); 
	Queue(const Queue& other);
    ~Queue();
	
	Queue& operator=(const Queue& other);


	inline int size() const;
	inline bool empty() const;

	inline Type& front();
	inline const Type& front() const;
	
	inline Type& back();
	inline const Type& back() const;

	void push(const Type&);
	void pop();
	void clear();
};


//************************************************************************
template<typename Type>
Queue<Type>::Queue()
{
	head = tail = nullptr;
	items = 0;
}


template<typename Type>
Queue<Type>::Queue(const Queue<Type>& other)
{
	Queue();
	Node* tmp = other.head;
	while (tmp)
	{
		push(tmp->data);
		tmp = tmp->pNext;
	}
}


template<typename Type>
Queue<Type>::~Queue()
{
	clear();
}


template<typename Type>
Queue<Type>& Queue<Type>::operator=(const Queue<Type>& other)
{
	if (&other == this)
		return *this;

	clear();
	Node* tmp = other.head;
	while (tmp)
	{
		push(tmp->data);
		tmp = tmp->pNext;
	}
}


template<typename Type>
inline int Queue<Type>::size() const
{
	return items;
}


template<typename Type>
inline bool Queue<Type>::empty() const
{
	return !items;
}


template<typename Type>
inline Type& Queue<Type>::front()
{
	return head->data;
}
template<typename Type>
inline const Type& Queue<Type>::front() const
{
	return head->data;
}


template<typename Type>
inline Type& Queue<Type>::back()
{
	return tail->data;
}
template<typename Type>
inline const Type& Queue<Type>::back() const
{
	return tail->data;
}


template<typename Type>
void Queue<Type>::push(const Type& item)
{
	if (!head)
		head = tail = new Node(item);
	else
	{
		tail->pNext = new Node(item, nullptr, tail);
		tail = tail->pNext;
	}
	
	items++;
}


template<typename Type>
void Queue<Type>::pop()
{
	if (!head) throw std::runtime_error("deque empty before pop");

	if (head == tail)
	{
		delete head;
		tail = head = nullptr;
	}
	else
	{
		head = head->pNext;
		delete head->pPrev;
		head->pPrev = nullptr;
	}
	
	items--;
}


template<typename Type>
void Queue<Type>::clear()
{
	while (head)
		pop();
}


#endif // !QUEUE_H_