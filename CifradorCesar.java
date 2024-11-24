package libCifrador;

public class CifradorCesar {

    public native String cifrarCesar(String texto, int desplazamiento);
    public native String descifrarCesar(String texto, int desplazamiento);

    static {
        System.loadLibrary("Cifrador"); // Cargar la biblioteca nativa
    }

    public static void main(String[] args) {
        CifradorCesar cifrador = new CifradorCesar();

        String textoOriginal = "Hola estas probando tu libreria de codigo cesar";
        int desplazamiento = 3;

        String textoCifrado = cifrador.cifrarCesar(textoOriginal, desplazamiento);
        System.out.println("Texto cifrado: " + textoCifrado);

        String textoDescifrado = cifrador.descifrarCesar(textoCifrado, desplazamiento);
        System.out.println("Texto descifrado: " + textoDescifrado);
    }

}
