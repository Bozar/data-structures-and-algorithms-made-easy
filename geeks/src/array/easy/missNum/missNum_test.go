package missNum_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/array/easy/missNum"

	//	"fmt"
	"testing"
)

type tData struct {
	input []int
	want  int
}

func TestPrint(t *testing.T) {
	data := []tData{
		tData{
			input: []int{8, 2, 4, 5, 3, 7, 1},
			want:  6,
		},
		tData{
			input: []int{1, 2, 3, 5},
			want:  4,
		},
	}

	for _, v := range data {
		output := missNum.Print(v.input)
		if output != v.want {
			t.Errorf(
				"\nwrong: %v\nwant: %v, %v\n",
				output, v.want, v.input,
			)
			return
		}
	}
}
