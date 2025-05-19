package main

import (
	"fmt"
)

type Nodo struct {
	valor     int
	izquierda *Nodo
	derecha   *Nodo
	altura    int
}

type AVL struct {
	raiz *Nodo
}

func altura(n *Nodo) int {
	if n == nil {
		return 0
	}
	return n.altura
}

func actualizarAltura(n *Nodo) {
	n.altura = 1 + max(altura(n.izquierda), altura(n.derecha))
}

func factorEquilibrio(n *Nodo) int {
	if n == nil {
		return 0
	}
	return altura(n.derecha) - altura(n.izquierda)
}

func rotarIzquierda(z *Nodo) *Nodo {
	y := z.derecha
	T2 := y.izquierda
	y.izquierda = z
	z.derecha = T2

	actualizarAltura(z)
	actualizarAltura(y)
	return y
}

func rotarDerecha(z *Nodo) *Nodo {
	y := z.izquierda
	T3 := y.derecha
	y.derecha = z
	z.izquierda = T3

	actualizarAltura(z)
	actualizarAltura(y)
	return y
}

func insertar(n *Nodo, valor int) *Nodo {
	if n == nil {
		return &Nodo{valor: valor, altura: 1}
	}

	if valor < n.valor {
		n.izquierda = insertar(n.izquierda, valor)
	} else if valor > n.valor {
		n.derecha = insertar(n.derecha, valor)
	} else {
		return n // no se permiten duplicados
	}

	actualizarAltura(n)
	fe := factorEquilibrio(n)

	// Rotar izquierda izquierda
	if fe < -1 && valor < n.izquierda.valor {
		return rotarDerecha(n)
	}
	// Rotar derecha derecha
	if fe > 1 && valor > n.derecha.valor {
		return rotarIzquierda(n)
	}
	// Rotar izquierda derecha
	if fe < -1 && valor > n.izquierda.valor {
		n.izquierda = rotarIzquierda(n.izquierda)
		return rotarDerecha(n)
	}
	// Rotar derecha izquierda
	if fe > 1 && valor < n.derecha.valor {
		n.derecha = rotarDerecha(n.derecha)
		return rotarIzquierda(n)
	}

	return n
}

func buscar(n *Nodo, valor int) bool {
	if n == nil {
		return false
	}
	if valor == n.valor {
		return true
	} else if valor < n.valor {
		return buscar(n.izquierda, valor)
	} else {
		return buscar(n.derecha, valor)
	}
}

func minimo(n *Nodo) *Nodo {
	actual := n
	for actual.izquierda != nil {
		actual = actual.izquierda
	}
	return actual
}

func mayor(m *Nodo) *Nodo {
	actual := m
	for actual.derecha != nil {
		actual = actual.derecha
	}
	return actual
}

func main() {
	var raiz *Nodo

	codigos := []int{
		1012,
		1020,
		1005,
		1030,
		1008,
		1015,
		1025,
	}

	// Insertar en AVL
	for _, codigos := range codigos {
		raiz = insertar(raiz, codigos)
	}

	fmt.Println("Códigos insertados en el AVL.")

	// Ejemplo de búsqueda
	codigoBuscado := 1015
	encontrado := buscar(raiz, codigoBuscado)
	fmt.Printf("¿El código %d está en el inventario?: %v\n", codigoBuscado, encontrado)

	// Ejemplo de mínimo y máximo
	fmt.Println("Código menor:", minimo(raiz).valor)
	fmt.Println("Código mayor:", mayor(raiz).valor)
}
