# Práctica 6 - Cifrado Hill

[Cifrado Hill](https://github.com/MarianaGU18/Criptografia_S2026-1/tree/main/Pr%C3%A1cticas/P06_Cifrado_Hill)

### 👥 Colaboradores

- **Chagoya González Leonardo**
- **Camacho Garduño Miguel Ángel**
- **Gómez Urbano Mariana**
- **Hernández Nava Luisa Fernanda**
- **Rosas Meza Isaías**
- **Vieyra Márquez Andrea**

## ¿Qué es lo que hicimos?

En esta práctica implementamos en **Python** el **Cifrado de Hill**, un cifrado polialfabético basado en **matrices y álgebra lineal**:

1. **Cifrado Hill**:  
   Utiliza una **matriz como clave** para transformar bloques de letras en números y aplicar operaciones lineales módulo 26.

2. **Criptoanálisis Hill**:  
   Implementa la **inversa de la matriz clave** para descifrar el mensaje, mostrando cómo se puede recuperar el texto original a partir del cifrado si se conoce la clave.

## ¿Cómo lo hicimos?

1. **Definición de la clave y módulo**

   - Se definieron matrices clave de tamaños **5x5, 6x6 y 7x7**.
   - Todas las operaciones se realizan módulo 26.

2. **Conversión entre letras y números**

   - `char_to_num(c)` convierte una letra a su valor numérico (`A=0, B=1, ... Z=25`).
   - `num_to_char(n)` convierte un valor numérico a su letra correspondiente.
   - Los mensajes se transforman en **vectores de tamaño n (block size)**.

3. **Operaciones matriciales**

   - Cálculo de **determinante**, **cofactores**, **adjunta** y **transpuesta**.
   - Cálculo de la **inversa modular de la matriz clave** para el descifrado.
   - Multiplicación de bloques por la matriz clave para cifrar y por la inversa para descifrar.

4. **Funciones de cifrado y descifrado**

   - `encrypt(text, key)` → cifra el mensaje usando la matriz clave.
   - `decrypt(cipher, key)` → descifra el mensaje usando la inversa modular de la matriz.

5. **Interfaz de usuario**
   - Menú que permite seleccionar **el tamaño de la clave** (5, 6 o 7).
   - Solicita el **mensaje** a cifrar.
   - Muestra:
     - Texto original
     - Texto cifrado
     - Texto descifrado aplicando criptoanálisis.

## ¿Por qué lo hicimos?

Este proyecto permite:

- Comprender cómo un **cifrado polialfabético basado en matrices** puede codificar un mensaje.
- Aplicar **conceptos de álgebra lineal** y operaciones módulo para el cifrado.
- Ver cómo la **inversa de la matriz clave** permite descifrar el mensaje, demostrando la importancia de claves adecuadas y su seguridad.

## ¿Cómo usar el código?

### Ejecutar el programa

Guarda el archivo como `P006_Hill.py` y ejecútalo en terminal o en Google Colab:

```bash
python3 P006_Hill.py
```

### **Probar cifrado**

Para cifrar un mensaje con el **Cifrado Hill**, el programa pedirá:

1. Selecciona el **tamaño de la clave**: 5, 6 o 7.
2. Escribe el **mensaje a cifrar** (solo letras, el programa ignora números o símbolos).

El resultado será el **texto cifrado**, aplicando la multiplicación de cada bloque por la **matriz clave** módulo 26.

**Ejemplo:**

```
Texto original: HOLA
Clave: Matriz de 5x5 seleccionada
→ Texto cifrado: KQPO
```

> Si el mensaje no completa un bloque completo, se rellenará automáticamente con `X`.

### **Probar descifrado**

Para descifrar un mensaje cifrado con Hill, el programa pedirá:

1. Selecciona el **tamaño de la clave** que se utilizó para cifrar.
2. Escribe el **mensaje cifrado**.

El programa calculará la **inversa modular de la matriz clave** y aplicará la multiplicación para recuperar el texto original.

**Ejemplo:**

```
Texto cifrado: KQPO
Clave: Matriz de 5x5 seleccionada
→ Texto descifrado: HOLA
```

> El descifrado solo funcionará correctamente si se usa la **misma clave** que se utilizó para cifrar el mensaje.
