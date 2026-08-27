// https://www.geeksforgeeks.org/dsa/split-array-three-equal-sum-subarrays/
package split3

import ()

func Print(input []int) []int {
	sum := 0
	for _, v := range input {
		sum += v
	}
	if sum%3 != 0 {
		return []int{-1, -1}
	}

	sum /= 3
	sav := sum
	idx0, idx1 := -1, -1
	for i, v := range input {
		sum -= v
		if sum == 0 {
			idx0 = i
			sum = sav
			break
		}
	}
	if idx0 < 0 {
		return []int{-1, -1}
	}

	for i := idx0 + 1; i < len(input); i++ {
		sum -= input[i]
		if sum == 0 {
			idx1 = i
			break
		}
	}
	return []int{idx0, idx1}
}
