package stack

import (
	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/llist"
)

type Lstack struct {
	top  *llist.Snode
	size int
}

func (ls *Lstack) IsEmpty() bool {
	if ls == nil {
		return true
	}
	return ls.size < 1
}

func (ls *Lstack) Size() int {
	if ls == nil {
		return 0
	}
	return ls.size
}

func (ls *Lstack) Push(data int) {
	node := llist.Snode{}
	node.Data = data
	if ls == nil {
		*ls = Lstack{}
	}
	if ls.top == nil {
		ls.top = &node
	}
	node.Next = ls.top
	ls.top = &node
	ls.size += 1
}

func (ls *Lstack) Peek() (int, bool) {
	if ls.IsEmpty() {
		return 0, false
	}
	return ls.top.Data, true
}

func (ls *Lstack) Pop() (int, bool) {
	if ls.IsEmpty() {
		return 0, false
	}
	data := ls.top.Data
	ls.top = ls.top.Next
	ls.size -= 1
	return data, true
}
