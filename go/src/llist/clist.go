package llist

import (
	"fmt"
)

type Cnode struct {
	Data int
	Next *Cnode
}

func Cprint(head Cnode) {
	start := head
	for i := 0; ; i++ {
		fmt.Printf("%d: %d\n", i, head.Data)
		if head.Next == nil {
			fmt.Printf("Cnode.Next is null: %d\n", i)
			return
		} else if *head.Next == start {
			break
		}
		head = *head.Next
	}
}

func Cinsert(head *Cnode, index int, data int) *Cnode {
	node := new(Cnode)
	node.Data = data

	if head == nil {
		head = node
		head.Next = head
		return head
	}

	prev := getLastCnode(head)
	if index < 0 {
		node.Next = head
		prev.Next = node
		head = node
		return head
	}

	prev, _ = getCnode(head, index)
	node.Next = prev.Next
	prev.Next = node
	return head
}

func Cdelete(head *Cnode, index int) *Cnode {
	if head == nil {
		return head
	}

	var prev *Cnode
	if index < 1 {
		if head.Next == head {
			return nil
		}
		prev = getLastCnode(head)
		prev.Next = head.Next
		head = head.Next
		return head
	}

	del, prev := getCnode(head, index)
	if (prev == nil) || (del == nil) {
		return nil
	}
	prev.Next = del.Next
	return head
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
