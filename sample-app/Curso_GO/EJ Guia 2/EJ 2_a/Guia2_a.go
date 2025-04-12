package main

import "fmt"

// Iterativa
func cuenta_regresivaIterativa(n int) {
	for i := 0; i <= n; i++ {
		fmt.Println(n)
	}
}

// Recursiva
func cuenta_regresivaRecursiva(n, actual int) {
	if actual > n {
		return
	}
	fmt.Println(actual)
	cuenta_regresivaRecursiva(n, actual-1)
}

func main() {
	cuenta_regresivaIterativa(5)
	cuenta_regresivaRecursiva(5, 0)
}
