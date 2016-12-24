#pragma once


template <class T>
class MyLinkedList
{
public:
	MyLinkedList();
	~MyLinkedList();
	MyLinkedList(const MyLinkedList<T> &list);
	MyLinkedList<T>& operator=(const MyLinkedList<T> &list);

	MyLinkedList(MyLinkedList<T> &&list);
	MyLinkedList<T>& operator=(MyLinkedList<T> &&list);
	
	void Add(T value);
	
	void Remove(T value);
	void RemoveAt(int i);
	void RemoveAll();

	T* GetAt(int i);
	size_t GetSize();
	void Print();

private:
	class MyLinkedListNode
	{
		friend class MyLinkedList;
		public:
			MyLinkedListNode(T val);
			~MyLinkedListNode() {};
			void Print();

		private:
			T value;
			MyLinkedListNode *next;

	};

	size_t size;
	MyLinkedListNode *head;
};

template <class T>
MyLinkedList<T>::MyLinkedList()
	:size(0), head(nullptr)
{	
	std::cout << this << "  Empty Constructor" << std::endl;
}

template<class T>
MyLinkedList<T>::MyLinkedList(const MyLinkedList<T>& list)
	:MyLinkedList()
{
	std::cout << this << "  Copy Constructor" << std::endl;

	MyLinkedListNode *ptr = list.head;
	while (ptr != nullptr)
	{
		T node = ptr->value;
		this->Add(node);

		ptr = ptr->next;
	}
}

template<class T>
MyLinkedList<T>& MyLinkedList<T>::operator=(const MyLinkedList<T>& list)
{
	std::cout << this << "  Assignment" << std::endl;

	this->RemoveAll();

	MyLinkedListNode *ptr = list.head;
	while (ptr != nullptr)
	{
		T node = ptr->value;
		this->Add(node);

		ptr = ptr->next;
	}
	return *this;
}

template<class T>
MyLinkedList<T>::MyLinkedList(MyLinkedList<T>&& list)
	:size(list.size), head(list.head)
{		
	std::cout << this << "  Move Constructor" << std::endl;
	list.head = nullptr;
}

template<class T>
MyLinkedList<T>& MyLinkedList<T>::operator=(MyLinkedList<T>&& list)
{
	std::cout << this << "  Move Assignment" << std::endl;

	this->RemoveAll();
	this->size = list.size;
	this->head = list.head;

	list.head = nullptr;

	return *this;
}


template <class T>
MyLinkedList<T>::~MyLinkedList()
{	
	std::cout << this << "  Destructor" << std::endl;
	RemoveAll();
}


template <class T>
void MyLinkedList<T>::Add(T val)
{
	MyLinkedListNode* node = new MyLinkedListNode(val);

	if (head == nullptr)
		head = node;
	else
	{
		MyLinkedListNode *ptr = head;
		while (ptr->next != nullptr)
			ptr = ptr->next;
		ptr->next = node;
	}
	++size;
}

template <class T>
void MyLinkedList<T>::Remove(T val)
{
	if (head->value == val)
	{
		MyLinkedListNode* ptr = head->next;
		delete head;
		head = ptr;
		--size;
		return;
	}

	MyLinkedListNode *pre = nullptr;
	MyLinkedListNode *cur = head;

	while (cur != nullptr & cur->value != val)
	{
		pre = cur;
		cur = cur->next;
	}

	if (cur->value == val)
	{
		pre->next = cur->next;
		delete cur;		
		--size;
	}
}

template <class T>
void MyLinkedList<T>::RemoveAt(int i)
{
	if (i >= size)
		return;

	if (i == 0) {
		head = head->next;
		return;
	}

	int index = 0;
	MyLinkedListNode *cur = head;
	while (index + 1 != i)
	{
		cur = cur->next;
		++index;
	}

	cur->next = cur->next->next;
	--size;
}

template<class T>
void MyLinkedList<T>::RemoveAll()
{
	while (head != nullptr)
	{
		MyLinkedListNode* ptr = head->next;
		delete head;
		head = ptr;
	}
	size = 0;
}

template <class T>
T* MyLinkedList<T>::GetAt(int i)
{
	if (i >= size)
		return nullptr;

	MyLinkedList::MyLinkedListNode* ptr = head;
	int index = 0;
	while (index++ != i)
		ptr = ptr->next;

	return ptr->value;
}

template <class T>
inline size_t MyLinkedList<T>::GetSize()
{
	return size;
}

template <class T>
void MyLinkedList<T>::Print()
{
	MyLinkedListNode *cur = head;
	while (cur != nullptr) {
		cur->Print();
		cur = cur->next;
	}
	std::cout << std::endl;
}

template <class T>
MyLinkedList<T>::MyLinkedListNode::MyLinkedListNode(T val)
	:value(val), next(nullptr)
{	
}

template <class T>
void MyLinkedList<T>::MyLinkedListNode::Print()
{
	std::cout << value << " " << std::endl;
}


