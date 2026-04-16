package queue

import (
	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/llist"
)

type Lqueue struct {
	front *llist.Snode
	rear  *llist.Snode
	size  int
}

func (lq *Lqueue) IsEmpty() bool {
	if lq == nil {
		return true
	}
	return lq.size < 1
}

func (lq *Lqueue) Size() int {
	if lq == nil {
		return 0
	}
	return lq.size
}

func (lq *Lqueue) Peek() (int, bool) {
	if (lq == nil) || (lq.front == nil) {
		return 0, false
	}
	return lq.front.Data, true
}

func (lq *Lqueue) Enqueue(data int) {
	node := llist.Snode{}
	node.Data = data
	if lq == nil {
		*lq = Lqueue{}
	}
	if lq.front == nil {
		lq.front = &node
	}
	if lq.rear == nil {
		lq.rear = lq.front
	} else {
		lq.rear.Next = &node
		lq.rear = &node
	}
	lq.size += 1
}

func (lq *Lqueue) Dequeue() (int, bool) {
	if (lq == nil) || (lq.front == nil) || (lq.rear == nil) {
		return 0, false
	}
	data := lq.front.Data
	lq.front = lq.front.Next
	if lq.front == nil {
		lq.rear = nil
	}
	lq.size -= 1
	return data, true
}
