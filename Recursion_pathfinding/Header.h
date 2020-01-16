
#pragma once
template<class T>
class list;

template<class T>
class node
{
	T data;
	node<T> * next;
	node<T> * prev;
public:
	node()
	{
		next = nullptr;
	}
	node(T d, node* n = nullptr)
	{
		data = d;
		next = n;
	}

	friend class list<T>;

};
template<class T>
class stack;
template<class T>
class list
{
	node<T>* head;
	class listiterator
	{
		node<T> * curr;
	public:
		friend class list;


		listiterator(node<T>* n = nullptr)
		{
			curr = n;
		}
		listiterator& operator++()
		{
			if (curr != nullptr)
				curr = curr->next;
			return *this;
		}
		listiterator& operator--()
		{
			if (curr != 0 && curr->prev != 0)
				curr = curr->prev;
			return *this;
		}
		bool operator!=(listiterator& it)
		{
			return(curr != it.curr);
		}
		T& operator*()
		{
			return(curr->data);
		}
		bool operator ==(listiterator& it)
		{
			return(curr == it.curr);
		}


	};
public:
	typedef listiterator diterator;
public:
	list()
	{
		head = nullptr;
	}
	void insertAtEnd(T data)
	{
		node<T>* temp = new node<T>(data);

		if (head == nullptr)
			head = temp;
		else
		{
			node<T>* curr = head;
			while (curr->next != nullptr)
				curr = curr->next;
			curr->next = temp;
		}

	}
	void removeFromEnd(T& data)
	{
		node<T>* temp = head;
		if (head->next != nullptr)
		{
			while (temp->next->next != 0)
				temp = temp->next;
			data = temp->next->data;
			delete temp->next;
			temp->next = nullptr;
		}
		else
		{
			data = head->data;
			delete head;
			head = 0;
		}
	}
	void accessTail(T& data)//copies the contents of the last element of list into the reference paramter
	{
		if (head->next != nullptr)
		{
			node<T>* temp = head;
			while (temp->next->next != 0)
				temp = temp->next;
			data = temp->next->data;
		}
		else
		{
			data = head->data;
		}
	}
	void printList()
	{

		node<T>* curr = head;
		while (curr != nullptr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << endl;
	}
	listiterator begin()
	{
		listiterator obj(head);
		return obj;
	}
	listiterator end()
	{
		listiterator obj;
		return obj;
	}
	void insertAtStart(T data)
	{
		node<T>* temp = new node<T>(data);
		temp->next = head;
		head = temp;
	}
	~list()
	{

		node<T>* curr = head;
		while (curr != 0)
		{
			head = head->next;
			delete curr;
			curr = head;
		}

	}
	friend class stack<T>;

};
template<class T>
class stack
{
	list<T> l;
public:
	stack()
	{

	}
	bool isEmpty()
	{
		return(l.head == nullptr);
	}
	bool isFull()
	{
		return false;
	}
	bool push(T data)
	{
		if (!isFull())
		{
			l.insertAtEnd(data);
			return true;
		}
		return false;
	}
	bool pop(T& data)
	{
		if (!isEmpty())
		{
			l.removeFromEnd(data);
			return true;
		}
		return false;
	}
	bool top(T& data)
	{
		if (!isEmpty())
		{
			l.accessTail(data);
			return true;
		}
		return false;
	}

};