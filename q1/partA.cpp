#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

// interface IQueuable

class IQueuable
{

public:
  // adds value to queue and returns new queue
  virtual string *enqueue(string value) = 0;

  // removes item from queue, and returns the item removed
  virtual string dequeue() = 0;

  // returns a list of all the items in the queue
  virtual string *getQueue() = 0;

  // returns the number of items in the queue
  virtual int size() = 0;
};

// Queue class
class Queue : public IQueuable
{
private:
  int front, rear, length;
  string queueNo[MAX_SIZE];

public:
  // contructor
  Queue()
  {
    front = 0;
    rear = MAX_SIZE - 1;
    length = 0;
  }

  // accessor method for the first one in the queue
  int getFront()
  {
    return this->front;
  }

  // accessor method for the last one in the queue
  int getRear()
  {
    return this->rear;
  }

  // adds value to queue and returns new queue
  string *enqueue(string value)
  {
    if (length == MAX_SIZE)
    {
      cout << "\n\n"
           << "Queue is Full, Please wait..!" << endl;
    }
    else
    {
      rear = (rear + 1) % MAX_SIZE;
      queueNo[rear] = value;
      length++;
    }

    return queueNo;
  }

  // removes item from queue, and returns the item removed
  string dequeue()
  {
    string value = "empty Queue";
    if (length != 0)
    {
      value = queueNo[front];
      front = (front + 1) % MAX_SIZE;
      --length;
    }

    return value;
  }

  // returns a list of all the items in the queue
  string *getQueue()
  {
    return queueNo;
  }

  // returns the number of items in the queue
  int size()
  {
    return length;
  }
};

// for display purpose
void display(string *list, Queue q)
{

  cout
      << "currently in queue:" << endl;
  for (int i = q.getFront(); i != q.getRear(); i = (i + 1) % MAX_SIZE)
  {
    if (q.size() == 0)
      break;
    cout << list[i] << endl;
  }
  cout << list[q.getRear()] << endl
       << endl;
}

int main()
{
  // IQueuable *queue;
  // queue = new Queue();
  // string arr[MAX_SIZE] = queue->getQueue();
  Queue queue;

  display(queue.enqueue("101"), queue);
  display(queue.enqueue("102"), queue);
  display(queue.enqueue("103"), queue);
  display(queue.enqueue("104"), queue);
  display(queue.enqueue("105"), queue);
  cout << queue.dequeue() << endl;
  display(queue.enqueue("106"), queue);
  display(queue.enqueue("107"), queue);
  display(queue.enqueue("108"), queue);
  display(queue.enqueue("109"), queue);
  display(queue.enqueue("110"), queue);
}