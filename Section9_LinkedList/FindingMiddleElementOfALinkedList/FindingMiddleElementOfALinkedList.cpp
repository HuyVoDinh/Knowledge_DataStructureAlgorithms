/***
 * p = q = first;
 * while(q)
 * {
 *      q = q->next;
 *      if(q)
 *      {
 *          q = q->next;
 *      }
 *      if(q)
 *      {
 *          // means q has not became null,  then p assign, p is next. So q will move for two times, p will move for one time and the p will move if q has not become null. So this loop will make a p point on the middle node of a linked list. 
 *          p = p->next;
 *      }
 * }
 * 
 * ***/