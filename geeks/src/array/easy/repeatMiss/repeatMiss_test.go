package repeatMiss_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/array/easy/repeatMiss"

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
			input: []int{3, 1, 3},
			want:  []int{3, 2},
		},
		tData{
			input: []int{4, 3, 6, 2, 1, 1},
			want:  []int{1, 5},
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", repeatMiss.Print(v.input))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v -> %v\n",
				output, v.input, v.want,
			)
			return
		}
	}
}
