#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node* next;

	node(int d)
	{
		data = d;
		next = NULL;
	}
};

class queue
{
public:
	node* front = NULL;
	node* back = NULL;

	void enqueue(int v)
	{
		node* temp = new node(v);
		if (front == NULL)
		{
			front = temp;
			back = temp;
			return;
		}
		back->next = temp;
		back = temp;
	}

	void dequeue()
	{
		if (front == NULL)
		{
			cout << "Queue underflow" << endl;
			return;
		}

		node* todelete = front;
		front = front->next;
		delete todelete;
	}

	int peak()
	{
		if (front == NULL)
		{
			cout << "Queue underflow" << endl;
			return -1;
		}
		else
		{
			return front->data;
		}
	}

	void display(node*& front)
	{
		node* temp = front;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

void main()
{
	queue Q;
	Q.enqueue(1);
	Q.enqueue(2);
	Q.enqueue(3);
	Q.enqueue(4);

	cout << "Queue Elements: ";
	Q.display(Q.front);
	cout << endl;

	Q.dequeue();
	cout << "Queue after dequeuing: ";
	Q.display(Q.front);
	cout << endl;

	cout << "Queue Top Elements: " << Q.peak() << endl;
}