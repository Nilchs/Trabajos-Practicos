package main

type Node struct {
	valor     int
	izquierda *Node
	derecha   *Node
}

type ABB struct {
	raiz *Node
}

// Generadores

func vacio() *ABB {
	nuevo := new(ABB)
	nuevo.raiz = nil
	return nuevo
}

func a_partir_de(secuencia []int) *ABB {
	nuevo := new(ABB)
	nuevo.raiz = nil
	for i := 0; i < len(secuencia); i++ {

	}
	return nuevo
}

// Observadores básicos

func (a *ABB) es_vacio() bool {
	if a.raiz == nil {
		return true
	}
	return false
}

func (a *ABB) cantidadDeNodos() int {
	if a.es_vacio() {
		return 0
	}
	return a.cantidadDeNodosRecursivo(a.raiz)
}

func (a *ABB) cantidadDeNodosRecursivo(nodo *Node) int {
	if nodo == nil {
		return 0
	}
	return 1 + a.cantidadDeNodosRecursivo(nodo.izquierda) + a.cantidadDeNodosRecursivo(nodo.derecha)
}

func maximo(a *ABB) int {
	if a.es_vacio() {
		return 0
	}
	return a.maximoRecursivo(a.raiz)
}

func (a *ABB) maximoRecursivo(nodo *Node) int {
	if nodo == nil {
		return 0
	}
	if nodo.derecha == nil {
		return nodo.valor
	}
	return a.maximoRecursivo(nodo.derecha)
}

func (abb *ABB) MinimoRec() int {
	nodo := minimoRecursivo(abb.raiz)

	if nodo == nil {
		return 0
	}
	return nodo.valor
}

func minimoRecursivo(nodo *Node) *Node {
	// Caso base: si el nodo es nil, retornar nil
	if nodo == nil || nodo.izquierda == nil {
		return nodo
	}
	// Caso recursivo: si el nodo no es nil, seguir buscando en la izquierda
	return minimoRecursivo(nodo.izquierda)
}

func (a *ABB) pertenece(valor int) bool {
	if a.es_vacio() {
		return false
	}
	return a.perteneceRecursivo(a.raiz, valor)
}

func (a *ABB) perteneceRecursivo(nodo *Node, valor int) bool {
	if nodo == nil {
		return false
	}
	if nodo.valor == valor {
		return true
	}
	if valor < nodo.valor {
		return a.perteneceRecursivo(nodo.izquierda, valor)
	} else {
		return a.perteneceRecursivo(nodo.derecha, valor)
	}
} // Comparaciones realizadas en el peor caso: O(n) donde n es la cantidad de nodos del arbol.

// Otras operaciones

func (a *ABB) insertar(valor int) {
	if a.es_vacio() {
		a.raiz = new(Node)
		a.raiz.valor = valor
		a.raiz.izquierda = nil
		a.raiz.derecha = nil
	} else {
		a.raiz.insertarEnNodo(valor)
	}
}

func (n *Node) insertarEnNodo(valor int) {
	if n == nil {
		return
	}
	if valor < n.valor {
		if n.izquierda == nil {
			n.izquierda = &Node{valor: valor, izquierda: nil, derecha: nil}
		} else {
			n.izquierda.insertarEnNodo(valor)
		}
	} else if valor > n.valor {
		if n.derecha == nil {
			n.derecha = &Node{valor: valor, izquierda: nil, derecha: nil}
		} else {
			n.derecha.insertarEnNodo(valor)
		}
	}
}

func (a *ABB) eliminar(valor int) {
	if a.es_vacio() {
		return
	}
	a.raiz = a.raiz.eliminarEnNodo(valor)
}

func (n *Node) eliminarEnNodo(valor int) *Node {
	if n == nil {
		return nil
	}
	if valor < n.valor {
		n.izquierda = n.izquierda.eliminarEnNodo(valor)
	} else if valor > n.valor {
		n.derecha = n.derecha.eliminarEnNodo(valor)
	} else {
		if n.izquierda == nil {
			return n.derecha
		} else if n.derecha == nil {
			return n.izquierda
		}
		minimo := MinimoRec(n.derecha)
		n.valor = minimo
		n.derecha = n.derecha.eliminarEnNodo(minimo)
	}
	return n
}
