#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

#define MAX_LENGTH 1000

// Función para generar números pseudoaleatorios
void generarClave(int *clave, int longitud) {
    srand(time(NULL));
    for (int i = 0; i < longitud; i++) {
        clave[i] = rand() % 26;
    }
}

// Función para cifrar el mensaje
void cifrarMensaje(char *mensaje, int *clave, char *mensajeCifrado, int longitud) {
    for (int i = 0; i < longitud; i++) {
        if (isalpha(mensaje[i])) {
            // Convertir a mayúscula y ajustar a rango 0-25
            char letra = toupper(mensaje[i]);
            int pos = letra - 'A';
            
            // Aplicar cifrado Vernam
            int nuevaPos = (pos + clave[i]) % 26;
            mensajeCifrado[i] = 'A' + nuevaPos;
        } else {
            // Mantener caracteres no alfabéticos sin cambio
            mensajeCifrado[i] = mensaje[i];
        }
    }
    mensajeCifrado[longitud] = '\0';
}

// Función para descifrar el mensaje
void descifrarMensaje(char *mensajeCifrado, int *clave, char *mensajeOriginal, int longitud) {
    for (int i = 0; i < longitud; i++) {
        if (isalpha(mensajeCifrado[i])) {
            char letra = toupper(mensajeCifrado[i]);
            int pos = letra - 'A';
            
            // Aplicar descifrado Vernam
            int nuevaPos = (pos - clave[i] + 26) % 26;
            mensajeOriginal[i] = 'A' + nuevaPos;
        } else {
            mensajeOriginal[i] = mensajeCifrado[i];
        }
    }
    mensajeOriginal[longitud] = '\0';
}

// Función para guardar mensaje cifrado en archivo
void guardarMensajeCifrado(char *mensajeCifrado, int longitud) {
    FILE *archivo = fopen("mensaje_cifrado.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo del mensaje cifrado.\n");
        return;
    }
    
    fprintf(archivo, "%d\n", longitud);
    fprintf(archivo, "%s", mensajeCifrado);
    fclose(archivo);
    printf("Mensaje cifrado guardado en 'mensaje_cifrado.txt'\n");
}

// Función para guardar la clave en archivo
void guardarClave(int *clave, int longitud) {
    FILE *archivo = fopen("clave.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo de la clave.\n");
        return;
    }
    
    fprintf(archivo, "%d\n", longitud);
    for (int i = 0; i < longitud; i++) {
        fprintf(archivo, "%d ", clave[i]);
    }
    fclose(archivo);
    printf("Clave guardada en 'clave.txt'\n");
}

// Función para cargar mensaje cifrado desde archivo
int cargarMensajeCifrado(char *mensajeCifrado) {
    FILE *archivo = fopen("mensaje_cifrado.txt", "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo 'mensaje_cifrado.txt'\n");
        return -1;
    }
    
    int longitud;
    fscanf(archivo, "%d\n", &longitud);
    fgets(mensajeCifrado, MAX_LENGTH, archivo);
    
    // Remover el salto de línea si existe
    if (mensajeCifrado[strlen(mensajeCifrado) - 1] == '\n') {
        mensajeCifrado[strlen(mensajeCifrado) - 1] = '\0';
    }
    
    fclose(archivo);
    return longitud;
}

// Función para cargar clave desde archivo
int cargarClave(int *clave) {
    FILE *archivo = fopen("clave.txt", "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo 'clave.txt'\n");
        return -1;
    }
    
    int longitud;
    fscanf(archivo, "%d", &longitud);
    
    for (int i = 0; i < longitud; i++) {
        fscanf(archivo, "%d", &clave[i]);
    }
    
    fclose(archivo);
    return longitud;
}

// Función para eliminar archivos automáticamente
void eliminarArchivos() {
    if (remove("clave.txt") == 0) {
        printf("Archivo 'clave.txt' eliminado automaticamente.\n");
    } else {
        printf("Error al eliminar 'clave.txt'\n");
    }
    
    if (remove("mensaje_cifrado.txt") == 0) {
        printf("Archivo 'mensaje_cifrado.txt' eliminado automaticamente.\n");
    } else {
        printf("Error al eliminar 'mensaje_cifrado.txt'\n");
    }
}

// Función principal de cifrado
void procesoCifrado() {
    char mensaje[MAX_LENGTH];
    char mensajeCifrado[MAX_LENGTH];
    int clave[MAX_LENGTH];
    
    printf("\n=== CIFRADO VERNAM ===\n");
    printf("Ingrese el mensaje a cifrar: ");
    fgets(mensaje, MAX_LENGTH, stdin);
    
    // Remover el salto de línea
    if (mensaje[strlen(mensaje) - 1] == '\n') {
        mensaje[strlen(mensaje) - 1] = '\0';
    }
    
    int longitud = strlen(mensaje);
    printf("Longitud del mensaje: %d caracteres\n", longitud);
    
    // Generar clave aleatoria
    generarClave(clave, longitud);
    
    // Cifrar mensaje
    cifrarMensaje(mensaje, clave, mensajeCifrado, longitud);

    printf("Mensaje cifrado:  %s\n", mensajeCifrado);
    
    // Guardar archivos
    guardarMensajeCifrado(mensajeCifrado, longitud);
    guardarClave(clave, longitud);
}

// Función principal de descifrado
void procesoDescifrado() {
    char mensajeCifrado[MAX_LENGTH];
    char mensajeOriginal[MAX_LENGTH];
    int clave[MAX_LENGTH];
    
    printf("\n=== DESCIFRADO VERNAM ===\n");
    
    // Cargar mensaje cifrado
    int longitudMensaje = cargarMensajeCifrado(mensajeCifrado);
    if (longitudMensaje == -1) return;
    
    // Cargar clave
    int longitudClave = cargarClave(clave);
    if (longitudClave == -1) return;
    
    if (longitudMensaje != longitudClave) {
        printf("Error: Las longitudes del mensaje y la clave no coinciden.\n");
        return;
    }
    
    // Descifrar mensaje
    descifrarMensaje(mensajeCifrado, clave, mensajeOriginal, longitudMensaje);
    
    printf("Mensaje cifrado:   %s\n", mensajeCifrado);
    printf("Mensaje descifrado: %s\n", mensajeOriginal);
    
    // Eliminar archivos automáticamente después de usarlos
    printf("\nEliminando archivos utilizados...\n");
    eliminarArchivos();
}

// Función para mostrar el menú
void mostrarMenu() {
    printf("\n==============================\n");
    printf("    CIFRADO VERNAM (OTP)       \n");
    printf("==============================\n");
    printf("1. Cifrar mensaje\n");
    printf("2. Descifrar mensaje\n");
    printf("3. Salir\n");
    printf("==============================\n");
    printf("Seleccione una opcion: ");
}

int main() {
	setlocale(LC_ALL, "spanish");
	int opcion;
    do {
        mostrarMenu();
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer
        
        switch (opcion) {
            case 1:
                procesoCifrado();
                break;
            case 2:
                procesoDescifrado();
                break;
            case 3:
                printf("Hasta luego\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
        
    } while (opcion != 3);
    
    return 0;
}
