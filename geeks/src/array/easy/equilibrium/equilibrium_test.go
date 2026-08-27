package equilibrium_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/array/easy/equilibrium"

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
			input: []int{1, 2, 0, 3},
			want:  2,
		},
		tData{
			input: []int{1, 1, 1, 1},
			want:  -1,
		},
		tData{
			input: []int{-7, 1, 5, 2, -4, 3, 0},
			want:  3,
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", equilibrium.Print(v.input))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v -> %v\n",
				output, v.input, v.want,
			)
			return
		}
	}
}
