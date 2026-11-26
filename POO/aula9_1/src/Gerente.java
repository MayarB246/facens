public class Gerente extends Funcionario{
    private String area;

    public Gerente(String nome, String cpf, double salario, String area){
        super(nome, cpf, salario);
        this.area = area;
    }

    public String getArea(){
        return area;
    }

    public void imprimir(){
        System.out.println("Nome: "+getNome());
        System.out.println("CPF: "+getCPF());
        System.out.println("Salario: "+getSalario());
        System.out.println("Area: "+ getArea());
    }

    public double calcularImposto(){
        return getSalario()*0.2;
    }
}
