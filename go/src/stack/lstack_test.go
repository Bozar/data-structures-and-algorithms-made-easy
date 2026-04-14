package stack_test

import (
	"fmt"
	"testing"

	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/internal/debug"
	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/stack"
)

func TestLstack(t *testing.T) {
	if !debug.IsDebugLstack {
		t.SkipNow()
	}

	fmt.Println("testLnew()")
	testLnew(t)

	fmt.Println()
	fmt.Println("testLpush()")
	testLpush(t)

	fmt.Println()
	fmt.Println("testLpop()")
	testLpop(t)
}

func testLnew(t *testing.T) {
	stack := new(stack.Lstack)
	if !stack.IsEmpty() {
		t.Error("stack is NOT empty")
	} else if stack.Size() != 0 {
		t.Error("stack size is NOT 0")
	}
}

func testLpush(t *testing.T) {
	stack := new(stack.Lstack)

	data, ok := stack.Peek()
	if ok {
		t.Errorf("Peek() should fail: %d", data)
	}

	for i := 1; i < 6; i++ {
		stack.Push(i)
		if stack.Size() != i {
			t.Errorf("wrong size: %d, right: %d", stack.Size(), i)
		}
		data, ok = stack.Peek()
		if (data != i) || (!ok) {
			t.Errorf("wrong peek data: %d, right: %d", data, i)
		}
	}
}

func testLpop(t *testing.T) {
	stack := new(stack.Lstack)

	data, ok := stack.Pop()
	if ok {
		t.Errorf("Pop() should fail: %d", data)
	}

	const maxI = 5
	for i := maxI; i > 0; i-- {
		stack.Push(i)
	}
	for i := 1; i < maxI+1; i++ {
		data, ok = stack.Pop()
		if (data != i) || (!ok) {
			t.Errorf("wrong pop: %d, right: %d", data, i)
		} else if stack.Size() != maxI-i {
			t.Errorf(
				"wrong size: %d, right: %d",
				stack.Size(), maxI-i,
			)
		}
		if i == maxI {
			continue
		}
		data, ok = stack.Peek()
		if (data != i+1) || (!ok) {
			t.Errorf("wrong peek: %d, right: %d", data, i+1)
		}
	}
}
