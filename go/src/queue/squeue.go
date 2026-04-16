package queue

import ()

const initSqueueLen int = 8

type Squeue struct {
	front *[]int
}

func (sq *Squeue) IsEmpty() bool {
	if (sq == nil) || (sq.front == nil) {
		return true
	}
	return len(*sq.front) > 0
}

func (sq *Squeue) Size() int {
	if (sq == nil) || (sq.front == nil) {
		return 0
	}
	return len(*sq.front)
}

func (sq *Squeue) Peek() (int, bool) {
	if (sq == nil) || (sq.front == nil) || (len(*sq.front) == 0) {
		return 0, false
	}
	return (*sq.front)[0], true
}

func (sq *Squeue) Enqueue(data int) {
	if sq == nil {
		*sq = Squeue{}
	}
	if sq.front == nil {
		init := make([]int, 0, initSqueueLen)
		sq.front = &init
	}
	*sq.front = append(*sq.front, data)
}

func (sq *Squeue) Dequeue() (int, bool) {
	if (sq == nil) || (sq.front == nil) || (len(*sq.front) == 0) {
		return 0, false
	}
	data := (*sq.front)[0]
	*sq.front = (*sq.front)[1:]
	return data, true
}
