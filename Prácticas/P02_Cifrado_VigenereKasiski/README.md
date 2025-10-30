# Práctica 2 - Cifrado Vigenere Kasiski

[Cifrado Vigenere Kasiski](https://github.com/MarianaGU18/Criptografia_S2026-1/tree/main/Pr%C3%A1cticas/P02_Cifrado_VigenereKasiski)

### 👥 Colaboradores

- **Chagoya González Leonardo**
- **Camacho Garduño Miguel Ángel**
- **Gómez Urbano Mariana**
- **Hernández Nava Luisa Fernanda**
- **Rosas Meza Isaías**
- **Vieyra Márquez Andrea**

## ¿Qué es lo que hicimos?

En esta práctica implementamos en **Python** dos herramientas criptográficas:

1. **Cifrado y descrifrado con el algoritmo de Vignère**, la cual, utiliza una clave de letras para realizar un cifrado polialfabético.

2. **Análisis de Kasiski**, una técnica de criptoanálisis que permite estimar la longitud de la clave del cifrado de **Vignère** a partir de **patrones repetidos** en el texto cifrado.

## NOTA

<div style="display: flex; align-items: center;">
  <img src="https://i.pinimg.com/474x/06/21/45/062145f96a85addce364be26cfb46159.jpg" alt="Mi imagen" style="width:100px; margin-right:20px;" />
  <div>
    <ul>
        <li> <b>Cifrado Polialfafabético</b>:
            Es un tipo de cifrado que utiliza más de un alfabeto para cifrar el mensaje, cambiando la sustitución de letras según una clave.
        </li>
        <li> <b>Criptoanálisis</b>: Estudio y aplicación de métodos para descubrir información cifrada sin conocer la clave secreta. 
        </li>
    </ul>

  </div>
</div>

---

## ¿Cómo lo hicimos?

1. **Diseño del cifrado Vigenère**

   - Se definió un **alfabeto de referencia (A–Z)** y funciones auxiliares para obtener índices y letras.
   - Se desarrollaron funciones para **cifrar (`encrypt_vigenere`)** y **descifrar (`decrypt_vigenere`)** texto, avanzando la clave solo en las posiciones alfabéticas.
   - Se añadió manejo de **mayúsculas/minúsculas** y se preservaron los caracteres no alfabéticos (espacios, signos, números).

2. **Implementación del análisis de Kasiski**

   - Se construyó una versión **filtrada del texto cifrado** que solo contiene letras mayúsculas.
   - Se buscaron **subcadenas repetidas** de longitud 3 a 5.
   - Para cada repetición se calcularon **distancias** entre ocurrencias.
   - Se analizó la **frecuencia de divisores comunes** en las distancias, que pueden corresponder a posibles longitudes de la clave.
   - Finalmente, el programa **sugiere longitudes probables de clave**, que pueden verificarse descifrando con hipótesis.

3. **Interfaz de usuario**
   - Se implementaron **menús interactivos** que permiten elegir entre:
     - Cifrar o descifrar con Vigenère.
     - Ejecutar el examen de Kasiski sobre un texto cifrado.

## ¿Por qué lo hicimos?

Este proyecto permite:

- Comprender cómo **funciona un cifrado clásico** y sus limitaciones.
- Aplicar un **ataque criptoanalítico real (Kasiski)** para romperlo.
- Demostrar la importancia de las **claves largas** y de los métodos de cifrado modernos frente a los antiguos.

## ¿Cómo usar el código?

### Ejecutar el programa

Guarda el archivo como `vigenere_kasiski.py` y ejecútalo en terminal o en Google Colab:

```bash
python3 vigenere_kasiski.py
```

### **Probar cifrado**

Para cifrar un texto con el algoritmo de **Vigenère**, el programa pedirá:

1. El **texto original** que deseas cifrar.
2. La **clave** (formada solo por letras, sin espacios).

El resultado será el texto cifrado utilizando el método polialfabético.

**Ejemplo:**

```python
Texto original: ATAQUENALAMANECER
Clave: SOL
→ Texto cifrado: SFLDIEPNSRPAEQEVS
```

### **Probar descifrado**

Para descifrar un texto cifrado con Vigenère, el programa pedirá:

1. El **texto cifrado** que deseas descifrar.
2. La **misma clave** utilizada durante el cifrado.

El resultado será el texto original descifrado correctamente.

**Ejemplo:**

```python
Texto cifrado: SFLDIEPNSRPAEQEVS
Clave: SOL
→ Texto descifrado: ATAQUENALAMANECER
```

> Si se introduce una clave incorrecta, el texto resultante será ilegible, demostrando la importancia de conocer la clave correcta.

---

### **Probar análisis de Kasiski**

El análisis de Kasiski permite estimar la **longitud de la clave** de un texto cifrado con Vigenère, buscando **patrones repetidos** y calculando distancias entre ellos.

**Pasos para usarlo en el programa:**

1. Introduce el **texto cifrado** que deseas analizar.
2. El programa generará una versión filtrada del texto (solo letras mayúsculas).
3. Buscará **subcadenas repetidas** de longitud 3 a 5.
4. Calculará las **distancias** entre repeticiones y analizará sus divisores comunes.
5. Mostrará las **longitudes de clave más probables**.

**Ejemplo:**

```python
Texto cifrado: LXFOPVEFRNHR
→ Subcadenas repetidas encontradas: ['LXF', 'FOP', 'EFR']
→ Distancias entre repeticiones: [6, 12]
→ Posibles longitudes de clave sugeridas: [3, 6]
```

> Con esta información, se puede intentar descifrar el mensaje usando claves de las longitudes sugeridas, facilitando el criptoanálisis del cifrado de Vigenère.

**Nota:** El análisis es más efectivo con textos largos, donde los patrones repetidos aparecen con mayor frecuencia.
