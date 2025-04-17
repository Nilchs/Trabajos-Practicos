package main

import "fmt"

func invertirIterativo(a []int) []int {
	aNew := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		aNew[i] = a[len(a)-1-i] //
	}
	return aNew
}

func invertirRecursivo(i int, aNew, a []int) []int {
	if i >= len(a) {
		return aNew
	}
	aNew[i] = a[len(a)-1-i]
	return invertirRecursivo(i+1, aNew, a)
}

func main() {
	arreglo := []int{1, 2, 3}
	arregloNew := make([]int, len(arreglo))
	a1 := invertirIterativo(arreglo)
	fmt.Printf("El arreglo invertido de forma iterativa queda: %v\n", a1)
	a2 := invertirRecursivo(0, arregloNew, arreglo)
	fmt.Printf("El arreglo invertido de forma recursiva queda: %v\n", a2)
}
