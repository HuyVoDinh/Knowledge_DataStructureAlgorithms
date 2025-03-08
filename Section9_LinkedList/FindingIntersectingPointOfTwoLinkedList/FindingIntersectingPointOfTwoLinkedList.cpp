/***
 * At the time if you're reaching on the same node, But from this side, we cannot at the same time. 
 * But from that side, if you come backward, you can reach. 
 * 
 * Lst us go to the end of the first linked list. Then let us go to the end of the second linked list. 
 * Then com backward. And we get point, same addresses. Then next nodes' addresses will be different. 
 * So once you get a different addresses, you can say that, the previous one was intersection point. 
 * So the procedure is we have to find the intersecting node by traversing from backward. 
 * 
 * How you can traverse from backward?
 * We cannot do that because it's a singly linked list. We can move only in forward direction.
 * It is possible using stack. So when you cannot traverse backward in a singly linked list, stack will help you to get back the previous node addresses. 
 * <FindingIntersectingPointOfTwoLinkedList.png> 
 * 
 * p = first;
 * while(p!=NULL) push(&stk1,p);
 * p = second;
 * while(p!=NULL) push(&stk2,p);
 * //This loop will pop out the addresses from both the stack
 * // Pop out from stack one, pop out from stack two, and any one of the value, I can take it in pointer P. So pointer P will be having the last node deleted from the stack. 
 * // So this will be checking and it will stop if the addresses are different. 
 * // So the last address that is popped out will be in variable P. 
 * // So P is an intersecting point of two linked list. 
 * while(stackTop(stk1) == stackTop(stk2))
 * {
 *      p = pop(&stk1);
 *      pop(&stk2);
 * }
 * ***/