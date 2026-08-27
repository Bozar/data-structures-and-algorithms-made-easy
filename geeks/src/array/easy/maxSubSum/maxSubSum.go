// https://www.geeksforgeeks.org/dsa/largest-sum-contiguous-subarray/
package maxSubSum

import ()

func Print(input []int) int {
	maxSubSum := input[0]
	for i := range input {
		subSum := 0
		for j := i; j < len(input); j++ {
			subSum += input[j]
			if subSum > maxSubSum {
				maxSubSum = subSum
			}
		}
	}
	return maxSubSum
}
