# Práctica 3 - Cifrado Playfair

[Código fuente de Cifrado Playfair](https://github.com/MarianaGU18/Criptografia_S2026-1/tree/main/Pr%C3%A1cticas/P03_CifradoPlayfair)

### 👥 Colaboradores

- **Chagoya González Leonardo**
- **Camacho Garduño Miguel Ángel**
- **Gómez Urbano Mariana**
- **Hernández Nava Luisa Fernanda**
- **Rosas Meza Isaías**
- **Vieyra Márquez Andrea**

## ¿Qué es lo que hicimos?

Este programa implementa en Python el cifrado Wheatstone o Playfair completo con funciones de cifrado y descifrado y un menú de consola para elegir la operación (cifrar/descifrar).

## ¿Cómo lo hicimos?

- Normalización: el texto y la clave se pasan a minúsculas y se eliminan espacios para procesar solo letras.

- Generación de la tabla 5×5: se construye el key table insertando primero las letras de la clave (sin repetir) y luego el resto del alfabeto; la letra 'j' se trata como 'i' (se marca para saltarla).

- Preparación del texto: se asegura que la longitud sea par (si es impar se añade 'z'). (Nota: el código no inserta relleno para pares de letras iguales dentro de un dígrafo, solo rellena al final si la longitud es impar)

- Reglas del algoritmo: para cada dígrafo se buscan posiciones en la tabla y se aplican las tres reglas clásicas — misma fila (desplazar columna +1 / −1), misma columna (desplazar fila +1 / −1) o formar rectángulo (intercambiar columnas). Se implementan versiones simétricas para cifrar y descifrar.

## ¿Por qué lo hicimos?

- Consistencia/normalización: pasar a minúsculas y quitar espacios simplifica la búsqueda en la tabla y garantiza resultados reproducibles.

- Tabla 5×5 y unión i/j: Playfair clásico usa 25 casillas; unir i/j y llenar la tabla con la clave evita duplicados y define el alfabeto del cifrado.

- Reglas del dígrafo: aplicar las reglas de fila/columna/rectángulo es exactamente la mecánica del algoritmo Playfair — permite cifrar/descifrar sin depender de sustituciones por letra única.

## Cómo usar el código

Al ejecutar el programa, se presentará un menú donde puedes elegir entre cifrar o descifrar un mensaje.

1. **=== Práctica: Wheastone/Playfair (Python) ===**

   - `1`: Cifrar un mensaje.

   - `2`: Descifrar un mensaje.

     **Seleccione una opción (1 o 2):**

2. **Ingresa la clave:** Debe contener solo caracteres alfabéticos. **No se admiten las vocales acentuadas.**
3. **Ingresa el texto a cifrar:** Debe contener solo caracteres alfabéticos, admite acentuación, pero de preferencia no colocar.
4. **Resultado:** El programa imprimirá el texto cifrado o descifrado según la opción seleccionada.

### **Probar cifrado**

1. Ejecutar el programa `/Cifrado-Playfair.py`

2. Seleccionar la opción `1` (Cifrar)

3. Ingresar la llave, por ejemplo: `loco`

4. Ingresar el texto, por ejemplo: `Este es mi noveno semestre en la carrera`

5. Se mostrará el texto cifrado, por ejemplo: `frrgfrnkkawdkarfkftuwkgkobabtokwby`

### **Probar descifrado**

1. Ejecutar el programa `/Cifrado-Playfair.py`
2. Seleccionar la opción `2` (Descifrar)
3. Ingresar la llave, por ejemplo: `loco`
4. Ingresar el texto cifrado: `frrgfrnkkawdkarfkftuwkgkobabtokwby`
5. Se mostrará el texto descifrado: `esteesminovenosemestreenlacarreraz`
