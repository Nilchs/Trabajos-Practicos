package main

type Node struct {
	valor     int
	izquierda *Node
	derecha   *Node
}

type ABB struct {
	raiz *Node
}

// Inserta un valor en el ABB
func (a *ABB) Insertar(valor int) {
	a.raiz = insertarNodo(a.raiz, valor)
}

func insertarNodo(nodo *Node, valor int) *Node {
	if nodo == nil {
		return &Node{valor: valor}
	}
	if valor < nodo.valor {
		nodo.izquierda = insertarNodo(nodo.izquierda, valor)
	} else if valor > nodo.valor {
		nodo.derecha = insertarNodo(nodo.derecha, valor)
	}
	// Si el valor ya existe, no lo inserto
	return nodo
}

// Buscar un valor en nodos ABB
func (a *ABB) Buscar(valor int) bool {
	return buscarEnNodo(a.raiz, valor)
}

func buscarEnNodo(n *Node, valor int) bool {
	if n == nil {
		return false
	}
	if valor == n.valor {
		return true
	} else if valor < n.valor {
		return buscarEnNodo(n.izquierda, valor)
	} else {
		return buscarEnNodo(n.derecha, valor)
	}
}

/*
En el mejor caso (árbol perfectamente balanceado), la altura es aproximadamente: h ≈ log2(n)

En el peor caso (árbol completamente desbalanceado, como una lista), la altura es: h = n
*/

// Eliminar valor de un ABB
func (a *ABB) Eliminar(valor int) {
	a.raiz = eliminarNodo(a.raiz, valor)
}

func eliminarNodo(nodo *Node, valor int) *Node {
	if nodo == nil {
		return nil
	}

	if valor < nodo.valor {
		nodo.izquierda = eliminarNodo(nodo.izquierda, valor)
	} else if valor > nodo.valor {
		nodo.derecha = eliminarNodo(nodo.derecha, valor)
	} else {
		// Caso 1: Sin hijos
		if nodo.izquierda == nil && nodo.derecha == nil {
			return nil
		}

		// Caso 2: Un solo hijo
		if nodo.izquierda == nil {
			return nodo.derecha
		}
		if nodo.derecha == nil {
			return nodo.izquierda
		}

		// Caso 3: Dos hijos
		sucesor := minimoRecursivo(nodo.derecha)
		nodo.valor = sucesor.valor
		nodo.derecha = eliminarNodo(nodo.derecha, sucesor.valor)
	}
	return nodo
}

// Buscar el nodo con el valor más chico del subarbol derecho (Sucesor Inorden)
func (a *ABB) minimo(nodo *Node) int {
	if nodo == nil {
		return 0
	}
	if nodo.izquierda == nil {
		return nodo.valor
	}
	return a.minimoRecursivo(nodo.izquierda)
}

// Contar todos los nodos de un ABB
func contarNodos(n *Node) int {
	if n == nil {
		return 0
	}
	return 1 + contarNodos(n.izquierda) + contarNodos(n.derecha)
}
