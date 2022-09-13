#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

// interface IQueuable

class IQueuable
{
protected:
  int first, last, length;
  string queueNo[MAX_SIZE];

public:
  // adds value to queue and returns new queue
  virtual string *enqueue(string value) = 0;

  // removes item from queue, and returns the item removed
  virtual string dequeue() = 0;

  // returns a list of all the items in the queue
  virtual string *getQueue() = 0;

  // returns the number of items in the queue
  virtual int size() = 0;

  // for display purpose
  virtual void display() = 0;
};

// Queue class
class Queue : public IQueuable
{
public:
  // contructor
  Queue()
  {
    first = 0;
    last = MAX_SIZE - 1;
    length = 0;
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
      last = (last + 1) % MAX_SIZE;
      queueNo[last] = value;
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
      value = queueNo[first];
      first = (first + 1) % MAX_SIZE;
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

  // display method definition
  void display()
  {

    cout << "currently in queue:" << endl;
    for (int i = first; i != last; i = (i + 1) % MAX_SIZE)
    {
      if (size() == 0)
        break;
      cout << queueNo[i] << endl;
    }
    cout << queueNo[last] << endl
         << endl;
  }
};

// Stack class
class Stack : public IQueuable
{
public:
  // contructor
  Stack()
  {
    first = 0;
    last = -1;
    length = last + 1;
  }

  // adds value to queue and returns new queue
  string *enqueue(string value)
  {
    if (last == MAX_SIZE - 1)
    {
      cout << "Stack is full...!" << endl;
    }
    else
    {
      last++;
      queueNo[last] = value;
    }
    return queueNo;
  }

  // removes item from queue, and returns the item removed
  string dequeue()
  {
    string value = "empty Queue";
    if (last >= 0)
    {
      value = queueNo[last];
      last--;
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
    length = last + 1;
    return length;
  }

  // display method definition
  void display()
  {

    cout << "currently in queue:" << endl;
    for (int i = last; i >= first; i--)
    {
      cout << queueNo[i] << endl;
    }
  }
};

int main()
{
  IQueuable *queue;
  IQueuable *stack;
  queue = new Queue();
  stack = new Stack();
  // string arr[MAX_SIZE] = queue->getQueue();
  // Queue queue;

  queue->enqueue("101");

  stack->enqueue("101");
}