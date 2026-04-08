package llist_test

import (
	//	"fmt"
	"testing"

	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/internal/debug"
	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/llist"
)

// Use `go test -v ./src/...` to see output.
func TestSprint(t *testing.T) {
	if !debug.IsDebugSlist {
		t.SkipNow()
	}

	n1 := llist.Snode{}
	n2 := llist.Snode{}
	n3 := llist.Snode{}

	n1.Data = 1
	n2.Data = 2
	n3.Data = 3

	n1.Next = &n2
	n2.Next = &n3

	llist.Sprint(n1)
}
