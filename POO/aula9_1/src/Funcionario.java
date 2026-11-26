public class Funcionario {
    private String nome;
    private String cpf;
    private double salario;
    private double imposto;

    public Funcionario(String nome, String cpf, double salario){
        this.nome = nome;
        this.cpf = cpf;
        this.salario = salario;
    }

    public String getNome() {
        return nome;
    }

    public String getCPF(){
        return cpf;
    }

    public double getSalario(){
        return salario;
    }

    public void imprimir(){
        System.out.println("Nome: "+getNome());
        System.out.println("CPF: "+getCPF());
        System.out.println("Salario: "+getSalario());
    }

    public double calcularImposto(){
        return getSalario()*0.1;
    }

    public double calcSalarioLiq(){
        return salario-calcularImposto();
    }
    
}
