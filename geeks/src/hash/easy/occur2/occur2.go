// https://www.geeksforgeeks.org/dsa/maximum-distance-two-occurrences-element-array/
package occur2

import ()

func Print(input []int) int {
	valToIndex := make(map[int]int, len(input))
	maxDist := 0
	for i, v := range input {
		if vi, ok := valToIndex[v]; ok {
			maxDist = max(i-vi, maxDist)
		} else {
			valToIndex[v] = i
		}
	}
	return maxDist
}
