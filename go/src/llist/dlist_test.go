package llist_test

import (
	"fmt"
	"testing"

	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/internal/debug"
	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/llist"
)

func TestDlist(t *testing.T) {
	if !debug.IsDebugDlist {
		t.SkipNow()
	}

	fmt.Println("Dprint()")
	testDprint(t)

	fmt.Println()
	fmt.Println("Dinsert()")
	testDinsert(t)

	fmt.Println()
	fmt.Println("Ddelete()")
	testDdelete(t)
}

// Use `go test -v ./src/...` to see output.
func testDprint(t *testing.T) {
	n1 := llist.Dnode{}
	n2 := llist.Dnode{}
	n3 := llist.Dnode{}

	n1.Data = 1
	n2.Data = 2
	n3.Data = 3

	n1.Next = &n2
	n2.Next = &n3
	n2.Prev = &n1
	n3.Prev = &n2

	llist.Dprint(n1)
}

func testDinsert(t *testing.T) {
	var head *llist.Dnode

	// Step 1: [2,]
	index := 9
	data := 2
	head = llist.Dinsert(head, index, data)
	fmt.Println("step 1: [2,]")
	llist.Dprint(*head)
	if !verifyDlist(t, head, []int{2}) {
		return
	}

	// Step 2: [2, 3, 4, 5,]
	index = 0
	data = 3
	head = llist.Dinsert(head, index, data)
	index = 9
	data = 5
	head = llist.Dinsert(head, index, data)
	index = 1
	data = 4
	head = llist.Dinsert(head, index, data)
	fmt.Println("step 2: [2, 3, 4, 5,]")
	llist.Dprint(*head)
	if !verifyDlist(t, head, []int{2, 3, 4, 5}) {
		return
	}

	// Step 3: [1, 2, 3, 4, 5,]
	index = -9
	data = 1
	head = llist.Dinsert(head, index, data)
	fmt.Println("step 3: [1, 2, 3, 4, 5,]")
	llist.Dprint(*head)
	if !verifyDlist(t, head, []int{1, 2, 3, 4, 5}) {
		return
	}
}

func testDdelete(t *testing.T) {
	// Step 0: [1, 2, 3, 4, 5, 6,]
	var head *llist.Dnode
	index := 7
	for i := 1; i < index; i++ {
		head = llist.Dinsert(head, 99, i)
	}
	fmt.Printf("\nllist.Ddelete()")
	fmt.Printf("\nstep 0: [1, 2, 3, 4, 5, 6,]\n")
	llist.Dprint(*head)

	// Step 1: [1, 2, 3, 4, 5,]
	index = 99
	head = llist.Ddelete(head, index)
	fmt.Printf("\nstep 1: [1, 2, 3, 4, 5,]\n")
	llist.Dprint(*head)
	if !verifyDlist(t, head, []int{1, 2, 3, 4, 5}) {
		return
	}

	// Step 2: [1, 2, 3, 4,]
	index = 4
	head = llist.Ddelete(head, index)
	fmt.Printf("\nstep 2: [1, 2, 3, 4,]\n")
	llist.Dprint(*head)
	if !verifyDlist(t, head, []int{1, 2, 3, 4}) {
		return
	}

	// Step 3: [1, 2, 4,]
	index = 2
	head = llist.Ddelete(head, index)
	fmt.Printf("\nstep 3: [1, 2, 4,]\n")
	llist.Dprint(*head)
	if !verifyDlist(t, head, []int{1, 2, 4}) {
		return
	}

	// Step 4: [2, 4,]
	index = -1
	head = llist.Ddelete(head, index)
	fmt.Printf("\nstep 4: [2, 4,]\n")
	llist.Dprint(*head)
	if !verifyDlist(t, head, []int{2, 4}) {
		return
	}

	// Step 5: [4,]
	index = 0
	head = llist.Ddelete(head, index)
	fmt.Printf("\nstep 5: [4,]\n")
	llist.Dprint(*head)

	if !verifyDlist(t, head, []int{4}) {
		return
	}

	// Step 6: [,]
	index = 0
	head = llist.Ddelete(head, index)
	fmt.Printf("\nstep 6: [,]\n")
	if head != nil {
		llist.Dprint(*head)
		t.Error("head is not null")
		return
	}

	// Step 7: [4,] -> [,]
	index = 9
	head = llist.Dinsert(head, index, 4)
	head = llist.Ddelete(head, index)
	fmt.Printf("\nstep 7: [,]\n")
	if head != nil {
		llist.Dprint(*head)
		t.Error("head is not null")
		return
	}
}

func verifyDlist(t *testing.T, head *llist.Dnode, sample []int) bool {
	if head == nil {
		t.Error("input head is null")
		return false
	}

	maxIdx := len(sample)
	var prev *llist.Dnode
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
		prev = head.Prev
		if i == 0 {
			if prev != nil {
				t.Error("head.Prev is not null")
				return false
			}
		} else if prev.Data != sample[i-1] {
			t.Errorf(
				"idx: %d, wrong prev data: %d, right: %d",
				i, prev.Data, sample[i-1],
			)
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
