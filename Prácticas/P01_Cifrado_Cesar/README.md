# Práctica 1 - Cifrado César con Ñ y acentos (ASCII extendido)

[Código fuente de Cifrado César con Ñ y acentos](https://github.com/MarianaGU18/Criptografia_S2026-1/blob/main/Pr%C3%A1cticas/P01_Cifrado_Cesar/cifradoCesar.c)

### 👥 Colaboradores

- **Chagoya González Leonardo**
- **Camacho Garduño Miguel Ángel**
- **Gómez Urbano Mariana**
- **Hernández Nava Luisa Fernanda**
- **Rosas Meza Isaías**
- **Vieyra Márquez Andrea**

## ¿Qué es lo que hicimos?

Este programa implementa el Cifrado César en C, permitiendo el cifrado y descifrado de textos que incluyen la letra Ñ y vocales acentuadas en ASCII extendido, preservando caracteres no alfabéticos.

## ¿Cómo lo hicimos?

- Se definieron dos arreglos (`ALFABETO_MAY`, `ALFABETO_MIN`) con 32 símbolos cada uno (las 27 letras del alfabeto español + 5 vocales acentuadas) usando códigos ASCII extendidos para incluir Ñ y acentos.

- Se implementó `codificarCaracter` para obtener el índice de una letra en el alfabeto y `decodificarPosicion` para convertir un índice a carácter.

- Las funciones `cifrarCesar` y `descifrarCesar` aplican desplazamiento modular `(pos ± llave) % LONGITUD_ALFABETO`, preservando mayúsculas/minúsculas y copiando literalmente caracteres no encontrados.

La interfaz por consola utiliza `fgets` para leer texto, `scanf` para seleccionar opciones, y valida que la llave esté en el rango `1–31`.

## ¿Por qué lo hicimos?

- Incluir Ñ y acentos garantiza que el algoritmo funcione correctamente con texto en español.
- Usar índices y aritmética modular evita desbordes y permite el “recorrido circular” del alfabeto.
- Mantener caracteres no alfabéticos facilita usar frases, signos y espacios sin alterar su formato.
- La validación de la llave evita valores fuera del tamaño del alfabeto y errores en el cifrado/descifrado.

## Cómo usar el código

Al ejecutar el programa, se presentará un menú donde puedes elegir entre cifrar o descifrar un mensaje.

1. **Elige una opción:**

   - `1`: Cifrar un mensaje.

   - `2`: Descifrar un mensaje.

2. **Ingresa el texto:** Debe contener solo caracteres alfabéticos, incluidos `Ñ` y vocales acentuadas.
3. **Ingresa la llave:** Debe ser un número entre `1` y `31`. Este número define el desplazamiento en el cifrado César.
4. **Resultado:** El programa imprimirá el texto cifrado o descifrado según la opción seleccionada.

### **Probar cifrado**

1. Ejecutar el programa `./cifradoCesar`

2. Seleccionar la opción `1` (Cifrar)

3. Ingresar el texto, por ejemplo: `HOLA MUNDO`

4. Ingresar la llave, por ejemplo: `3`

5. Se mostrará el texto cifrado, por ejemplo: `KRÑD OXPGR`

### **Probar descifrado**

1. Ejecutar el programa `./cifradoCesar`
2. Seleccionar la opción `2` (Descifrar)
3. Ingresar el texto cifrado, por ejemplo: `KRÑD OXPGR`
4. Ingresar la misma llave usada en el cifrado, por ejemplo: `3`
5. Se mostrará el texto descifrado: `HOLA MUNDO`
