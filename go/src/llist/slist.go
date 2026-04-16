package llist

import (
	"fmt"
)

type Snode struct {
	Data int
	Next *Snode
}

func (sn *Snode) Print() {
	for i := 0; ; i++ {
		fmt.Printf("%d: %d\n", i, sn.Data)
		if sn.Next == nil {
			break
		}
		sn = sn.Next
	}
}

func (sn *Snode) Insert(index int, data int) *Snode {
	node := new(Snode)
	node.Data = data

	if sn == nil {
		sn = node
		return sn
	} else if index < 0 {
		node.Next = sn
		sn = node
		return sn
	}

	prev, _ := getSnode(sn, index)
	node.Next = prev.Next
	prev.Next = node
	return sn
}

func (sn *Snode) Delete(index int) *Snode {
	if sn == nil {
		return sn
	}

	if index < 1 {
		sn = sn.Next
		return sn
	}

	del, prev := getSnode(sn, index)
	if (prev == nil) || (del == nil) {
		return nil
	}
	prev.Next = del.Next
	return sn
}

func getSnode(head *Snode, index int) (this *Snode, prev *Snode) {
	for i := 0; i < index; i++ {
		if head.Next == nil {
			break
		}
		prev = head
		head = head.Next
	}
	return head, prev
}
