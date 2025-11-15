# CPP_08
Templated containers, iterators, algorithms



# Span

Develop a Span class that is capable of storing a maximum of $N$ integers. $N$ shall be an unsigned integer variable and will constitute the sole parameter passed to the constructor. This class is to be furnished with a member function denominated addNumber() whose purpose is to append a single integer to the Span. This function shall serve to populate the container.

Any attempt to add a new element if there are already N elements stored should throw an exception.

Next, implement two member functions: 

shortestSpan() o **Mínima Diferencia Absoluta ($\Delta_{min}$) en un Conjunto Ordenado $S'$:**

```math
\Delta_{min} = \min_{1 \le i < n} \{ a'_{i+1} - a'_i \}
```

longestSpan() = Max - Min

They shall, respectively, ascertain and return either the shortest span or the longest span (or distance, if one prefers that nomenclature) existing between all of the numbers that have been stored.

Should there be no numbers stored, or if there is only a single number, no span may be legitimately determined. In such a circumstance, an exception must be thrown.


### STL usage (Subject instructions)
You will notice that, in this module, the exercises can be solved WITHOUT the standard Containers and WITHOUT the standard Algorithms.
However, using them is precisely the goal of this Module.
You must use the STL — especially the Containers (vector/list/map/and so forth)
and the Algorithms (defined in header <algorithm>) — whenever they are appropriate.
Moreover, you should use them as much as you can.

### Custom versus STL
My Span class is designed to update the minimum and maximum values with each insertion. I elected this approach to ensure a rapid response when answering the longestSpan() query. 

The reasoning for this design choice is that the standard algorithm for calculating the minimum or maximum element typically iterates through all elements. 

A time comparison conducted between the two methods affirms that my custom Span implementation yields a faster result than utilising the STL calls to min_element() and max_element(). 

Conversely, the process of inserting ten thousand ($\text{10,000}$) elements into my class demands more time than the execution of the standard vector::insert() member function.

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

The MutantStack is to be defined as an iterable stack structure.

The crux of this exercise lies in the comprehension that the standard std::stack class possesses a protected attribute. This protected attribute is, in fact, the underlying container that supports the stack's functionality. Since this underlying container is directly accessible (via inheritance or a similar mechanism), we are thus able to retrieve its iterators.

A stack is fundamentally a container adaptor designed to modify a Sequence Container (such as a vector, list, or deque) to offer a Last-In, First-Out (LIFO) data structure. The default container selected for this adaptation is the deque.
```c++
template <class T, class Container = deque<T> > class stack;
```


|Contenedor	|Estructura interna	|Acceso a elementos|	Inserción/Borrado|	Coste de memoria|	Casos de uso|
|-----------|-------------------|------------------|---------------------|------------------|---------------|
|std::vector|	Array dinámico contiguo	|O(1) acceso aleatorio con []	|O(1) amortizado al final, O(n) al inicio o medio	|Bajo (solo datos + posible capacidad extra)	|Ideal para colecciones con acceso rápido y pocas inserciones fuera del final|
|std::deque	|Bloques de memoria contiguos en segmentos|	O(1) acceso aleatorio, aunque menos cache-friendly que vector|	O(1) en ambos extremos, O(n) en el medio|	Moderado (estructura de bloques)	|Útil cuando necesitas acceso rápido y operaciones en ambos extremos|
|std::list	|Lista doblemente enlazada (nodos)|	O(n) para acceder a un elemento|	O(1) en cualquier posición si tienes el iterador|	Alto (punteros extra por nodo)	|Adecuado para muchas inserciones/borrados en posiciones arbitrarias|


As the stack is defined as a class template, it retains the capacity to be instantiated (or declared) using a variety of different containers.

```c++
template <typename T, typename Container = std::deque<T> >
class pila_deque : public std::stack<T, Container> 
{};

template <typename T, typename Container = std::deque<T> >
class pila_vector : public std::stack<T, std::vector<T> > 
{};
```
