// https://www.geeksforgeeks.org/dsa/find-the-missing-number/
package missNum

import ()

func Print(input []int) int {
	nums := make([]int, len(input)+1)
	for _, v := range input {
		nums[v-1] = v
	}
	for i := range nums {
		if nums[i] == 0 {
			return i + 1
		}
	}
	return 0
}
