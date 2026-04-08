package llist_test

import (
	//	"fmt"
	"testing"

	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/internal/debug"
	"github.com/Bozar/data-structures-and-algorithms-made-easy/go/src/llist"
)

// Use `go test -v ./src/...` to see output.
func TestCprint(t *testing.T) {
	if !debug.IsDebugClist {
		t.SkipNow()
	}

	n1 := llist.Cnode{}
	n2 := llist.Cnode{}
	n3 := llist.Cnode{}

	n1.Data = 1
	n2.Data = 2
	n3.Data = 3

	n1.Next = &n2
	n2.Next = &n3
	n3.Next = &n1

	llist.Cprint(n1)
}
