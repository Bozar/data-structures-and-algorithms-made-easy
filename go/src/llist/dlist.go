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
