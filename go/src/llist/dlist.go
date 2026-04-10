package llist

import (
	"fmt"
)

type Dnode struct {
	Data int
	Next *Dnode
	Prev *Dnode
}

func Dprint(head Dnode) {
	for i := 0; ; i++ {
		if head.Prev == nil {
			fmt.Printf("%d: %d <- NULL\n", i, head.Data)
		} else {
			fmt.Printf(
				"%d: %d <- %d\n",
				i, head.Data, (head.Prev).Data,
			)
		}
		if head.Next == nil {
			break
		}
		head = *head.Next
	}
}

func Dinsert(head *Dnode, index int, data int) *Dnode {
	node := new(Dnode)
	node.Data = data

	if head == nil {
		head = node
		return head
	}

	if index < 0 {
		node.Next = head
		head.Prev = node
		head = node
		return head
	}

	prev, _ := getDnode(head, index)
	next := prev.Next

	node.Next = next
	prev.Next = node
	node.Prev = prev
	if next != nil {
		next.Prev = node
	}
	return head
}

func Ddelete(head *Dnode, index int) *Dnode {
	if head == nil {
		return head
	}

	if index < 1 {
		head = head.Next
		if head != nil {
			head.Prev = nil
		}
		return head
	}

	del, prev := getDnode(head, index)
	if (prev == nil) || (del == nil) {
		return nil
	}
	next := del.Next
	prev.Next = next
	if next != nil {
		next.Prev = prev
	}
	return head
}

func getDnode(head *Dnode, index int) (this *Dnode, prev *Dnode) {
	for i := 0; i < index; i++ {
		if head.Next == nil {
			break
		}
		prev = head
		head = head.Next
	}
	return head, prev
}
