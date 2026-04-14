import java.util.Scanner;

class Sistem {
    public void ejecutar() {
        Scanner entrada = new Scanner(System.in);

        System.out.print("Escriba el nombre: ");
        String nombre = entrada.nextLine();

        System.out.print("Escriba el apellido: ");
        String apellido = entrada.nextLine();

        System.out.println("Ingrese fecha de nacimiento:");
        System.out.print("Día: ");
        int dia = entrada.nextInt();
        System.out.print("Mes: ");
        int mes = entrada.nextInt();
        System.out.print("Año: ");
        int anio = entrada.nextInt();

        FrecuenciasCardiacas persona = new FrecuenciasCardiacas(nombre, apellido, dia, mes, anio);

        System.out.println("\n--- RESULTADOS ---");
        System.out.println("Nombre: " + persona.getNombre() + " " + persona.getApellido());
        System.out.println("Fecha de Nacimiento: " + persona.getDiaNacimiento() + "/" +
                persona.getMesNacimiento() + "/" + persona.getAnioNacimiento());

        System.out.println("Edad: " + persona.calcularEdad() + " años");
        System.out.println("Frecuencia Cardiaca Máxima: " + persona.calcularFrecuenciaMaxima());
        System.out.println("Rango esperado (50%-85%): " + persona.calcularFrecuenciaEsperada());
    }
}