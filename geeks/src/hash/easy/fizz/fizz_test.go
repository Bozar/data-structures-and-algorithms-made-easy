package fizz_test

import (
	"github.com/Bozar/data-structures-and-algorithms/geeks/src/hash/easy/fizz"

	"fmt"
	"testing"
)

type tData struct {
	input int
	want  []string
}

func TestPrint(t *testing.T) {
	data := []tData{
		tData{
			input: 3,
			want:  []string{"1", "2", "Fizz"},
		},
		tData{
			input: 10,
			want: []string{
				"1", "2", "Fizz", "4", "Buzz", "Fizz", "7",
				"8", "Fizz", "Buzz",
			},
		},
		tData{
			input: 20,
			want: []string{
				"1", "2", "Fizz", "4", "Buzz", "Fizz", "7",
				"8", "Fizz", "Buzz", "11", "Fizz", "13", "14",
				"FizzBuzz", "16", "17", "Fizz", "19", "Buzz",
			},
		},
	}

	for _, v := range data {
		output := fmt.Sprintf("%v", fizz.Print(v.input))
		if output != fmt.Sprintf("%v", v.want) {
			t.Errorf(
				"\nwrong: %v\nwant: %v -> %v\n",
				output, v.input, v.want,
			)
			return
		}
	}
}
