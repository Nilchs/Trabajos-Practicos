package main

import "fmt"

type nodo struct {
	valor     int
	siguiente *nodo
	anterior  *nodo
}

type Cola struct {
	frente *nodo
	final  *nodo
	tamano int
}

// Crear una nueva cola vacía
func nuevaCola() *Cola {
	return &Cola{frente: nil, final: nil, tamano: 0}
}

// Encolar un valor al final (O(1))
func (c *Cola) encolar(valor int) {
	nuevoNodo := &nodo{valor: valor}

	if c.frente == nil {
		// Si la cola está vacía
		c.frente = nuevoNodo
		c.final = nuevoNodo
	} else {
		// Insertamos al final
		c.final.siguiente = nuevoNodo
		nuevoNodo.anterior = c.final
		c.final = nuevoNodo
	}

	c.tamano++
}

// Desencolar (sacar el frente) (O(1))
func (c *Cola) desencolar() int {
	if c.frente == nil {
		panic("No se puede desencolar: la cola esta vacia")
	}

	valor := c.frente.valor
	c.frente = c.frente.siguiente

	if c.frente != nil {
		c.frente.anterior = nil
	} else {
		// Si después de desencolar queda vacía
		c.final = nil
	}

	c.tamano--
	return valor
}

// Función para saber si la cola está vacía
func (c *Cola) esVacia() bool {
	return c.tamano == 0
}

// Obtener el tamaño de la cola
func (c *Cola) obtenerTamano() int {
	return c.tamano
}

func main() {
	cola := nuevaCola()

	cola.encolar(10)
	cola.encolar(20)
	cola.encolar(30)

	fmt.Println("Tamano actual:", cola.obtenerTamano())                   // 3
	fmt.Println("Desencolar:", cola.desencolar())                         // 10
	fmt.Println("Nuevo frente despues de desencolar:", cola.frente.valor) // 20
	fmt.Println("Tamano actual:", cola.obtenerTamano())                   // 2
}
