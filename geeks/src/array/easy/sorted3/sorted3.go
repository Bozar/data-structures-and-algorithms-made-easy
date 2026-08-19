// https://www.geeksforgeeks.org/dsa/find-a-sorted-subsequence-of-size-3-in-linear-time/
package sorted3

import ()

func Print(input []int) []int {
	minNum, midNum, maxNum := -1, -1, -1
	for i, v := range input {
		if i == 0 {
			continue
		}
		if (midNum > 0) && (v > midNum) {
			maxNum = v
			break
		}
		if v > input[i-1] {
			minNum = input[i-1]
			midNum = v
		}
	}
	if minNum > 0 {
		return []int{minNum, midNum, maxNum}
	}
	return []int{}
}
