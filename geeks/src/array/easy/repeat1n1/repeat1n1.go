// https://www.geeksforgeeks.org/dsa/find-repetitive-element-1-n-1/
package repeat1n1

import ()

func PrintSum(input []int) int {
	maxNum := len(input) - 1
	sumNum := maxNum * (maxNum + 1) / 2
	for _, v := range input {
		sumNum -= v
	}
	return -sumNum
}

func PrintXor(input []int) int {
	xInput := 0
	for i, v := range input {
		if i == 0 {
			xInput = v
			continue
		}
		xInput ^= i ^ v
	}
	return xInput
}
