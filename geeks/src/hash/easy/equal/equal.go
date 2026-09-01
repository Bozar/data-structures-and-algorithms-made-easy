// https://www.geeksforgeeks.org/dsa/check-two-given-sets-equal/
package equal

import ()

func Print(inputA []int, inputB []int) bool {
	inputHash := map[int]int{}
	for _, v := range inputA {
		inputHash[v] += 1
	}
	for _, v := range inputB {
		if _, ok := inputHash[v]; !ok {
			return false
		}
		inputHash[v] -= 1
		if inputHash[v] < 0 {
			return false
		}

	}
	return true
}
