#include <iostream>
#include <sstream>
#include <string>

#include "Node.h"
#include "List.h"
#include "CLinkedList.h"
#include "CLinkedList.cpp"
#include "List.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"


using namespace std;


/* -------------------------------------------------------------------------- */
/*                                 PLEASE READ                                */
/* -------------------------------------------------------------------------- */
/*
    Hello 110 Student :). This main.cpp provides very, very basic testing that should help prevent some errors
    in your code. However, it is not a complete test suite. You should write your own tests to ensure that your
    code is working as expected

    Please do not be surprised if this main works but your FF upload fails as the FF main is different from this one.
    This Assignment has many edge cases, please test as much as possible.
*/



void t1(){
    cout<<"Testing CLinkedList"<<endl;
    CLinkedList<int> list;
    cout<<"Testing basics"<<endl;
    list.append(1);
    list.append(2);
    list.prepend(3);
    list.insert(4, 3);
    list.print();// Output should be "3 -> 1 -> 2 -> 4\n"
    list.remove(0);//remember remove works based of index
    list.remove(0);
    list.remove(100);//test for invalid
    list.remove(1);
    list.removeElements(2);
    list.print();// Output should be "Empty\n
    list.append(1);
    list.append(1);
    list.print();// Output should be "1 -> 1\n"
    list.removeElements(1);
    list.print();// Output should be "Empty\n
}

void t2(){
    cout<<"Testing CLinkedList"<<endl;
    CLinkedList<int> list;
    cout<<"Testing rotations"<<endl;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.RRotate(2);
    list.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
    list.LRotate(7);
    list.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    cout<<"Testing Assignment operator and rotation"<<endl;
    CLinkedList<int> list2;
    list2= list;
    list2.print();// Output should be "1 -> 2 -> 3 -> 4 -> 5\n"
    list2.RRotate(2);
    list2.print();// Output should be "4 -> 5 -> 1 -> 2 -> 3\n"
}

void t3(){
    cout<<"Testing Stack"<<endl;
    Stack<int> stack;
    cout<<"Testing basics"<<endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout<<stack.pop()<<endl;// Output should be "4\n"
    cout<<stack.peek()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "2\n"
    cout<<stack.pop()<<endl;// Output should be "1\n"
    cout<<stack.pop()<<endl;// Output should be "0\n" since we are returning the default val
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout<<"Testing copy constructor"<<endl;
    Stack<int> stack2(stack);
    cout<<stack2.pop()<<endl;// Output should be "3\n"
    cout<<stack2.pop()<<endl;// Output should be "2\n"
    cout<<stack2.pop()<<endl;// Output should be "1\n"
    cout<<stack2.pop()<<endl;// Output should be "0\n" since we are returning the default val
    cout<<stack.pop()<<endl;// Output should be "3\n"
    cout<<stack.pop()<<endl;// Output should be "2\n"
    cout<<stack.pop()<<endl;// Output should be "1\n"
    cout<<stack.pop()<<endl;// Output should be "0\n" since we are returning the default val
    //loading up items to test destructor
    stack.push(1);
    stack.push(2);
    stack.push(3);

}

void t4(){
    cout<<"Testing Queue"<<endl;
    Queue<int> queue;
    cout<<"Testing basics"<<endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    cout<<queue.dequeue()<<endl;// Output should be "1\n"
    cout<<queue.peek()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "3\n"
    cout<<queue.dequeue()<<endl;// Output should be "4\n"
    cout<<queue.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout<<"Testing copy constructor"<<endl;
    Queue<int> queue2(queue);
    cout<<queue2.dequeue()<<endl;// Output should be "1\n"
    cout<<queue2.dequeue()<<endl;// Output should be "2\n"
    cout<<queue2.dequeue()<<endl;// Output should be "3\n"
    cout<<queue2.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    cout<<queue.dequeue()<<endl;// Output should be "1\n"
    cout<<queue.dequeue()<<endl;// Output should be "2\n"
    cout<<queue.dequeue()<<endl;// Output should be "3\n"
    cout<<queue.dequeue()<<endl;// Output should be "0\n" since we are returning the default val
    //loading up items to test destructor
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

}

int main(){
    std::cout << "\nStarting my own tests:\n";
    CLinkedList<int> circularList;

    circularList.append(4);
    circularList.append(5);
    circularList.append(6);
    circularList.append(9);
    circularList.append(10);
    circularList.append(12);
    circularList.print();

    circularList.prepend(1);
    circularList.prepend(17);
    circularList.prepend(33);
    circularList.print();

    std::cout << "Removing index 0\n";
    circularList.remove(0);
    circularList.print();
    std::cout << "Removing index 7\n";
    circularList.remove(7);
    circularList.print();
    std::cout << "Removing index 4\n";
    circularList.remove(4);
    circularList.print();
    std::cout << "Removing index -1\n";
    circularList.remove(-1);
    circularList.print();
    std::cout << "Removing index 20\n";
    circularList.remove(20);
    circularList.print();

    CLinkedList<int> circularList1;
    std::cout << "Removing last element\n";
    circularList1.append(1);
    circularList1.print();
    circularList1.remove(0);
    circularList1.print();

    CLinkedList<int> circList2;
    circList2 = circularList;
    std::cout << "Assignment operator:\n";
    circList2.print();

    std::cout << "Reversing\n";
    circularList.reverse();
    circularList.print();

    std::cout << "\nClear array, check for mem leaks\n";
    circularList.clear();
    circularList.print();
    std::cout << "Repopulating\n";
    circularList = circList2;
    circularList.print();

    std::cout << "\nget() and operator[]()\n";
    std::cout << "Index 1: val: 1\n"
            << circularList.get(1) << ' ' << circularList[1] << '\n';
    std::cout << "Index 0: val: 17\n"
              << circularList.get(0) << ' ' << circularList[0] << '\n';
    std::cout << "Index 5: val: 10\n"
              << circularList.get(5) << ' ' << circularList[5] << '\n';
    std::cout << "Index 10: val: Default\n"
              << circularList.get(10) << ' ' << circularList[10] << '\n';
    std::cout << "Index -1: val: Default\n"
              << circularList.get(-1) << ' ' << circularList[-1] << '\n';
    circList2.clear();
    std::cout << "Index 1 on empty list: val: Default\n"
              << circList2.get(1) << ' ' << circList2[1] << '\n';
    circList2.append(2);
    std::cout << "Index 0 on single element list: val: 2\n"
              << circList2.get(0) << ' ' << circList2[0] << '\n';

    CLinkedList<int> circList3;

    circList3.append(5);
    for (int i = 0; i < 10; i++) {
        circList3.append(i);
        circList3.append(5);
    }

    std::cout << "removeElements Test (5):\n";
    circList3.print();
    circList3.removeElements(5);
    circList3.print();

    CLinkedList<int> circList3Copy;
    circList3Copy = circList3;


    std::cout << "\nCircList3: ";
    circList3.print();
    std::cout << "Slicing circList3 from 0 to 0\n";
    circList3.slice(0,0);
    circList3.print();
    circList3 = circList3Copy;
    std::cout << "Slicing circList3 from 2 to 7\n";
    circList3.slice(2,7);
    circList3.print();
    circList3 = circList3Copy;
    std::cout << "Slicing circList3 from 8 to 8\n";
    circList3.slice(8,8);
    circList3.print();
    circList3 = circList3Copy;
    std::cout << "Slicing circList3 from 0 to 8\n";
    circList3.slice(0,8);
    circList3.print();
    circList3 = circList3Copy;
    std::cout << "Slicing circList3 from 7 to 8\n";
    circList3.slice(7,8);
    circList3.print();
    circList3 = circList3Copy;
    std::cout << "Slicing circList3 from 0 to 2\n";
    circList3.slice(0,2);
    circList3.print();
    circList3 = circList3Copy;

    std::cout << "LRotate 4 times\n";
    circList3.LRotate(4);
    circList3.print();
    circList3 = circList3Copy;
    std::cout << "RRotate 4 times\n";
    circList3.RRotate(4);
    circList3.print();
    circList3 = circList3Copy;
    std::cout << "LRotate 0 times\n";
    circList3.LRotate(0);
    circList3.print();
    circList3 = circList3Copy;
    std::cout << "RRotate 105 times\n";
    circList3.RRotate(105);
    circList3.print();
    circList3 = circList3Copy;
    std::cout << "LRotate 105 times\n";
    circList3.LRotate(105);
    circList3.print();
    circList3 = circList3Copy;


    circList3.print();
    std::cout << (circList3 == circList3Copy) << '\n';
    circList3.remove(0);
    circList3.prepend(1);
    std::cout << (circList3 == circList3Copy) << '\n';

    CLinkedList<int> circList4;

    circList4.append(1);
    circList4.append(1);
    circList4.append(3);
    circList4.append(9);
    circList4.append(1);
    circList4.append(3);
    circList4.append(5);
    circList4.append(1);
    circList4.append(1);
    circList4.append(5);
    circList4.append(1);
    circList4.append(1);
    circList4.append(6);
    circList4.append(9);
    circList4.append(1);

    std::cout << "Remove duplicates from:\n";
    circList4.print();
    circList4.removeDuplicates();
    circList4.print();

    CLinkedList<int> circList4Copy;
    circList4Copy = circList4;

    std::cout << "CircList4 consuming circList3:\n";
    circList4.print();
    circList3.print();
    circList4.consume(circList3);
    circList4.print();
    circList3.print();

    circList3 = circList3Copy;

    std::cout << "Subtraction (circList4 - circList3:\n"
            << "circList4: ";
    circList4.print();
    std::cout << "circList3: ";
    circList3.print();
    CLinkedList<int>* minus = circList4 - circList3;
    minus->print();

    circList4 = *minus;
    std::cout << "Addition:\n";
    std::cout << "circList4: ";
    circList4.print();
    std::cout << "circList3: ";
    circList3.print();
    circList4 += circList3;
    circList4.print();

    std::cout << "Testing swap funct.\n";
    std::cout << "Swapping index 4 with index 6 in circList4\n";
    circList4.swap(4,6);
    circList4.print();
    std::cout << "Swapping index 0 with index 0 in circList4\n";
    circList4.swap(0,0);
    circList4.print();
    std::cout << "Swapping index 0 with index 1 in circList4\n";
    circList4.swap(0,1);
    circList4.print();
    std::cout << "Swapping index 1 with index 0 in circList4\n";
    circList4.swap(1,0);
    circList4.print();
    std::cout << "Swapping index 0 with last index in circList4\n";
    circList4.swap(0, circList4.length() - 1);
    circList4.print();
    std::cout << "Swapping last index with index 0 in circList4\n";
    circList4.swap(circList4.length() - 1, 0);
    circList4.print();

    circList4Copy = circList4;

    // Test the filter function on circlist4, printing after every test
    std::cout << "Filtering for < 5\n";
    circList4.filter("<", 5);
    circList4.print();
    circList4 = circList4Copy;
    std::cout << "Filtering for > 5\n";
    circList4.filter(">", 5);
    circList4.print();
    circList4 = circList4Copy;
    std::cout << "Filtering for == 5\n";
    circList4.filter("==", 5);
    circList4.print();
    circList4 = circList4Copy;
    std::cout << "Filtering for <= 5\n";
    circList4.filter("<=", 5);
    circList4.print();
    circList4 = circList4Copy;
    std::cout << "Filtering for >= 5\n";
    circList4.filter(">=", 5);
    circList4.print();
    circList4 = circList4Copy;
    std::cout << "Filtering for != 5\n";
    circList4.filter("!=", 5);
    circList4.print();
    circList4 = circList4Copy;
    std::cout << "Filtering for < 1\n";
    circList4.filter("<", 1);
    circList4.print();

    // Test insert function, printing after every test
    std::cout << "Inserting 12 at index 0\n";
    circList4.insert(12, 0);
    circList4.print();
    std::cout << "Inserting 13 at index 1\n";
    circList4.insert(13, 1);
    circList4.print();
    std::cout << "Inserting 14 at index 2\n";
    circList4.insert(14, 2);
    circList4.print();
    std::cout << "Inserting 15 at last index\n";
    circList4.insert(15, circList4.length()-1);
    circList4.print();
    std::cout << "Inserting 16 at end\n";
    circList4.insert(16, circList4.length());
    circList4.print();


    delete minus;


    Stack<int> stack1;
    // push some data to the stack
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);

    // print the stack
    std::cout << "Popping the stack:\n";
    while (!stack1.isEmpty()) {
        cout << stack1.pop() << endl;
    }
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);

    std::cout << "Peeking the stack:\n" << stack1.peek() << std::endl;

    // Test copy constructor
    Stack<int> stack2(stack1);
    std::cout << "Testing copy constructor:\n";
    while (!stack2.isEmpty()) {
        cout << stack2.pop() << endl;
    }


    Queue<int> queue1;
    // push some data to the stack
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);
    queue1.enqueue(4);
    queue1.enqueue(5);
    queue1.enqueue(6);

    // print the stack
    std::cout << "Popping the Queue:\n";
    while (!queue1.isEmpty()) {
        cout << queue1.dequeue() << endl;
    }
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);
    queue1.enqueue(4);
    queue1.enqueue(5);
    queue1.enqueue(6);

    std::cout << "Peeking the Queue:\n" << queue1.peek() << std::endl;

    // Test copy constructor
    Queue<int> queue2(queue1);
    std::cout << "Testing Queue copy constructor:\n";
    while (!queue2.isEmpty()) {
        cout << queue2.dequeue() << endl;
    }

    Queue<int>* copy = queue1.clone();
    std::cout << "Testing Queue clone function:\n";
    while (!copy->isEmpty()) {
        cout << copy->dequeue() << endl;
    }
    delete copy;
    copy = queue1.clone();

    delete copy;

    t1();
    t2();
    t3();
    t4();

    std::cout << "My tests again\n";

    CLinkedList<int> circList5;
    circList5.insert(2,0);
    circList5.print();
    circList5.insert(1,0);
    circList5.print();
    circList5.insert(3,2);
    circList5.print();
    circList5.insert(0,0);
    circList5.print();
    circList5.insert(2,1);
    circList5.print();
    circList5.insert(2,5);
    circList5.print();

    CLinkedList<int> circList6;
    CLinkedList<int> circList7;

    // append three 2's to circlist5 and circlist6
    for (int i = 0; i < 3; i++) {
        circList6.append(2);
        circList7.append(2);
    }
    circList6.print();
    circList7.print();
    std::cout << (circList6 == circList7) << '\n';

    CLinkedList<int> circList8;
    circList8.append(1);
    circList8.append(2);
    std::cout << "reversing two element list:\n";
    circList8.print();
    circList8.reverse();
    circList8.print();

    CLinkedList<int> circList9;
    circList9.append(1);
    circList9.append(2);
    circList9.append(3);
    circList9.append(4);
    std::cout << "reversing four element list:\n";
    circList9.print();
    circList9.reverse();
    circList9.print();

    // Reverse one element list
    CLinkedList<int> circList10;
    circList10.append(1);
    std::cout << "reversing one element list:\n";
    circList10.print();
    circList10.reverse();
    circList10.print();

    // Reverse empty list
    CLinkedList<int> circList11;
    std::cout << "reversing empty list:\n";
    circList11.print();
    circList11.reverse();
    circList11.print();


    return 0;
}