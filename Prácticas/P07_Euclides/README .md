# Práctica 7 - Cifrado Euclides

[Cifrado Euclides](https://github.com/MarianaGU18/Criptografia_S2026-1/tree/main/Pr%C3%A1cticas/P07_Euclides)

### 👥 Colaboradores

- **Chagoya González Leonardo**
- **Camacho Garduño Miguel Ángel**
- **Gómez Urbano Mariana**
- **Hernández Nava Luisa Fernanda**
- **Rosas Meza Isaías**
- **Vieyra Márquez Andrea**

## ¿Qué es lo que hicimos?

Implementamos el **algoritmo extendido de Euclides** para calcular el máximo común divisor (mcd) de dos números y obtener los coeficientes \(x\) e \(y\) que cumplen la ecuación:

\[
ax + by = \text{mcd}(a, b)
\]

Además, utilizamos estos resultados como base para el **cifrado y descifrado tipo Euclides**, que se relaciona con la criptografía de clave pública y modular.

## ¿Cómo lo hicimos?

1. Creamos la función `extended_gcd_with_steps(a, b)` que:
   - Aplica el algoritmo extendido de Euclides de manera recursiva.
   - Devuelve el mcd de `a` y `b`.
   - Devuelve los coeficientes `x` e `y` de la ecuación `ax + by = mcd(a, b)`.
2. Mostramos los pasos de cada división para entender cómo se obtiene el resultado.
3. Aplicamos el algoritmo para cifrar y descifrar mensajes usando operaciones modulares.

## ¿Por qué lo hicimos?

- Para **entender los fundamentos matemáticos** detrás de la criptografía.
- Para practicar el uso de **algoritmos recursivos** y su aplicación en seguridad informática.
- Para aprender a **verificar resultados** mediante ecuaciones lineales y operaciones modulares.

## ¿Cómo usar el código?

1. Clonar o descargar el repositorio del enlace proporcionado.
2. Ejecutar el archivo `Euclides.ipynb` en Google Colab o Jupyter Notebook.
3. Definir los valores de `a` y `b` según tus necesidades para calcular el mcd y los coeficientes.

### **Probar cifrado**

Puedes utilizar la función `extended_gcd_with_steps` para obtener el inverso modular, que es útil para cifrar con técnicas como el cifrado multiplicativo:

```python
# Ejemplo de cifrado multiplicativo
m = 123  # mensaje
n = 26   # módulo
_, x, _ = extended_gcd_with_steps(7, n)  # 7 es la clave
if x < 0:
    x += n  # ajustar el inverso a positivo
c = (m * x) % n
print(f"Mensaje cifrado: {c}")
```

### **Probar descifrado**

Para descifrar, se usa el inverso modular nuevamente:

```python
# Descifrado multiplicativo
c = 19  # mensaje cifrado
m = (c * 7) % n  # 7 es la clave original
print(f"Mensaje descifrado: {m}")
```
