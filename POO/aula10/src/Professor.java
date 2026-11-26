public class Professor extends Funcionario{
    private int horaH;
    private double Vhora;

    public Professor(String nome, String matricula, double salario, int horaH, double Vhora){
        super(nome, matricula, salario);
        this.horaH = horaH;
        this.Vhora = Vhora;
    }

    @Override
    public double calcSalario(){
        return super.calcSalario() + (double)horaH*Vhora;
    }

}
