# Abstracción y Uso de Datos

Este repositorio es nuestro espacio de trabajo colaborativo para la materia impartida por el **Prof. Yventz Garduño Entzana**. Aquí organizamos de manera cronológica cada práctica y proyecto desarrollado durante el semestre.

## Autores
* **Rodrigo Yael Murata Abreu**
* **Ian Aaron Van Scoit Urtiz**

---

## Estructura del Repositorio

El repositorio se divide en tres niveles principales correspondientes a los parciales del curso:

### Primer_Parcial /
* `Proyecto_01/`  → Hola mundo
* `Proyecto_02/`  → Suma de dos valores como parámetros
* `Proyecto_03/`  → Calculadora básica (suma, resta, div, mult)
* `Proyecto_04/`  → Calculadora con 2, 0, 3 parametros (suma, resta, div, mult)
* `Proyecto_05/`  → Calculadora nueva con herencia (suma, resta, div, mult, pot, mod)
* `Proyecto_06/`  → Calculadora nueva con herencia y sobreescritura de funciones (suma, resta, div, mult)
* `Proyecto_07/`  → Creacion de tipo de dato en PE y POO
* `Proyecto_08/`  → Identificar el tamaño en PE y POO 
* `Proyecto_09/`  → Promedio
* `Proyecto_10/` → Promedio con array
* `Proyecto_11/` → Promedio con array y con puntero
* `Proyecto_12/` → Multiplicacion de matrices
* `Proyecto_13/` → Lista de personas y coches
* `Proyecto_14/` → Lista de personas con puntero al arreglo
* `Proyecto_15/` → Factorial y serie de fibonacci con funciones fibo() y fibo2()
* `Proyecto_16/` → Fractales: tríangulo de sierpinski y polvo de cantor
* **Reporte_Primer_Parcial.pdf** → Documentación detallada de cada práctica del primer parcial.
  
### Segundo_Parcial /
* `Proyecto_01/`  → Pila con arreglos (dato base)
* `Proyecto_02/`  → Pila con arreglos (nuevo tipo de dato)
* `Proyecto_03/`  → Pila con punteros (dato base)
* `Proyecto_04/`  → Pila con punteros (nuevo tipo de dato)
* `Proyecto_05/`  → Pila con librerías (dato base)
* `Proyecto_06/`  → Pila con librerías (nuevo tipo de dato)
* `Proyecto_07/`  → Cola con arreglos (dato base)
* `Proyecto_08/`  → Cola con arreglos (nuevo tipo de dato)
* `Proyecto_09/`  → Cola con punteros (dato base)
* `Proyecto_10/` → Cola con punteros (nuevo tipo de dato)
* `Proyecto_11/` → Cola con librerías (dato base)
* `Proyecto_12/` → Cola con librerías (nuevo tipo de dato)
* `Proyecto_13/` → Fila con arreglos (dato base)
* `Proyecto_14/` → Fila con arreglos (nuevo tipo de dato)
* `Proyecto_15/` → Fila con punteros (dato base)
* `Proyecto_16/` → Fila con punteros (nuevo tipo de dato)
* `Proyecto_17/` → Fila con librerías (dato base)
* `Proyecto_18/` → Fila con librerías (nuevo tipo de dato)
* `Proyecto_19/` → Ordenamiento Bubble Sort
* `Proyecto_20/` → Ordenamiento Merge Sort
* `Proyecto_21/` → Ordenamiento Quick Sort
* **Reporte_Segundo_Parcial.pdf** → Documentación detallada de cada práctica del segundo parcial.

### Tercer_Parcial /
* `Proyecto_01/`  → Archivos: Lectura y escritura de CSV.
* `Proyecto_02/`  → Archivos: Lectura y escritura de XML.
* `Proyecto_03/`  → Archivos: Lectura y escritura de TXT.
* `Proyecto_04/`  → Archivos: Lectura y escritura de JSON.
* `Proyecto_05/`  → Implementación de Grafos.
* `Proyecto_06/`  → Implementación de Digrafos.
* `Proyecto_07/`  → Implementación de Árboles.
* ... (Sucesivamente hasta completar el parcial)
* **Reporte_Tercer_Parcial.pdf** → Documentación detallada de cada práctica del tercer parcial.

---

## Contenido de cada Proyecto

Cada carpeta de proyecto está estructurada bajo un esquema de **programación modular**, conteniendo los siguientes archivos base:

* **`archivo.h`** → Definición de las interfaces, estructuras de datos y prototipos de funciones.
* **`archivo.c`** → Implementación detallada de la lógica y funciones.
* **`main.c`** → Punto de entrada del programa, encargado de la ejecución y pruebas.

---
## Guía de Instalación y Uso

### Requisitos Previos
Antes de comenzar, asegúrate de tener instalado lo siguiente en tu sistema:

* **Git:** Necesario para clonar el repositorio. [Instalar Git aquí](https://git-scm.com/).
* **Compilador C/C++:** GCC 

---

###  Pasos a seguir

#### 1.- Clonar el repositorio
Puedes clonar el repositorio usando **HTTPS** o **SSH**.

**Opción A — HTTPS:**
```bash
git clone https://github.com/AaronVanScoit/Practicas-Abstraccion_y_uso_de_datos.git
cd Practicas-Abstraccion_y_uso_de_datos
```

**Opción B — SSH:**
```bash
git clone git@github.com:AaronVanScoit/Practicas-Abstraccion_y_uso_de_datos.git
cd Practicas-Abstraccion_y_uso_de_datos
```

#### 2.- Compilación
Al ser un proyecto modular, es necesario compilar los archivos de implementación junto con el principal:

```bash
gcc main.c archivo.c -o programa
```

#### 3.-Ejecución

En **Linux/macOS**:
```bash
./programa
```

En **Windows**:
```bash
programa.exe
```
O se puede ejecutar directo desde Dev-C++)

---

## Entorno de Desarrollo

* **Sistemas Operativos:** macOS, Ubuntu y Windows
* **IDEs y Herramientas:** Dev-C++ y Visual Studio Code
* **Compilador:** GCC
* **Unidad Académica:** UPIICSA - IPN
* **Estado:** En progreso 
