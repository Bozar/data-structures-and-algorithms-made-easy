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
