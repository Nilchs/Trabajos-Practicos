package main

import "fmt"

type Nodo struct {
	valor     int // ID del turno
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

// Para punto B
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

func eliminarTurno(n *Nodo, valor int) *Nodo {
	if n == nil {
		return n
	}

	if valor < n.valor {
		n.izquierda = eliminarTurno(n.izquierda, valor)
	} else if valor > n.valor {
		n.derecha = eliminarTurno(n.derecha, valor)
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
			n.derecha = eliminarTurno(n.derecha, temp.valor)
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

func minimo(n *Nodo) *Nodo {
	actual := n
	for actual.izquierda != nil {
		actual = actual.izquierda
	}
	return actual
}

// Para punto C
func imprimirTurnos(n *Nodo) {
	if n != nil {
		imprimirTurnos(n.izquierda)
		fmt.Printf("Turno %d\n", n.valor)
		imprimirTurnos(n.derecha)
	}
}

func main() {
	var raiz *Nodo

	turnos := []int{
		600,
		900,
		720,
		660,
		840,
		780,
		1020,
	}

	for _, turnos := range turnos {
		raiz = insertar(raiz, turnos)
	}

	fmt.Println("Turnos agendados en el AVL.")

	// Ejemplo de cancelar turnos
	eliminar1 := 720
	raiz = eliminarTurno(raiz, eliminar1)

	eliminar2 := 600
	raiz = eliminarTurno(raiz, eliminar2)

	fmt.Println("Turnos cancelados en el AVL.")

	fmt.Println("Turnos vigentes:")
	imprimirTurnos(raiz)

	// Mostrar el turno más próximo
	fmt.Println("Turno más próximo:", minimo(raiz).valor)
}

/*
Para punto D
i. Si se utiliza un ABB sin balanceo:
- Problema: el árbol puede desbalancearse fácilmente si los turnos se cargan en orden creciente o decreciente (por ejemplo: 600, 660, 720, 780…).
- Impacto:
	- El árbol se convierte en una lista enlazada.
	- Las operaciones de búsqueda, inserción y eliminación se degradan a O(n) en el peor caso.
	- Tiempo de respuesta aumenta cuanto más crece la agenda del día.
- Ejemplo: Buscar el turno 1020 podría requerir recorrer 6 nodos en un árbol sin balanceo.

ii. Si se utiliza un AVL balanceado:
- Ventaja: el árbol mantiene siempre el equilibrio, sin importar el orden de inserción de los turnos.
- Impacto:
	- Las operaciones de búsqueda, inserción y eliminación se realizan en O(log n).
	- Garantiza alta eficiencia incluso con muchos turnos.
	- Mantiene el sistema ágil, predecible y escalable.
- Ejemplo: Buscar el mismo turno 1020 requiere como máximo 3 pasos en un AVL balanceado.
*/

/*
Para punto E
Usar un AVL en un sistema de turnos médicos garantiza que el sistema se mantenga rápido, ordenado y eficiente sin importar
cuántos turnos se carguen, ni en qué orden. Es la mejor elección frente a un ABB no balanceado,
especialmente cuando hay inserciones dinámicas y búsquedas frecuentes.
*/
