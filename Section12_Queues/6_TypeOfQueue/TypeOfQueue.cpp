/***
 * [DEQueue]
 * DEQueue is not dequeue. Double ended queue. It doesn't strictly follow FIFO. It all depends on you. If you want can use it as a FIFO. It can be implemented using array, 
 * it can be implemented using array  or it can be implemented using linked list. 
 * Similarly in the linked list we need two pointers front and rear. Rear is used for insertion. front is used for deletion. But in DEQueue can use both the pointers for both operations,
 * for both operations insertion as well as deletion. 
 * So with rear pointer can insert as well as delete. And with front pointer can insert as well as delete. 
 * 
 * [Priority Queues 1]
 * This method is useful mostly in operating system. Some operating system allows priority-based scheduling. Like in Java, JVM supports multi-threading.
 * It's allow priorities upon threads. So can set the priorities for a thread. 
 * Element:     A   B   C   D   E   F   G   H   I   J
 * Priority:    1   1   2   3   2   1   2   3   2   2   1
 * 
 * Q1:  A   B   F
 * Q2:  C   E   G   I   J
 * Q3:  D   H
 * When first queue is empty, then go for second priority. 
 * Deletion should be done always from highest priority queue. And if it is empty, go to the next priority. 
 * 
 * [Priority Queues 2]
 * Where the element itself is a priority. It means there are unlimited priorities. Priority can be anything and even the elements can have same priority also.
 * Can have duplicate.
 * If you want the elements in the decreasing order of the priority means first, highest priority then next highest priority. 
 * Then you have to arrange the elements in increasing order. 
 * This is not FIFO. Just taken an array. Have store those elements in an array. 
 * When want to implement a priority queue using a array for these set of number, that is unlimited priorities. 
 * Two solutions: 
 * + Inserting the elements, insert them in the same order as they are coming in. While deleting find out the maximum priority element, search for that element and then delete that element. 
 * + Insert in increasing order of the priority. When the elements are coming in, dont insert them as it is. Try to arrange them in increasing order of the priority so that the last element is of highest priority. 
 * When deleting, can simply delete the last element. 
 * -> Difference in these two methods is while inserting simply inserting it,  or searching for an element and deleting it. Method second, while inserting are trying to properly arrange it, while deleting are simply deleting an element. 
 * 
 * Elements -> 6, 8, 3, 10, 15, 2, 9, 17, 5, 8
 * 
 * 
 * [Queue using 2 Stacks]
 * Queue itself is a data structure. Can implement it using array or else using linked list. But if have two stacks, can make them work just like a queue. 
 * Have two stack. That has to be actually inserted and deleted from a queue, means enqueue or dequeue. 
 * 
 * Element: 6,3,9,5,4,2,8,12,10... 
 * S1: 6
 * S2: 
 * 
 * S1: 6 3
 * S2: 
 * 
 * S1: 6 3 9
 * S2: 
 * 
 * S1: 6 3 9 5
 * S2: 
 * -> delete: But these elements are in stack. If delete any element, means pop out an element, will get 5. To get 6, transfer all these elements into stack 2. 
 * S1: 6 3 9
 * S2: 5
 * 
 * S1: 6 3 
 * S2: 5 9
 * 
 * S1: 6 
 * S2: 5 9 3
 * 
 * S1:  
 * S2: 5 9 3 6
 * => delete
 * S1: 
 * S2: 5 9 3
 * 
 * -> enqueue
 * S1: 4
 * S2: 5 9 3
 * 
 * S1: 4 2
 * S2: 5 9 3
 * -> dequeue
 * 
 * S1: 4 2
 * S2: 5 9 
 * 
 * S1: 4 2
 * S2: 5 
 * ***/