# Práctica 4 - Cifrado Vernam


### 👥 Colaboradores

- **Chagoya González Leonardo**
- **Camacho Garduño Miguel Ángel**
- **Gómez Urbano Mariana**
- **Hernández Nava Luisa Fernanda**
- **Rosas Meza Isaías**
- **Vieyra Márquez Andrea**

## ¿Qué es lo que hicimos?

Este programa implementa en lenguaje en C el cifrado Vernam completo con funciones de cifrado y descifrado y un menú de consola para elegir la operación (cifrar/descifrar/salir).
Así como la creación de archivos con el mensaje cifrado y la llave. 

## ¿Cómo lo hicimos?

- Entrada y limpieza del mensaje: se pide al usuario un texto, y si contiene salto de línea al final se elimina. Los caracteres no alfabéticos se mantienen sin cambios para no perder información.

- Generación de la clave: se usa rand() con srand(time(NULL)) para obtener una secuencia pseudoaleatoria de números entre 0 y 25, uno por cada carácter del mensaje. Esta clave se guarda en un archivo para poder descifrar después.
 
- Cifrado carácter por carácter: Se convierte cada letra del mensaje a mayúscula y se obtiene su posición en el alfabeto (A=0 ... Z=25). A cada posición se le suma el valor de la clave correspondiente y se aplica módulo 26.
 Finalmente el resultado se convierte nuevamente en letra ('A' + valor).

- Almacenamiento en archivos: el mensaje cifrado se guarda en mensaje_cifrado.txt junto con su longitud, y la clave se guarda en clave.txt para permitir el proceso inverso.

- Descifrado: Se leen tanto el mensaje cifrado como la clave desde archivo. Cada letra se convierte a su valor numérico y se resta la clave (con módulo 26 para mantener el rango) y el resultado se traduce de vuelta en letra mayúscula, reconstruyendo el mensaje original.

## ¿Por qué lo hicimos?

- Seguridad del mensaje: el objetivo principal es proteger la información, de modo que el texto original no pueda ser entendido sin la clave correspondiente.

- Comprender la relación entre mensaje y clave: generar una clave del mismo tamaño que el texto permite aplicar la operación carácter a carácter, reforzando la idea de que cada símbolo depende de su propio valor de clave.

- Implementar el algoritmo Vernam (OTP): este cifrado es teóricamente irrompible cuando se usa una clave verdaderamente aleatoria, del mismo tamaño que el mensaje y empleada una sola vez.

## Cómo usar el código

Al ejecutar el programa, se presentará un menú donde puedes elegir entre cifrar o descifrar un mensaje.

1. **=== CIFRADO VERNAM (OTP) ===**

   - `1`: Cifrar un mensaje.

   - `2`: Descifrar un mensaje.
  
   - `3`: Salir.

   - Seleccione una opción:

2. **Ingrese el mensaje a cifrar:** Debe contener solo caracteres alfabéticos.
3. **Archivos:** El programa creará automáticamente dos archivos, uno para el mensaje cifrado y otro para la clave, y los guardará en la carpeta donde se encuentre el programa.
4. **Vuelta al menú:** El programa mostrará nuevamente el menú para volver a seleccionar una opción, en caso de querer descifrar el mensaje, se leeran los archivos creados, en caso de volver a cifrar un mensaje, los archivos se sobreescribiran con la nueva información.
5. **Resultado:** El programa imprimirá el texto cifrado o descifrado según la opción seleccionada así como la llave.

### **Probar cifrado**

1. Ejecutar el programa `.\Cifrado_Vernam`

2. Seleccionar la opción `1` (Cifrar)

3. Ingresar el mensaje a cifrar, por ejemplo: `Hola a todos en la clase de criptografia`

4. Se mostrará la longitud del mensaje, el mensaje original y cifrado así como un texto donde indica la creación de los archivos, por ejemplo:
 - `Longitud del mensaje: 40 caracteres`
 - `Mensaje cifrado:  FTEQ K DSMCK NR WG ENLRV YP OVIWRCKVDYWE`
 - `Mensaje cifrado guardado en 'mensaje_cifrado.txt'`
 - `Clave guardada en 'clave.txt'`
5. Se regresa al menú. 

### **Probar descifrado**

1. Ejecutar el programa `.\Cifrado_Vernam`
2. Seleccionar la opción `2` (Descifrar)
3. Se leen los archivos correspondientes, se muestra el mensaje cifrado y el original y se eliminan los archivos automáticamante:
   - `Mensaje cifrado:   FTEQ K DSMCK NR WG ENLRV YP OVIWRCKVDYWE`
   - `Mensaje descifrado: HOLA A TODOS EN LA CLASE DE CRIPTOGRAFIA`
   - `Eliminando archivos utilizados...`
   - `Archivo 'clave.txt' eliminado automaticamente.`
   - `Archivo 'mensaje_cifrado.txt' eliminado automaticamente.`
5. Se regresa al menú.

