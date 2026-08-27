// https://www.geeksforgeeks.org/dsa/equilibrium-index-of-an-array/
package equilibrium

import ()

func Print(input []int) int {
	arrSum := 0
	lfSum := 0
	for _, v := range input {
		arrSum += v
	}
	for i, v := range input {
		rtSum := arrSum - lfSum - v
		if lfSum == rtSum {
			return i
		}
		lfSum += v
	}
	return -1
}
