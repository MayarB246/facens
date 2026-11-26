public class Funcionario {
    private String nome;
    private String matricula;
    private double salario;

    public Funcionario(String nome, String matricula, double salario){
        if (salario<=0) {
            System.out.println("Salario invalido\n\n");
        }
        else{
            this.nome = nome;
            this.matricula = matricula;
            this.salario = salario;
        }
    }

    public String getNome(){
        return nome;
    }
    public String getMatricula(){
        return matricula;
    }
    public double getSalario(){
        return salario;
    }

    public double calcSalario(){
        return salario;
    }

    public void resumo(){
        System.out.printf("Nome: %s | Matricula: %s | Salario inteiro: RS%.2f%n", getNome(), getMatricula(), calcSalario());
    }
}
