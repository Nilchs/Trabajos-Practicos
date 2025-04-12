package main

import (
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
func contarLetrasRecursiva(cadena string, numVocales, numConsonantes int) (int, int) {
	if cadena == "" {
		return numVocales, numConsonantes
	}
	c := cadena[0]
	if strings.ContainsRune("aeiouAEIOU", rune(c)) { // rune(c) -> convierte el caracter a un rune para que funcione con "ContainsRune".
		numVocales++
	} else if c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' {
		numConsonantes++
	}
	return contarLetrasRecursiva(cadena[1:], numVocales, numConsonantes) // "cadena[1:]" -> elimina el primer caracter de la cadena.
}

func main() {
	contarLetrasIterativa("hola")
	contarLetrasRecursiva("hola", 0, 0)
}
