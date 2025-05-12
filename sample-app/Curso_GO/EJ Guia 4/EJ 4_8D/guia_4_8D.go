package main

type Node struct {
	valor     int
	izquierda *Node
	derecha   *Node
}

type ABB struct {
	raiz *Node
}

// Ejercicio d.1 - Función para encontrar el mínimo de un ABB en forma recursiva

func (abb *ABB) MinimoRecursivo() (int, bool) {
	// Verificar si el árbol está vacío
	nodo := minimoRecursivo(abb.raiz)

	if nodo == nil { // Si el nodo es nil, significa que el árbol está vacío
		return 0, false // Árbol vacío
	}
	return nodo.valor, true // Retornar el valor del nodo mínimo y true indicando que se encontró
}

func minimoRecursivo(nodo *Node) *Node {
	// Caso base: si el nodo es nil, retornar nil
	if nodo == nil || nodo.izquierda == nil {
		return nodo
	}
	// Caso recursivo: si el nodo no es nil, seguir buscando en la izquierda
	return minimoRecursivo(nodo.izquierda)
}

// Ejercicio d.2 - Función para encontrar el mínimo de un ABB en forma iterativa

func (abb *ABB) MinimoIterativo() (int, bool) {
	actual := abb.raiz

	if actual == nil {
		return 0, false // Árbol vacío
	}

	for actual.izquierda != nil {
		actual = actual.izquierda
	}

	return actual.valor, true
}

/*
| Método    | Ventaja                                 | Costo                                   |
| --------- | --------------------------------------- | --------------------------------------- |
| Recursivo | Más simple y directo                    | Usa pila de llamadas (consumo de stack) |
| Iterativo | Más eficiente en memoria (no usa stack) | Ligeramente más largo de escribir       |
*/
