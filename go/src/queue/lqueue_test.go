package queue_test

import (
	"fmt"
	"testing"

	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/queue"
)

func TestLqueue(t *testing.T) {
	fmt.Println("testLnew()")
	testLnew(t)

	fmt.Println("testLenqueue()")
	testLenqueue(t)

	fmt.Println("testLdequeue()")
	testLdequeue(t)
}

func testLnew(t *testing.T) {
	queue := new(queue.Lqueue)
	if !queue.IsEmpty() {
		t.Error("queue is NOT empty")
	} else if queue.Size() != 0 {
		t.Error("queue size is NOT 0")
	}
}

func testLenqueue(t *testing.T) {
	queue := new(queue.Lqueue)

	data, ok := queue.Peek()
	if ok {
		t.Errorf("Peek() should fail: %d", data)
	}

	const minI int = 1
	const maxI int = 6
	for i := minI; i < maxI; i++ {
		queue.Enqueue(i)
		if queue.Size() != i {
			t.Errorf("wrong size: %d, right: %d", queue.Size(), i)
		}
		data, ok = queue.Peek()
		if (data != minI) || (!ok) {
			t.Errorf("wrong peek data: %d, right: %d", data, minI)
		}
	}
}

func testLdequeue(t *testing.T) {
	queue := new(queue.Lqueue)

	data, ok := queue.Dequeue()
	if ok {
		t.Errorf("Dequeue() should fail: %d", data)
	}

	const minI int = 1
	const maxI int = 5
	for i := minI; i < maxI+1; i++ {
		queue.Enqueue(i)
	}
	for i := minI; i < maxI+1; i++ {
		data, ok = queue.Dequeue()
		if (data != i) || (!ok) {
			t.Errorf("wrong dequeue: %d, right: %d", data, i)
		} else if queue.Size() != maxI-i {
			t.Errorf(
				"wrong size: %d, right: %d",
				queue.Size(), maxI-i,
			)
		}
		if i == maxI {
			continue
		}
		data, ok = queue.Peek()
		if (data != i+1) || (!ok) {
			t.Errorf("wrong peek: %d, right: %d", data, i+1)
		}
	}
}
