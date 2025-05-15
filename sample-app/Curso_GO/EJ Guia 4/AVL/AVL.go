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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
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

// Encuentra el nodo con el valor mínimo en el subárbol
func minimo(n *Nodo) *Nodo {
	actual := n
	for actual.izquierda != nil {
		actual = actual.izquierda
	}
	return actual
}

// Eliminación con rebalanceo
func eliminar(n *Nodo, valor int) *Nodo {
	if n == nil {
		return n
	}

	if valor < n.valor {
		n.izquierda = eliminar(n.izquierda, valor)
	} else if valor > n.valor {
		n.derecha = eliminar(n.derecha, valor)
	} else {
		// Nodo con uno o ningún hijo
		if n.izquierda == nil || n.derecha == nil {
			var temp *Nodo
			if n.izquierda != nil {
				temp = n.izquierda
			} else {
				temp = n.derecha
			}

			if temp == nil {
				n = nil
			} else {
				*n = *temp
			}
		} else {
			// Nodo con dos hijos: reemplazar con mínimo del derecho
			temp := minimo(n.derecha)
			n.valor = temp.valor
			n.derecha = eliminar(n.derecha, temp.valor)
		}
	}

	if n == nil {
		return n
	}

	actualizarAltura(n)
	balance := factorEquilibrio(n)

	// Casos de rebalanceo igual que en inserción
	if balance > 1 && factorEquilibrio(n.derecha) >= 0 {
		return rotarIzquierda(n)
	}
	if balance > 1 && factorEquilibrio(n.derecha) < 0 {
		n.derecha = rotarDerecha(n.derecha)
		return rotarIzquierda(n)
	}
	if balance < -1 && factorEquilibrio(n.izquierda) <= 0 {
		return rotarDerecha(n)
	}
	if balance < -1 && factorEquilibrio(n.izquierda) > 0 {
		n.izquierda = rotarIzquierda(n.izquierda)
		return rotarDerecha(n)
	}

	return n
}
