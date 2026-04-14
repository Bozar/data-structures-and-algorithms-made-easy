package stack

import ()

const initSstackLen int = 8

type Sstack struct {
	top *[]int
}

func (ss *Sstack) IsEmpty() bool {
	if (ss == nil) || (ss.top == nil) {
		return true
	}
	return len(*ss.top) < 1
}

func (ss *Sstack) Size() int {
	if (ss == nil) || (ss.top == nil) {
		return 0
	}
	return len(*ss.top)
}

func (ss *Sstack) Push(data int) {
	if ss == nil {
		*ss = Sstack{}
	}
	if ss.top == nil {
		init := make([]int, 0, initSstackLen)
		ss.top = &init
	}
	*ss.top = append(*ss.top, data)
}

func (ss *Sstack) Peek() (int, bool) {
	if ss.IsEmpty() {
		return 0, false
	}
	top := *ss.top
	idx := len(top) - 1
	return top[idx], true
}

func (ss *Sstack) Pop() (int, bool) {
	if ss.IsEmpty() {
		return 0, false
	}
	top := *ss.top
	idx := len(top) - 1
	data := top[idx]
	*ss.top = top[:idx]
	return data, true
}
