// https://www.geeksforgeeks.org/dsa/find-a-repeating-and-a-missing-number/
package repeatMiss

import ()

func Print(input []int) []int {
	nums := make([]int, len(input))
	for _, v := range input {
		nums[v-1] += 1
	}
	repeat, miss := 0, 0
	for i, v := range nums {
		if v == 0 {
			miss = i + 1
		} else if v == 2 {
			repeat = i + 1
		}
	}
	return []int{repeat, miss}
}
