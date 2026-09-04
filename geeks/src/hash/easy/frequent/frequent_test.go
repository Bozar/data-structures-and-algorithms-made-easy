package frequent_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/hash/easy/frequent"

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
			input: []int{1, 3, 2, 1, 4, 1},
			want:  1,
		},
		tData{
			input: []int{10, 20, 10, 20, 30, 20, 20},
			want:  20,
		},
		tData{
			input: []int{1, 2, 2, 4, 1},
			want:  2,
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", frequent.Print(v.input))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v -> %v\n",
				output, v.input, v.want,
			)
			return
		}
	}
}
