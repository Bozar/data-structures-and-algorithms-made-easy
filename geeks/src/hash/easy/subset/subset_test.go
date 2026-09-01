package subset_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/hash/easy/subset"

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
			inputA: []int{11, 1, 13, 21, 3, 7},
			inputB: []int{11, 3, 7, 1},
			want:   true,
		},
		tData{
			inputA: []int{1, 2, 3, 4, 5, 6},
			inputB: []int{1, 2, 4},
			want:   true,
		},
		tData{
			inputA: []int{10, 5, 2, 23, 19},
			inputB: []int{19, 5, 3},
			want:   false,
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", subset.Print(v.inputA, v.inputB))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v, %v -> %v\n",
				output, v.inputA, v.inputB, v.want,
			)
			return
		}
	}
}
