package equal_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/hash/easy/equal"

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
			inputA: []int{1, 2, 5, 4, 0},
			inputB: []int{2, 4, 5, 0, 1},
			want:   true,
		},
		tData{
			inputA: []int{1, 2, 5, 4, 0, 2, 1},
			inputB: []int{2, 4, 5, 0, 1, 1, 2},
			want:   true,
		},
		tData{
			inputA: []int{1, 7, 1},
			inputB: []int{7, 7, 1},
			want:   false,
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", equal.Print(v.inputA, v.inputB))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v, %v -> %v\n",
				output, v.inputA, v.inputB, v.want,
			)
			return
		}
	}
}
