// https://www.geeksforgeeks.org/dsa/fizz-buzz-implementation/
package fizz

import (
	"strconv"
)

func Print(input int) []string {
	divs := []int{15, 3, 5}
	divToStr := map[int]string{
		15: "FizzBuzz",
		3:  "Fizz",
		5:  "Buzz",
	}
	output := make([]string, input)
	for i := 1; i <= input; i++ {
		for _, v := range divs {
			if i%v == 0 {
				output[i-1] = divToStr[v]
				break
			}
		}
		if output[i-1] == "" {
			output[i-1] = strconv.Itoa(i)
		}
	}
	return output
}
