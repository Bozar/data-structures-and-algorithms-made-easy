package llist_test

import (
	"fmt"
	"testing"

	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/llist"
)

func TestClist(t *testing.T) {
	fmt.Println("testCprint()")
	testCprint(t)

	fmt.Println("testCinsert()")
	testCinsert(t)

	fmt.Println("testCdelete()")
	testCdelete(t)
}

// Use `go test -v ./src/...` to see output.
func testCprint(t *testing.T) {
	n1 := llist.Cnode{}
	n2 := llist.Cnode{}
	n3 := llist.Cnode{}

	n1.Data = 1
	n2.Data = 2
	n3.Data = 3

	n1.Next = &n2
	n2.Next = &n3
	n3.Next = &n1

	n1.Print()
}

func testCinsert(t *testing.T) {
	var head *llist.Cnode

	// Step 1: [2,]
	index := 9
	data := 2
	head = head.Insert(index, data)
	fmt.Println("step 1: [2,]")
	head.Print()
	if !verifyClist(t, head, []int{2}) {
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
	fmt.Println("step 2: [2, 3, 4, 5,]")
	head.Print()
	if !verifyClist(t, head, []int{2, 3, 4, 5}) {
		return
	}

	// Step 3: [1, 2, 3, 4, 5,]
	index = -9
	data = 1
	head = head.Insert(index, data)
	fmt.Println("step 3: [1, 2, 3, 4, 5,]")
	head.Print()
	if !verifyClist(t, head, []int{1, 2, 3, 4, 5}) {
		return
	}
}

func testCdelete(t *testing.T) {
	// Step 0: [1, 2, 3, 4, 5, 6,]
	var head *llist.Cnode
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
	if !verifyClist(t, head, []int{1, 2, 3, 4, 5}) {
		return
	}

	// Step 2: [1, 2, 3, 4,]
	index = 4
	head = head.Delete(index)
	fmt.Printf("\nstep 2: [1, 2, 3, 4,]\n")
	head.Print()
	if !verifyClist(t, head, []int{1, 2, 3, 4}) {
		return
	}

	// Step 3: [1, 2, 4,]
	index = 2
	head = head.Delete(index)
	fmt.Printf("\nstep 3: [1, 2, 4,]\n")
	head.Print()
	if !verifyClist(t, head, []int{1, 2, 4}) {
		return
	}

	// Step 4: [2, 4,]
	index = -1
	head = head.Delete(index)
	fmt.Printf("\nstep 4: [2, 4,]\n")
	head.Print()
	if !verifyClist(t, head, []int{2, 4}) {
		return
	}

	// Step 5: [4,]
	index = 0
	head = head.Delete(index)
	fmt.Printf("\nstep 5: [4,]\n")
	head.Print()
	if !verifyClist(t, head, []int{4}) {
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

func verifyClist(t *testing.T, head *llist.Cnode, sample []int) bool {
	if head == nil {
		t.Error("input head is null")
		return false
	}

	start := head
	maxIdx := len(sample)
	for i := 0; i < maxIdx; i++ {
		if head.Data != sample[i] {
			t.Errorf(
				"idx: %d, wrong data: %d, right: %d",
				i, head.Data, sample[i],
			)
			return false
		} else if (i < maxIdx-1) && (head.Next == start) {
			t.Errorf("wrong size: %d", i)
			return false
		}
		head = head.Next
	}

	if head != start {
		t.Error("wrong size")
		return false
	}
	return true
}
