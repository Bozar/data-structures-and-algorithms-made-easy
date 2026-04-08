package llist_test

import (
	"testing"

	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/internal/debug"
	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/llist"
)

// Use `go test -v ./src/...` to see output.
func TestDprint(t *testing.T) {
	if !debug.IsDebugDlist {
		t.SkipNow()
	}

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
