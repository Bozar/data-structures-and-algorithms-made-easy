package llist

import (
	"fmt"
)

type Cnode struct {
	Data int
	Next *Cnode
}

func (cn *Cnode) Print() {
	start := cn
	for i := 0; ; i++ {
		fmt.Printf("%d: %d\n", i, cn.Data)
		if cn.Next == nil {
			fmt.Printf("Cnode.Next is null: %d\n", i)
			return
		} else if cn.Next == start {
			break
		}
		cn = cn.Next
	}
}

func (cn *Cnode) Insert(index int, data int) *Cnode {
	node := new(Cnode)
	node.Data = data

	if cn == nil {
		cn = node
		cn.Next = cn
		return cn
	}

	prev := getLastCnode(cn)
	if index < 0 {
		node.Next = cn
		prev.Next = node
		cn = node
		return cn
	}

	prev, _ = getCnode(cn, index)
	node.Next = prev.Next
	prev.Next = node
	return cn
}

func (cn *Cnode) Delete(index int) *Cnode {
	if cn == nil {
		return cn
	}

	var prev *Cnode
	if index < 1 {
		if cn.Next == cn {
			return nil
		}
		prev = getLastCnode(cn)
		prev.Next = cn.Next
		cn = cn.Next
		return cn
	}

	del, prev := getCnode(cn, index)
	if (prev == nil) || (del == nil) {
		return nil
	}
	prev.Next = del.Next
	return cn
}

func getLastCnode(head *Cnode) *Cnode {
	start := head
	for head.Next != start {
		head = head.Next
	}
	return head
}

func getCnode(head *Cnode, index int) (this *Cnode, prev *Cnode) {
	start := head
	for i := 0; i < index; i++ {
		if head.Next == start {
			break
		}
		prev = head
		head = head.Next
	}
	return head, prev
}
