package sorted3_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/array/easy/sorted3"

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
			input: []int{12, 11, 10, 5, 6, 2, 30},
			want:  []int{5, 6, 30},
		},
		tData{
			input: []int{1, 2, 3, 4},
			want:  []int{1, 2, 3},
		},
		tData{
			input: []int{4, 3, 2, 1},
			want:  []int{},
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", sorted3.Print(v.input))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v -> %v\n",
				output, v.input, v.want,
			)
			return
		}
	}
}
