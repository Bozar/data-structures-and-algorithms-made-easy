package llist

import (
	"fmt"
)

type Dnode struct {
	Data int
	Next *Dnode
	Prev *Dnode
}

func (dn *Dnode) Print() {
	for i := 0; ; i++ {
		if dn.Prev == nil {
			fmt.Printf("%d: %d <- NULL\n", i, dn.Data)
		} else {
			fmt.Printf(
				"%d: %d <- %d\n",
				i, dn.Data, (dn.Prev).Data,
			)
		}
		if dn.Next == nil {
			break
		}
		dn = dn.Next
	}
}

func (dn *Dnode) Insert(index int, data int) *Dnode {
	node := new(Dnode)
	node.Data = data

	if dn == nil {
		dn = node
		return dn
	}

	if index < 0 {
		node.Next = dn
		dn.Prev = node
		dn = node
		return dn
	}

	prev, _ := getDnode(dn, index)
	next := prev.Next

	node.Next = next
	prev.Next = node
	node.Prev = prev
	if next != nil {
		next.Prev = node
	}
	return dn
}

func (dn *Dnode) Delete(index int) *Dnode {
	if dn == nil {
		return dn
	}

	if index < 1 {
		dn = dn.Next
		if dn != nil {
			dn.Prev = nil
		}
		return dn
	}

	del, prev := getDnode(dn, index)
	if (prev == nil) || (del == nil) {
		return nil
	}
	next := del.Next
	prev.Next = next
	if next != nil {
		next.Prev = prev
	}
	return dn
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
