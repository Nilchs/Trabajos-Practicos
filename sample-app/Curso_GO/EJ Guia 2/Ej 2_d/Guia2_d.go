package main

import "fmt"

// iterativa
func mayor_elementoIterativa(arreglo []int) int {
	mayor := 0
	for i := 0; i < len(arreglo); i++ {
		if mayor > arreglo[i] {
			mayor = arreglo[i]
		}
	}
	return mayor
}

func mayor_elementoRecursivo(i, mayor int, arreglo []int) int {
	if i > len(arreglo) {
		return 0
	}
	if mayor > len(arreglo) {
		mayor = arreglo[i]
	}
	return mayor_elementoRecursivo(i+1, mayor, arreglo)
}

func main() {
	arreglo := []int{5, 7, 2, 10, 1}
	a1 := mayor_elementoIterativa(arreglo)
	fmt.Printf("El mayor elemento del arreglo es: %d\n", a1)
	a2 := mayor_elementoRecursivo(0, 0, arreglo)
	fmt.Printf("El mayor elemento del arreglo es: %d\n", a2)
}
