package union_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/hash/easy/union"

	"fmt"
	"testing"
)

type tData struct {
	inputA []int
	inputB []int
	want   []int
}

func TestPrint(t *testing.T) {
	data := []tData{
		tData{
			inputA: []int{1, 2, 3, 2, 1},
			inputB: []int{3, 2, 2, 3, 3, 2},
			want:   []int{1, 2, 3},
		},
		tData{
			inputA: []int{1, 2, 3},
			inputB: []int{4, 5, 6},
			want:   []int{1, 2, 3, 4, 5, 6},
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", union.Print(v.inputA, v.inputB))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v, %v -> %v\n",
				output, v.inputA, v.inputB, v.want,
			)
			return
		}
	}
}
