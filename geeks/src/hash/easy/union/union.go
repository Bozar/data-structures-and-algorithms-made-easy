// https://www.geeksforgeeks.org/dsa/union-of-two-arrays/
package union

import ()

func Print(inputA []int, inputB []int) []int {
	abToBool := make(map[int]bool, len(inputA))
	union := make([]int, 0, len(inputA)+len(inputB))
	for _, v := range inputA {
		if _, ok := abToBool[v]; ok {
			continue
		}
		abToBool[v] = true
		union = append(union, v)
	}
	for _, v := range inputB {
		if _, ok := abToBool[v]; ok {
			continue
		}
		abToBool[v] = true
		union = append(union, v)
	}
	return union
}
