package split3_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/array/easy/split3"

	"fmt"
	"testing"
)

type tData struct {
	input []int
	want  []int
}

func TestPrint(t *testing.T) {
	data := []tData{
		tData{
			input: []int{1, 3, 4, 0, 4},
			want:  []int{1, 2},
		},
		tData{
			input: []int{2, 3, 4},
			want:  []int{-1, -1},
		},
		tData{
			input: []int{1, -1, 1, -1, 1, -1, 1, -1},
			want:  []int{1, 3},
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", split3.Print(v.input))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v -> %v\n",
				output, v.input, v.want,
			)
			return
		}
	}
}
