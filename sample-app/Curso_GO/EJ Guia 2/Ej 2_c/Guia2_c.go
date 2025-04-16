package main

import (
	"fmt"
	"strings"
)

// iterativa
func contarLetrasIterativa(cadena string) (int, int) {
	vocales := "aeiouAEIOU"
	numVocales, numConsonantes := 0, 0
	for _, c := range cadena { // "_" -> representa el indice pero no lo uso en este caso. "c" -> representa el caracter.
		if strings.ContainsRune(vocales, c) { // "ContainsRune" -> verifica si el caracter "c" esta dentro de la cadena "vocales".
			numVocales++
		} else if c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' { // Verifica si el caracter es una letra.
			numConsonantes++
		}
	}
	return numVocales, numConsonantes
}

// recursiva
func contarLetrasRecursiva(cadena string, i int, numVocales, numConsonantes int) (int, int) {
	if i >= len(cadena) {
		return numVocales, numConsonantes
	}
	c := cadena[i]
	if strings.ContainsRune("aeiouAEIOU", rune(c)) { // rune(c) -> convierte el caracter a un rune para que funcione con "ContainsRune".
		numVocales++
	} else if c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' {
		numConsonantes++
	}
	return contarLetrasRecursiva(cadena, i+1, numVocales, numConsonantes) // "cadena[1:]" -> elimina el primer caracter de la cadena.
}

func main() {
	S, S2 := "Hola", "Perro"
	r, r1 := contarLetrasIterativa(S)
	fmt.Printf("El texto \"%s\" en forma Iterativa, contiene %d vocales y %d consonantes.\n", S, r, r1)
	r, r1 = contarLetrasRecursiva(S2, 0, 0, 0)
	fmt.Printf("El texto \"%s\" en forma Recursiva, contiene %d vocales y %d consonantes.\n", S2, r, r1)
}
