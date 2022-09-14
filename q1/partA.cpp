#include <iostream>

using namespace std;

const int MAX_SIZE = 50;

// interface IQueuable

class IQueuable
{
protected:
  int first, last, length;
  string item[MAX_SIZE];

public:
  // adds value to queue and returns new queue
  virtual string *enqueue(string value) = 0;

  // removes item from queue, and returns the item removed
  virtual string dequeue() = 0;

  // returns a list of all the items in the queue
  virtual string *getQueue() = 0;

  // returns the number of items in the queue
  virtual int
  size() = 0;

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
      item[last] = value;
      length++;
      cout << "item [ " << value << " ] has been added to the queue\n\n";
    }

    return item;
  }

  // removes item from queue, and returns the item removed
  string dequeue()
  {
    string value = "empty Queue...!";
    if (length != 0)
    {
      value = item[first];
      first = (first + 1) % MAX_SIZE;
      --length;
      cout << "item has been dequeued " << endl;
    }

    return value;
  }

  // returns a list of all the items in the queue
  string *getQueue()
  {
    return item;
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
      cout << item[i] << endl;
    }
    cout << item[last] << endl
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
      item[last] = value;
      cout << "item [ " << value << " ] has been added to the stack\n\n";
    }
    return item;
  }

  // removes item from queue, and returns the item removed
  string dequeue()
  {
    string value = "empty Stack...!";
    if (last >= 0)
    {
      value = item[last];
      last--;
      cout << "item has been unstacked " << endl;
    }

    return value;
  }

  // returns a list of all the items in the queue
  string *getQueue()
  {
    return item;
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

    cout << "currently in Stack:" << endl;
    for (int i = last; i >= first; i--)
    {
      cout << item[i] << endl;
    }
  }
};

// extra functions will be defined at the end:

//    for testing purpose
void testing(IQueuable *);
//     for display clarity
void printStar();

// the main
int main()
{
  IQueuable *queue;
  printStar();
  cout << "\nclasses impelementation test" << endl;
  printStar();

  char choice;
  while (true)
  {
    printStar();
    cout << "please choose testing options: \n1.queue\n2.stack\n3.exit" << endl;
    printStar();
    cout << "please input your choose (1-3):";
    cin >> choice;
    switch (choice)
    {
    case '1':
      queue = new Queue();
      testing(queue);
      break;

    case '2':
      queue = new Stack();
      testing(queue);

    case '3':
      return 0;
      break;

    default:
      cout << "please enter a valid option!" << endl;
      break;
    }
  }
}

// extra functions definitions:

// for testing purpose

void testing(IQueuable *queue)
{
  printStar();
  cout << "\nQueue class test" << endl;
  printStar();

  string item;
  char choice;
  while (true)
  {
    printStar();
    cout << "choose: \n1.add queue/stack\n2.delete queue/stack\n3.list all queue/stack\n4.queue size\n5.go back" << endl;
    printStar();
    cout << "please input your choose(1-5):";
    cin >> choice;
    switch (choice)
    {
    case '1':
      cout << "input item to the queue/stack value:";
      cin >> item;
      queue->enqueue(item);
      queue->display();
      break;

    case '2':
      cout << queue->dequeue() << endl;
      break;
    case '3':
      queue->display();
      break;
    case '4':
      cout << "queue/stack size is :" << queue->size() << endl;
      break;
    case '5':
      return;
      break;

    default:
      cout << "please enter a valid option!" << endl;
      break;
    }
  }
}
// for display clarity
void printStar()
{
  cout << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << "***";
  }
  cout << endl;
}