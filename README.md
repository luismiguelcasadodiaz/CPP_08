# CPP_08
Templated containers, iterators, algorithms



# Span

Develop a Span class that can store a maximum of N integers. N is an unsigned int variable and will be the only parameter passed to the constructor.
This class will have a member function called addNumber() to add a single number
to the Span. It will be used in order to fill it. 

Any attempt to add a new element if there are already N elements stored should throw an exception.

Next, implement two member functions: 

shortestSpan() o **Mínima Diferencia Absoluta ($\Delta_{min}$) en un Conjunto Ordenado $S'$:**

```math
\Delta_{min} = \min_{1 \le i < n} \{ a'_{i+1} - a'_i \}
```

longestSpan() = Max - Min

They will respectively find out the shortest span or the longest span (or distance, if you prefer) between all the numbers stored, and return it. 

If there are no numbers stored, or only one, no span can be found. Thus, throw an exception.


### STL usage (Subject instructions)
You will notice that, in this module, the exercises can be solved WITHOUT the standard Containers and WITHOUT the standard Algorithms.
However, using them is precisely the goal of this Module.
You must use the STL — especially the Containers (vector/list/map/and so forth)
and the Algorithms (defined in header <algorithm>) — whenever they are appropriate.
Moreover, you should use them as much as you can.

### Custom versus STL
My span class updates min and max in each insert. I did this to return a fast answers to longestspan() question.

I did it in such way cause the algorithm of MIN/MAX element loops all elements to calculate it.

A time comparison of both methods states that my custom span is faster than STL call to min_element() and max_element().

But in the opposite side, mi 10 000 elements insert process takes longer than the vector.insert() member.

This are the results.

```bash
Shortest span: 0
Longest span: 99984
Custom insert Time : 0.000177s
Custom Span   Time : 0.000002s
Shortest span: 0
Longest span: 99984
STL    insert Time : 0.000003s
STL    Span   Time : 0.000221s

```

# MutantStack

A MutantStack is an iterable stack. 

The trick in this exercise is to know that class stack has a protected atribute.
This protected attribute is the container that supports the stack.
As the container is accessible we can get their iterators.

A stack is a container adaptor that adapts a `Sequencecontainer` (vector, list or deque) to provide a LIFO data structure.

Default container to adapt is deque,
```c++
template <class T, class Container = deque<T> > class stack;
```


|Contenedor	|Estructura interna	|Acceso a elementos|	Inserción/Borrado|	Coste de memoria|	Casos de uso|
|-----------|-------------------|------------------|---------------------|------------------|---------------|
|std::vector|	Array dinámico contiguo	|O(1) acceso aleatorio con []	|O(1) amortizado al final, O(n) al inicio o medio	|Bajo (solo datos + posible capacidad extra)	|Ideal para colecciones con acceso rápido y pocas inserciones fuera del final|
|std::deque	|Bloques de memoria contiguos en segmentos|	O(1) acceso aleatorio, aunque menos cache-friendly que vector|	O(1) en ambos extremos, O(n) en el medio|	Moderado (estructura de bloques)	|Útil cuando necesitas acceso rápido y operaciones en ambos extremos|
|std::list	|Lista doblemente enlazada (nodos)|	O(n) para acceder a un elemento|	O(1) en cualquier posición si tienes el iterador|	Alto (punteros extra por nodo)	|Adecuado para muchas inserciones/borrados en posiciones arbitrarias|


As stack is a class template it can be instantiated wiht different containerd

```c++
template <typename T, typename Container = std::deque<T> >
class pila_deque : public std::stack<T, Container> 
{};

template <typename T, typename Container = std::deque<T> >
class pila_vector : public std::stack<T, std::vector<T> > 
{};
```