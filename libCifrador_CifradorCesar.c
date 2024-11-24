#include <jni.h>
#include "libCifrador_CifradorCesar.h"
#include <ctype.h>
#include <string.h>

JNIEXPORT jstring JNICALL Java_libCifrador_CifradorCesar_cifrarCesar
  (JNIEnv * env, jobject obj, jstring texto, jint desplazamiento){

    const char* textoNativo = (*env)->GetStringUTFChars(env, texto, 0);
    int len = strlen(textoNativo);
    char resultado[len + 1];
    
    for (int i = 0; i < len; i++) {
        char letra = textoNativo[i];
        if (isupper(letra)) {
            resultado[i] = (char)(((int)letra + desplazamiento - 65) % 26 + 65);
        } else if (islower(letra)) {
            resultado[i] = (char)(((int)letra + desplazamiento - 97) % 26 + 97);
        } else {
            resultado[i] = letra;
        }
    }
    resultado[len] = '\0';
    (*env)->ReleaseStringUTFChars(env, texto, textoNativo);
    return (*env)->NewStringUTF(env, resultado);

}


JNIEXPORT jstring JNICALL Java_libCifrador_CifradorCesar_descifrarCesar
  (JNIEnv * env, jobject obj, jstring texto, jint desplazamiento){
    return Java_libCifrador_CifradorCesar_cifrarCesar(env, obj, texto, -desplazamiento);

}
