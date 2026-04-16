package llist_test

import (
	"fmt"
	"testing"

	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/llist"
)

func TestSlist(t *testing.T) {
	testSprint(t)
	testSinsert(t)
	testSdelete(t)
}

// Use `go test -v ./src/...` to see output.
func testSprint(t *testing.T) {
	n1 := llist.Snode{}
	n2 := llist.Snode{}
	n3 := llist.Snode{}

	n1.Data = 1
	n2.Data = 2
	n3.Data = 3

	n1.Next = &n2
	n2.Next = &n3

	fmt.Println("llist.Sprint()")
	llist.Sprint(n1)
}

func testSinsert(t *testing.T) {
	var head *llist.Snode

	// Step 1: [2,]
	index := 9
	data := 2
	head = llist.Sinsert(head, index, data)
	if head == nil {
		t.Error("head is null")
		return
	} else if head.Data != data {
		t.Errorf("wrong: %d, right: %d", head.Data, data)
		return
	}

	// Step 2: [2, 3, 4, 5,]
	index = 0
	data = 3
	head = llist.Sinsert(head, index, data)
	index = 9
	data = 5
	head = llist.Sinsert(head, index, data)
	index = 1
	data = 4
	head = llist.Sinsert(head, index, data)
	fmt.Printf("\nllist.Sinsert()")
	fmt.Printf("\nstep 2: [2, 3, 4, 5,]\n")
	llist.Sprint(*head)

	// Step 3: [1, 2, 3, 4, 5,]
	index = -9
	data = 1
	head = llist.Sinsert(head, index, data)
	fmt.Printf("\nstep 3: [1, 2, 3, 4, 5,]\n")
	llist.Sprint(*head)

	for i := 0; i < 5; i++ {
		if head.Data != i+1 {
			t.Errorf("%d, wrong: %d, right: %d", i, head.Data, i+1)
			return
		} else if (i < 4) && (head.Next == nil) {
			t.Errorf("%d, head.Next is null", i)
			return
		}
		head = head.Next
	}
}

func testSdelete(t *testing.T) {
	// Step 0: [1, 2, 3, 4, 5, 6,]
	var head *llist.Snode
	index := 7
	for i := 1; i < index; i++ {
		head = llist.Sinsert(head, 99, i)
	}
	fmt.Printf("\nllist.Sdelete()")
	fmt.Printf("\nstep 0: [1, 2, 3, 4, 5, 6,]\n")
	llist.Sprint(*head)

	// Step 1: [1, 2, 3, 4, 5,]
	index = 99
	head = llist.Sdelete(head, index)
	fmt.Printf("\nstep 1: [1, 2, 3, 4, 5,]\n")
	llist.Sprint(*head)
	if !verifySlist(t, head, []int{1, 2, 3, 4, 5}) {
		return
	}

	// Step 2: [1, 2, 3, 4,]
	index = 4
	head = llist.Sdelete(head, index)
	fmt.Printf("\nstep 2: [1, 2, 3, 4,]\n")
	llist.Sprint(*head)
	if !verifySlist(t, head, []int{1, 2, 3, 4}) {
		return
	}

	// Step 3: [1, 2, 4,]
	index = 2
	head = llist.Sdelete(head, index)
	fmt.Printf("\nstep 3: [1, 2, 4,]\n")
	llist.Sprint(*head)
	if !verifySlist(t, head, []int{1, 2, 4}) {
		return
	}

	// Step 4: [2, 4,]
	index = -1
	head = llist.Sdelete(head, index)
	fmt.Printf("\nstep 4: [2, 4,]\n")
	llist.Sprint(*head)
	if !verifySlist(t, head, []int{2, 4}) {
		return
	}

	// Step 5: [4,]
	index = 0
	head = llist.Sdelete(head, index)
	fmt.Printf("\nstep 5: [4,]\n")
	llist.Sprint(*head)
	if !verifySlist(t, head, []int{4}) {
		return
	}

	// Step 6: [,]
	index = 0
	head = llist.Sdelete(head, index)
	fmt.Printf("\nstep 6: [,]\n")
	if head != nil {
		llist.Sprint(*head)
		t.Error("head is not null")
		return
	}

	// Step 7: [4,] -> [,]
	index = 9
	head = llist.Sinsert(head, index, 4)
	head = llist.Sdelete(head, index)
	fmt.Printf("\nstep 7: [,]\n")
	if head != nil {
		llist.Sprint(*head)
		t.Error("head is not null")
		return
	}
}

func verifySlist(t *testing.T, head *llist.Snode, sample []int) bool {
	if head == nil {
		t.Error("input head is null")
		return false
	}

	maxIdx := len(sample)
	for i := 0; i < maxIdx; i++ {
		if head.Data != sample[i] {
			t.Errorf(
				"idx: %d, wrong data: %d, right: %d",
				i, head.Data, sample[i],
			)
			return false
		} else if (i < maxIdx-1) && (head.Next == nil) {
			t.Errorf("wrong size: %d", i)
			return false
		}
		head = head.Next
	}

	if head != nil {
		t.Error("wrong size")
		return false
	}
	return true
}
