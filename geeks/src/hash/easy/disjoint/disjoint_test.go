package disjoint_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/hash/easy/disjoint"

	"fmt"
	"testing"
)

type tData struct {
	inputA []int
	inputB []int
	want   bool
}

func TestPrint(t *testing.T) {
	data := []tData{
		tData{
			inputA: []int{12, 34, 11, 9, 3},
			inputB: []int{2, 1, 3, 5},
			want:   false,
		},
		tData{
			inputA: []int{12, 34, 11, 9, 3},
			inputB: []int{7, 2, 1, 5},
			want:   true,
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", disjoint.Print(v.inputA, v.inputB))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v, %v -> %v\n",
				output, v.inputA, v.inputB, v.want,
			)
			return
		}
	}
}
