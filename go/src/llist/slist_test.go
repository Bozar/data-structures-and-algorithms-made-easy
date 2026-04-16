package llist_test

import (
	"fmt"
	"testing"

	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/llist"
)

func TestSlist(t *testing.T) {
	fmt.Println("testSprint()")
	testSprint(t)

	fmt.Println("testSinsert()")
	testSinsert(t)

	fmt.Println("testSdelete()")
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

	n1.Print()
}

func testSinsert(t *testing.T) {
	var head *llist.Snode

	// Step 1: [2,]
	index := 9
	data := 2
	head = head.Insert(index, data)
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
	head = head.Insert(index, data)
	index = 9
	data = 5
	head = head.Insert(index, data)
	index = 1
	data = 4
	head = head.Insert(index, data)
	fmt.Printf("\nstep 2: [2, 3, 4, 5,]\n")
	head.Print()

	// Step 3: [1, 2, 3, 4, 5,]
	index = -9
	data = 1
	head = head.Insert(index, data)
	fmt.Printf("\nstep 3: [1, 2, 3, 4, 5,]\n")
	head.Print()

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
		head = head.Insert(99, i)
	}
	fmt.Printf("\nstep 0: [1, 2, 3, 4, 5, 6,]\n")
	head.Print()

	// Step 1: [1, 2, 3, 4, 5,]
	index = 99
	head = head.Delete(index)
	fmt.Printf("\nstep 1: [1, 2, 3, 4, 5,]\n")
	head.Print()
	if !verifySlist(t, head, []int{1, 2, 3, 4, 5}) {
		return
	}

	// Step 2: [1, 2, 3, 4,]
	index = 4
	head = head.Delete(index)
	fmt.Printf("\nstep 2: [1, 2, 3, 4,]\n")
	head.Print()
	if !verifySlist(t, head, []int{1, 2, 3, 4}) {
		return
	}

	// Step 3: [1, 2, 4,]
	index = 2
	head = head.Delete(index)
	fmt.Printf("\nstep 3: [1, 2, 4,]\n")
	head.Print()
	if !verifySlist(t, head, []int{1, 2, 4}) {
		return
	}

	// Step 4: [2, 4,]
	index = -1
	head = head.Delete(index)
	fmt.Printf("\nstep 4: [2, 4,]\n")
	head.Print()
	if !verifySlist(t, head, []int{2, 4}) {
		return
	}

	// Step 5: [4,]
	index = 0
	head = head.Delete(index)
	fmt.Printf("\nstep 5: [4,]\n")
	head.Print()
	if !verifySlist(t, head, []int{4}) {
		return
	}

	// Step 6: [,]
	index = 0
	head = head.Delete(index)
	fmt.Printf("\nstep 6: [,]\n")
	if head != nil {
		head.Print()
		t.Error("head is not null")
		return
	}

	// Step 7: [4,] -> [,]
	index = 9
	head = head.Insert(index, 4)
	head = head.Delete(index)
	fmt.Printf("\nstep 7: [,]\n")
	if head != nil {
		head.Print()
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
