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
