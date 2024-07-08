# Primer Final de Lenguaje de Programación 3

Este repositorio contiene las soluciones para el primer final de la materia Lenguaje de Programación 3 (LP3), impartida por el [Gustavo Arsenio Sosa Cataldo](https://grado.pol.una.py/user/view.php?id=16412&course=6620). Se divide en dos directorios principales, cada uno correspondiente a uno de los temas propuestos en el final.

## Estructura del Repositorio

El repositorio está organizado en dos directorios principales:

- `tm1/`: Contiene la solución al Tema 1.

- `tm2/`: Contiene dos programas relacionados con el Tema 2.

## Instalación

Para clonar este repositorio y compilar los programas (suponiendo un ambiente Unix/Linux), siga los siguientes pasos:

```bash
git clone https://github.com/seb5433/primerFinalLP3.git
cd primerFinalLP3 

# Para compilar el Tema 1
cd tm1
gcc -o programa *.c

# Para compilar el Tema 2
cd ../tm2
gcc -o programa *.c
```

## Uso

### Tema 1

Para ejecutar el programa correspondiente al Tema 1, navegue hasta el directorio `tm1` y ejecute el siguiente comando, reemplazando  `<array_de_enteros>` por el arreglo de enteros a utilizar para el cálculo de factorial:

```bash
./programa <array_de_enteros>
```

### Tema 2

Para ejecutar el programa correspondiente al Tema 2, navegue hasta el directorio `tm2` y ejecute el siguiente comando, reemplazando  `<numero_a_buscar>` por el numero que desea buscar y `numero_de_hilos_a_generar`por número de hilos que desea generar para la búsqueda:

```bash
./programa <numero_a_buscar> <numero_de_hilos_a_generar>
```

## Integrantes
- [Kyara Popov Araujo](https://grado.pol.una.py/user/view.php?id=23845&course=6620)
- [Johana Mabel Bareiro](https://grado.pol.una.py/user/view.php?id=18639&course=6620)
- [Sebastian Alvarez](https://grado.pol.una.py/user/view.php?id=23677&course=6620)
