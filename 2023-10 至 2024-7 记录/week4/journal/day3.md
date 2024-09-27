# Time log

- 11:30:16 `Makefiles & Command Line Arguments & File I/O & Binary Files & Endianness`学完
- 15:59:42 `hw7 deque`部分完成
- 17:29:52 `hw7 rpc`主体框架完成，命令分解还未完成，先去吃个饭
- 20:15:19 `hw7`全部完成
- 23:36:48 准备上床睡觉

# Summary

## `Deque`编写过程中的错误总结

1. `Deque_Push_Front`时需要检查`Front`是否为`NULL`(尚未插入元素)，并且元素个数+1，如果这是唯一一个元素，`dq->back`也需要修改，最后让`dq->front`指向新元素

   ```C++
   new_node->prev = NULL;
   new_node->next = dq->front;
   if(dq->front != NULL) {
           dq->front->prev = new_node;
   } else {
           dq->back = new_node;
   }
   dq->front = new_node;
   ```

2. `Pop_Front`时也需要检查，此外，还需要警惕pop到0时，除了需要充置front，还要重置dq->back

   ```C++
       DequeNode *node = dq->front;
       dq->front = dq->front->next;
       if(dq->front != NULL)
           dq->front->prev = NULL;
        if(Deque_Size(dq) == 0) {
		    dq->back = NULL;
	    }
       dq->num_elements -= 1;
   ```

3. `Push_Back`和`Pop_Back`同理
4. 释放`iterator`时只需要释放`iterator`本身，不要释放`deque`（留到 deque 自己释放）
   ```C++
   void DQIterator_Free(DQIterator *iter)
    {
        free(iter);
    }
   ```
5. `Next`时先递增，再判断

   ```C++
   bool DQIterator_Next(DQIterator *iter)
   {
       iter->node = iter->node->next;
       return DQIterator_IsValid(iter);
   }

   ```

6. `Remove`要点很多

   1. 需要判断是否是唯一一个节点，如果是的话将其置为 NULL，让 Front 和 Back 都为 NULL，prev 和 next 都为 NULL, num_elements 递减，并且返回`false`**(一定要记得`free`!)**

   ```C++
   if(node->next == NULL && node->prev == NULL) {
   	iter->node = NULL;
   	iter->deque->front = NULL;
   	iter->deque->back = NULL;
   	node->prev = NULL;
   	node->next = NULL;
   	iter->deque->num_elements -= 1;
    **free(node);**
   	return false;
   }
   ```

   2. 否则再来分别判断`prev`和`next`是否有节点

   ```C++
   else {
   	if(node->next != NULL) {
   		node->next->prev = node->prev;
   	}
   	else {
   		iter->deque->back = node->prev;
   		node->prev->next = NULL;
   	}

   	if(node->prev != NULL) {
   		node->prev->next = node->next;
   	}
   	else {
   		iter->deque->front = node->next;
   		iter->deque->front->prev = NULL;
   	}
   	iter->node = node->next;
   }
   ```

   3. 如果释放的是末尾节点，就将`iter`指向它的前驱，并且将 num_elements - 1，返回`true`

   ```C++
   	if(iter->node == NULL) {
   	iter->node = node->prev;
   }
    iter->deque->num_elements -= 1;
   ```

7. 先整理好思路，再开始写代码
