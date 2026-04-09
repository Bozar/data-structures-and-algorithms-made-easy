package llist

import (
	"fmt"
)

type Snode struct {
	Data int
	Next *Snode
}

func Sprint(head Snode) {
	for i := 0; ; i++ {
		fmt.Printf("%d: %d\n", i, head.Data)
		if head.Next == nil {
			break
		}
		head = *head.Next
	}
}

func Sinsert(head *Snode, index int, data int) *Snode {
	node := new(Snode)
	node.Data = data

	if head == nil {
		head = node
		return head
	}

	if index < 0 {
		node.Next = head
		head = node
		return head
	}

	prev, _ := getSnode(head, index)
	node.Next = prev.Next
	prev.Next = node
	return head
}

func Sdelete(head *Snode, index int) *Snode {
	if head == nil {
		return head
	}

	if index < 1 {
		head = head.Next
		return head
	}

	del, prev := getSnode(head, index)
	if (prev == nil) || (del == nil) {
		return nil
	}
	prev.Next = del.Next
	return head
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
