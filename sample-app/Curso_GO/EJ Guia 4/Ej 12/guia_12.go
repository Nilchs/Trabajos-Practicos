package main

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

func main() {
	arbol := &AVL{nil}
	arbol.raiz = insertar(arbol.raiz, 9780345391803)
	arbol.raiz = insertar(arbol.raiz, 9780131103627)
	arbol.raiz = insertar(arbol.raiz, 9780321573513)
	arbol.raiz = insertar(arbol.raiz, 9780596009205)
	arbol.raiz = insertar(arbol.raiz, 9780134190440)
	arbol.raiz = insertar(arbol.raiz, 9780262033848)

}
