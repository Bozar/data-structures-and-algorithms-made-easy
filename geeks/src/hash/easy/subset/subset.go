// https://www.geeksforgeeks.org/dsa/find-whether-an-array-is-subset-of-another-array-set-1/
package subset

import ()

func Print(inputA []int, inputB []int) bool {
	inputHash := map[int]bool{}
	for _, v := range inputA {
		inputHash[v] = true
	}
	for _, v := range inputB {
		if _, ok := inputHash[v]; !ok {
			return false
		}
	}
	return true
}
