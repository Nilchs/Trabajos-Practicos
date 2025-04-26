package main

import (
	"fmt"
)

func main() {
	var pila []int

	fmt.Println("Ingrese 10 numeros: ")
	for i := 1; i <= 10; i++ {
		var Num int
		fmt.Printf("Numero %d: ", i)
		fmt.Scan(&Num)
		pila = append(pila, Num)
	}

	fmt.Println("La pila invertida queda de la forma: ")
	for i := 0; len(pila) > 0; i++ {
		tope := pila[len(pila)-1]
		fmt.Println(tope)
		pila = pila[:len(pila)-1]
	}
}
