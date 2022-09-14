#include <iostream>

using namespace std;

// interface IQueuable

class IQueuable
{
protected:
  struct node
  {
    string item;
    node *next;
  };

  node *first, *last, *current;
  int length;

public:
  // adds value to queue and returns new queue
  virtual string enqueue(string value) = 0;

  // removes item from queue, and returns the item removed
  virtual string dequeue() = 0;

  // returns a list of all the items in the queue
  virtual node *getQueue() = 0;

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
  }

  // adds value to queue and returns new queue
  string enqueue(string value)
  {
  }

  // removes item from queue, and returns the item removed
  string dequeue()
  {
  }

  // returns a list of all the items in the queue
  node *getQueue()
  {
  }

  // returns the number of items in the queue
  int size()
  {
  }

  // display method definition
  void display()
  {
  }
};

// Stack class
class Stack : public IQueuable
{
public:
  // contructor
  Stack()
  {
    first = NULL;
    last = NULL;
    length = 0;
  }

  // adds value to queue and returns new queue
  string enqueue(string value)
  {
    node *newItem = new node;

    if (newItem == NULL)
    {
      cout << "Stack enqueue cannot allocate a memory";
    }
    else
    {
      newItem->item = value;
      newItem->next = last;
      last = newItem;
      cout << "item has been stacked" << endl;
    }
    return last->item;
  }

  // removes item from queue, and returns the item removed
  string dequeue()
  {
    string store = "Stack is empty...!";
    if (last != NULL)
    {
      store = last->item;
      node *temp = last;
      last = last->next;
      temp = temp->next = NULL;
      delete temp;
      cout << "item has been unstacked" << endl;
    }
    return store;
  }

  // returns a list of all the items in the queue
  node *getQueue()
  {
    return last;
  }

  // returns the number of items in the queue
  int size()
  {
    length = 0;
    current = last;
    while (current != NULL)
    {
      length++;
      current = current->next;
    }
    return length;
  }

  // display method definition
  void display()
  {
    current = last;
    while (current != NULL)
    {
      cout << current->item << endl;
      current = current->next;
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
    cin.ignore(10, '\n');
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

  string item;
  char choice;
  while (true)
  {
    printStar();
    cout << "choose: \n1.add queue/stack\n2.delete queue/stack\n3.list all queue/stack\n4.queue size\n5.go back" << endl;
    printStar();
    cout << "please input your choose(1-5):";
    cin >> choice;
    cin.ignore(10, '\n');
    switch (choice)
    {
    case '1':
      cout << "input item to the queue/stack value:";
      cin >> item;
      cout << queue->enqueue(item) << endl;
      break;

    case '2':
      queue->dequeue();
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