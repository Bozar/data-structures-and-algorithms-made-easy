// https://www.geeksforgeeks.org/dsa/intersection-of-two-arrays/
package intersect

import ()

func Print(inputA []int, inputB []int) []int {
	aToBool := make(map[int]bool, len(inputA))
	inter := make([]int, 0, min(len(inputA), len(inputB)))
	for _, v := range inputA {
		if _, ok := aToBool[v]; ok {
			continue
		}
		aToBool[v] = true
	}
	for _, v := range inputB {
		if aToBool[v] {
			inter = append(inter, v)
			delete(aToBool, v)
		}
	}
	return inter
}
