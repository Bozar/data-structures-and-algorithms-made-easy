package intersect_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/hash/easy/intersect"

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
			inputA: []int{1, 2, 1, 3, 1},
			inputB: []int{3, 1, 3, 4, 1},
			want:   []int{3, 1},
		},
		tData{
			inputA: []int{1, 1, 1},
			inputB: []int{1, 1, 1, 1, 1},
			want:   []int{1},
		},
		tData{
			inputA: []int{1, 2, 3},
			inputB: []int{4, 5, 6},
			want:   []int{},
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", intersect.Print(v.inputA, v.inputB))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v, %v -> %v\n",
				output, v.inputA, v.inputB, v.want,
			)
			return
		}
	}
}
