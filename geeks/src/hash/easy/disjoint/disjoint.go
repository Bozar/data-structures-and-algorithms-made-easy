// https://www.geeksforgeeks.org/dsa/check-two-given-sets-disjoint/
package disjoint

import ()

func Print(inputA []int, inputB []int) bool {
	inputHash := map[int]bool{}
	for _, v := range inputA {
		inputHash[v] = true
	}
	for _, v := range inputB {
		if _, ok := inputHash[v]; ok {
			return false
		}
	}
	return true
}
