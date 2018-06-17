# 数据结构—栈(Stack)

## 栈的定义和基本运算

栈（Stack）是一种后进先出（last in first off，LIFO）或先进后出（first in last out，FILO）的数据结构。它还可以理解为运算受限的线性表，其限制是仅允许在表的一端进行插入和删除运算。这一端被称为栈顶，相对地，把另一端称为栈底。

注：栈可以看成水杯，先导入水，水慢慢向上积累，再将水倒出来时，最上面的水先出来，这就符合先进后出，后进先出的规则。

栈有下面几种基本运算：

- push（压入）：向栈中添加元素（一般向栈顶处添加）。如果栈已满（full），即为溢出（overflow）情况。
- pop（推出）：从栈中删除元素（一般删除栈顶元素）。如果栈是空的，即为下溢（underflow）情况。
- Peek 或者 Top：返回栈顶元素。
- isEmpty（是否为空）：如果栈为空，返回True；反之，返回False。

![栈(Stack)](https://www.geeksforgeeks.org/wp-content/uploads/gq/2013/03/stack.png)

## 栈运算的复杂度

- push()：O(1)
- pop()：O(1)
- peek()复杂度：O(1)
- isEmpty()：O(1)

## 用数组实现栈

用数组实现栈，实质上是实现了"伪"栈，本质是数组，但添加了pop、push、isEmpty函数来控制数组的索引，造成栈的假象。比如使用push()向栈中添加元素时，只是给数组当前索引的下一个索引对应的内存空间赋值而已。

注：为什么认为是伪栈呢？因为数组必须初始化其容量大小，那么将数组作栈的基本数据结构时，其内存空间大小一开始就已经确定好了，哪怕对栈进行pop，实质上内存空间没有变化。

**C++**

```c++
/* C++ program to implement basic stack
   operations */
#include <iostream>
using namespace std;

// 定义栈的最大容量
#define MAX 1000
 
class Stack
{
    int top;	   // 栈顶索引
public:
    int a[MAX];    // Maximum size of Stack
 
    Stack()  { top = -1; }	// 构造函数
    bool push(int x);
    int pop();
    bool isEmpty();
};
// push()压入元素
bool Stack::push(int x)
{
  	// 判断栈顶索引
    if (top >= MAX)
    {
        cerr << "Stack Overflow" <<endl;	// 溢出
        return false;
    }
    else
    {
        a[++top] = x;	// 向数组中添加元素
        return true;
    }
}
// pop()推出元素
int Stack::pop()
{
  	// 判断栈顶索引
    if (top < 0)
    {
        cerr << "Stack Underflow" <<endl;	// 下溢
        return 0;
    }
    else
    {
        int x = a[top--];	// 删除栈顶元素
        return x;
    }
}
// 判断栈是否为空
bool Stack::isEmpty()
{
    return (top < 0);
}
 
// Driver program to test above functions
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
 
    cout << s.pop() << " Popped from stack\n";
 
    return 0;
}
```

**Python**

```python
# Python program for implementation of stack
 
# import maxsize from sys module 
# Used to return -infinite when stack is empty
from sys import maxsize
 
# Function to create a stack. It initializes size of stack as 0
def createStack():
    stack = []
    return stack
 
# Stack is empty when stack size is 0
def isEmpty(stack):
    return len(stack) == 0
 
# Function to add an item to stack. It increases size by 1
def push(stack, item):
    stack.append(item)
    print("pushed to stack " + item)
     
# Function to remove an item from stack. It decreases size by 1
def pop(stack):
    if (isEmpty(stack)):
        return str(-maxsize -1) #return minus infinite
     
    return stack.pop()
 
# Driver program to test above functions    
stack = createStack()
push(stack, str(10))
push(stack, str(20))
push(stack, str(30))
print(pop(stack) + " popped from stack")
```

## 用链表实现栈

用链表实现栈，个人较为符合真正栈的意义。

C

```c
// C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
// A structure to represent a stack
struct StackNode
{
    int data;
    struct StackNode* next;
};
 
struct StackNode* newNode(int data)
{
    struct StackNode* stackNode =
              (struct StackNode*) malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
 
int isEmpty(struct StackNode *root)
{
    return !root;
}
 
void push(struct StackNode** root, int data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}
 
int pop(struct StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
 
    return popped;
}
 
int peek(struct StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}
 
int main()
{
    struct StackNode* root = NULL;
 
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
 
    printf("%d popped from stack\n", pop(&root));
 
    printf("Top element is %d\n", peek(root));
 
    return 0;
}
```

Python

```python
# Python program for linked list implementation of stack
 
# Class to represent a node
class StackNode:
 
    # Constructor to initialize a node
    def __init__(self, data):
        self.data = data 
        self.next = None
 
class Stack:
     
    # Constructor to initialize the root of linked list
    def __init__(self):
        self.root = None
 
    def isEmpty(self):
        return True if self.root is None else  False
 
    def push(self, data):
        newNode = StackNode(data)
        newNode.next = self.root 
        self.root = newNode
        print "%d pushed to stack" %(data)
     
    def pop(self):
        if (self.isEmpty()):
            return float("-inf")
        temp = self.root 
        self.root = self.root.next
        popped = temp.data
        return popped
     
    def peek(self):
        if self.isEmpty():
            return float("-inf")
        return self.root.data
 
# Driver program to test above class 
stack = Stack()
stack.push(10)        
stack.push(20)
stack.push(30)
 
print "%d popped from stack" %(stack.pop())
print "Top element is %d " %(stack.peek())
 
# This code is contributed by Nikhil Kumar Singh(nickzuck_007)
```



# 数据结构—队列(Queue)

## 队列的定义和基本运算

队列（Queue）是限制结点插入操作固定在一端进行，而结点的删除操作固定在另一端进行的线性表。

队列犹如一个两端开口的管道。允许插入的一端称为队头，允许删除的一端称为队尾。队头和队尾各用一个”指针”指示，称为队头指针和队尾指针。不含任何结点的队列称为”空队列”。队列的特点是结点在队列中的排队次序和出队次序按进队时间先后确定，即先进队者先出队。因此，队列又称先进先出表。简称FIFO(first in first out)表。

队列的一个很好的例子就是消费者排队：消费者先排队先消费。

队列的基本运算如下：

- Enqueue（入队/插入）：添加元素到队列中。如果队列满了，则表示溢出（Overflow）情况。
- Dequeue（出队/删除）：从队列中剔除元素。该元素被压出（pop）的顺序与push（压入）的顺序一样。如果队列是空的，则表示下溢（underflow）情况。
- Front（队头）：从队列中获得最前面的元素。
- Rear（队尾）：从队列中获得最后面的元素。

![Queue](https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/02/Queue.png)

队列初始条件：队头指针=队尾指针=0

队列满条件：队尾指针=m（设队列当前容量为m）

队列空条件：队头指针=队尾指针

## 队列的应用

如果不必立即处理事件时，则可以使用队列，特别是使用“广度优先搜索”中的“先入先出”顺序进行处理。队列的这个属性使它在以下类型的场景中也很有用。

1）资源在多个消费者之间共享。 例子包括CPU调度（scheduling），磁盘调度。
2）在两个进程（processing）之间异步传输数据（数据接收的速度不一定与发送的速度相同）。例子包括IO缓冲区（Buffers），pipes，file IO等。

有关队列和堆栈的更多详细信息，请参阅此处。

## 用数组实现队列

为了实现队列，我们需要跟踪队头（front）和队尾（rear）的两个索引。我们在队尾插入元素并在队头删除元素。如果我们只是增加队头和队尾的索引，那么可能会出现问题，队头可能会到达数组的末端。解决这个问题的方法是以**循环（circular）**的方式增加队头和队尾。

[Inplement Queue using array](https://practice.geeksforgeeks.org/problems/implement-queue-using-array/1)

C

```c
// C program for array implementation of queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
// A structure to represent a queue
struct Queue
{
    int front, rear, size;	// 队头指针、队尾指针和队列有效元素数量
    unsigned capacity;	    // 队列最大容量 
    int* array;	// 存储队列值的数组
};
 
// function to create a queue of given capacity. 
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}
 
// Queue is full when size becomes equal to the capacity 
int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }
 
// Function to add an item to the queue.  
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}
 
// Function to remove an item from queue. 
// It changes front and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
 
// Driver program to test above functions./
int main()
{
  	// 初始化队列，分配空间为1000
    struct Queue* queue = createQueue(1000);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n", dequeue(queue));
 
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
 
    return 0;
}
```

Python

```python
# Python3 program for array implementation of queue
 
# Class Queue to represent a queue
class Queue:
 
    # __init__ function
    def __init__(self, capacity):
        self.front = self.size = 0
        self.rear = capacity -1
        self.Q = [None]*capacity
        self.capacity = capacity
     
    # Queue is full when size becomes
    # equal to the capacity 
    def isFull(self):
        return self.size == self.capacity
     
    # Queue is empty when size is 0
    def isEmpty(self):
        return self.size == 0
 
    # Function to add an item to the queue. 
    # It changes rear and size
    def EnQueue(self, item):
        if self.isFull():
            print("Full")
            return
        self.rear = (self.rear + 1) % (self.capacity)
        self.Q[self.rear] = item
        self.size = self.size + 1
        print("%s enqueued to queue"  %str(item))
 
    # Function to remove an item from queue. 
    # It changes front and size
    def DeQueue(self):
        if self.isEmpty():
            print("Empty")
            return
         
        print("%s dequeued from queue" %str(self.Q[self.front]))
        self.front = (self.front + 1) % (self.capacity)
        self.size = self.size -1
         
    # Function to get front of queue
    def que_front(self):
        if self.isEmpty():
            print("Queue is empty")
 
        print("Front item is", self.Q[self.front])
         
    # Function to get rear of queue
    def que_rear(self):
        if self.isEmpty():
            print("Queue is empty")
        print("Rear item is",  self.Q[self.rear])
 
 
# Driver Code
if __name__ == '__main__':
 
    queue = Queue(30)
    queue.EnQueue(10)
    queue.EnQueue(20)
    queue.EnQueue(30)
    queue.EnQueue(40)
    queue.DeQueue()
    queue.que_front()
    queue.que_rear()
```



## 队列的类型

- [ ] 待补充详细内容

- 顺序队列
- 循环队列
- 链队列






# 使用栈实现队列

https://www.geeksforgeeks.org/queue-using-stacks/



# 参考

## 栈(Stack)

[Wiki: Stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

**（推荐）**[Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)

[什么是“堆”,"栈","堆栈","队列",它们的区别？](https://jingyan.baidu.com/article/6c67b1d6a09f9a2786bb1e4a.html)

## 队列(Queue)

[Wiki: Queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type))

**（推荐）**[Queue Data Structure](https://www.geeksforgeeks.org/queue-data-structure/)：含队列的定义和代码等

[队列的定义及其基本操作](https://blog.csdn.net/forwardyzk/article/details/53771544)

## 



