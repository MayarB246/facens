public class Coordenador extends Funcionario{
    private double perc;
    public Coordenador(String nome, String matricula, double salario, double perc){
        super(nome, matricula, salario);
        this.perc = perc;
    }

    @Override
    public double calcSalario(){
        return getSalario() * (1+perc);
    }
}
