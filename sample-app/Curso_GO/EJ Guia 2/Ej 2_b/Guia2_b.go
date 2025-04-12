package main

import (
	"fmt"
)

// Iterativa
func suma_enterosIterativa(inicio, fin int) int {
	suma := 0
	for i := inicio; i <= fin; i++ {
		suma += i
	}
	return suma
}

// Recursiva
func suma_enterosRecursiva(inicio, fin int) int {
	if inicio > fin {
		return 0
	}
	return inicio + suma_enterosRecursiva(inicio+1, fin)
}

func main() {
	fmt.Sprintln(suma_enterosIterativa(2, 2))
	fmt.Sprintln(suma_enterosRecursiva(3, 1))
}
