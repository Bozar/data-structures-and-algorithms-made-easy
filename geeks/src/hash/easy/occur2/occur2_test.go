package occur2_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/hash/easy/occur2"

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
			input: []int{1, 1, 2, 2, 2, 1},
			want:  5,
		},
		tData{
			input: []int{3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2},
			want:  10,
		},
		tData{
			input: []int{1, 2, 3, 6, 5, 4},
			want:  0,
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", occur2.Print(v.input))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v -> %v\n",
				output, v.input, v.want,
			)
			return
		}
	}
}
