package repeat1n1_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/array/easy/repeat1n1"

	//"fmt"
	"testing"
)

type tData struct {
	input []int
	want  int
}

func TestPrintSum(t *testing.T) {
	data := []tData{
		tData{
			input: []int{1, 3, 2, 3, 4},
			want:  3,
		},
		tData{
			input: []int{1, 5, 1, 2, 3, 4},
			want:  1,
		},
	}

	for _, v := range data {
		output := repeat1n1.PrintSum(v.input)
		if output != v.want {
			t.Errorf(
				"\nwrong: %v\nwant: %v -> %v\n",
				output, v.input, v.want,
			)
			return
		}
	}
}

func TestPrintXor(t *testing.T) {
	data := []tData{
		tData{
			input: []int{1, 3, 2, 3, 4},
			want:  3,
		},
		tData{
			input: []int{1, 5, 1, 2, 3, 4},
			want:  1,
		},
	}

	for _, v := range data {
		output := repeat1n1.PrintXor(v.input)
		if output != v.want {
			t.Errorf(
				"\nwrong: %v\nwant: %v -> %v\n",
				output, v.input, v.want,
			)
			return
		}
	}
}
