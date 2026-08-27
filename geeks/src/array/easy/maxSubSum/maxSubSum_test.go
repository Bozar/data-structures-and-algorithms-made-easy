package maxSubSum_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/array/easy/maxSubSum"

	"fmt"
	"testing"
)

type tData struct {
	input []int
	want  int
}

func TestPrint(t *testing.T) {
	data := []tData{
		tData{
			input: []int{2, 3, -8, 7, -1, 2, 3},
			want:  11,
		},
		tData{
			input: []int{-2, -4},
			want:  -2,
		},
		tData{
			input: []int{5, 4, 1, 7, 8},
			want:  25,
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", maxSubSum.Print(v.input))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v -> %v\n",
				output, v.input, v.want,
			)
			return
		}
	}
}
