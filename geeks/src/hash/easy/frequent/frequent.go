// https://www.geeksforgeeks.org/dsa/frequent-element-array/
package frequent

import ()

func Print(input []int) int {
	vToCount := make(map[int]int, len(input))
	for _, v := range input {
		vToCount[v] += 1
	}
	maxV := 0
	maxFrq := 0
	for k, v := range vToCount {
		if (v > maxFrq) || ((v == maxFrq) && (k > maxV)) {
			maxV = k
			maxFrq = v
		}
	}
	return maxV
}
