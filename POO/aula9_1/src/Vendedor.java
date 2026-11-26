public class Vendedor extends Funcionario{
    private double comissao;

    public Vendedor(String nome, String cpf, double salario, double comissao){
        super(nome, cpf, salario);
        this.comissao = comissao;
    }

    public double getComissao(){
        return comissao;
    }

    public void imprimir(){
        System.out.println("Nome: "+getNome());
        System.out.println("CPF: "+getCPF());
        System.out.println("Salario: "+getSalario());
        System.out.println("Comissao: "+getComissao());
    }

    public double calcSalarioLiq(){
        return (getSalario()-calcularImposto()) + comissao;
    }
}
