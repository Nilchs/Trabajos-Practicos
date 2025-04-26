package main

import (
	"fmt"
	"strings"
)

type Pila struct {
	elementos []rune // No hace falta la variable "tamaño" porque, En Go, los slices ya manejan su propio tamaño internamente.
}

func nuevaPila() *Pila {
	return &Pila{elementos: []rune{}} // Agrego "[]rune{}" para reservar un espacio vacío de caracteres rune y evitar errores al hacer "append" sobre un slice que no existe.
}

// Operacion Apilar
func (p *Pila) apilar(valor rune) {
	p.elementos = append(p.elementos, valor)
}

// Operacion Desapilar
func (p *Pila) desapilar() rune {
	if p.es_vacia() {
		panic("Pila vacia") // "panic" detiene el programa si se trata de desapilar una pila vacia.
	}
	valor := p.elementos[len(p.elementos)-1]
	p.elementos = p.elementos[:len(p.elementos)-1] // Saco el ultimo elemento de la pila al desapirla el valor.
	return valor
}

// Observador Básico
func (p *Pila) es_vacia() bool {
	return len(p.elementos) == 0
}

func main() {
	var texto string

	fmt.Println("Ingrese una secuencia de caracteres: ")
	fmt.Scanln(&texto)

	texto = strings.ToLower(texto) // Ignorar mayúsculas/minúsculas

	pila := nuevaPila()

	// Apilamos todos los caracteres
	for _, c := range texto {
		pila.apilar(c)
	}

	esPalindromo := true
	for _, c := range texto {
		if c != pila.desapilar() {
			esPalindromo = false
			break
		}
	}

	if esPalindromo {
		fmt.Println("Es un palindromo.")
	} else {
		fmt.Println("No es un palindromo.")
	}
}
