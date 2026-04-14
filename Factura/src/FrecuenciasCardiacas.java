public class FrecuenciasCardiacas {
    private String nombre;
    private String apellido;
    private int diaNacimiento;
    private int mesNacimiento;
    private int anioNacimiento;


    public FrecuenciasCardiacas(String nombre, String apellido, int dia, int mes, int anio) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.diaNacimiento = dia;
        this.mesNacimiento = mes;
        this.anioNacimiento = anio;
    }

    public String getNombre (){return nombre;}
    public String getApellido (){return apellido;}
    public int getDiaNacimiento (){return diaNacimiento;}
    public int getAnioNacimiento() {return mesNacimiento;}
    public int getMesNacimiento() {return anioNacimiento;}

    public void establecerNombre(String nombre) { this.nombre = nombre; }
    public void establecerApellido(String apellido) { this.apellido = apellido; }
    public void establecerDiaNacimiento(int dia) { this.diaNacimiento = dia; }
    public void establecerMesNacimiento(int mes) { this.mesNacimiento = mes; }
    public void establecerAnioNacimiento(int anio) { this.anioNacimiento = anio; }

    public int calcularEdad(){
        int anioActual = 2026;
        return anioActual - anioNacimiento;
    }
    public int calcularFrecuenciaMaxima() {
        return 220 - calcularEdad();
    }

    public String calcularFrecuenciaEsperada() {
        int max = calcularFrecuenciaMaxima();
        double rangoMin = max * 0.50;
        double rangoMax = max * 0.85;
        return (int)rangoMin + " - " + (int)rangoMax + " pulsos por minuto";
    }
}
