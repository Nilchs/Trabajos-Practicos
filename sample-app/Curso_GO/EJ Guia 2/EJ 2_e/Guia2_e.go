package main

import "fmt"

func invertirIterativo(a []int) []int {
	aNew := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		aNew[i] = a[len(a)-1-i] //
	}
	return aNew
}

func main() {
	arreglo := []int{1, 2, 3}
	a1 := invertirIterativo(arreglo)
	fmt.Printf("El arreglo invertido queda: %v\n", a1)
}
