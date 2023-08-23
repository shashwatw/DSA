class Queue {

	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		if (rear == arr.size()) return;

		// Enqueue the element at the rear of the queue.
		arr[rear] = e;
		rear++;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		if (front == rear) return -1;
		
		// Dequeue the element at the front of the queue.
		int e = arr[front];
		front++;
		return e;
	}
};