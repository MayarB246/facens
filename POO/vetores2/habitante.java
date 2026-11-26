package facens.POO.vetores2;

public class habitante {
    private double salario;
    private int idade, numFilhos;
    
    public habitante(double salario, int idade, int numFilhos){
        if(salario>0){
            this.salario = salario;
        }
        else{
            salario = 0;
        }
        this.idade = idade;
        this.numFilhos = numFilhos;
    }

    public void setSalario(double salario){
        this.salario = salario;
    }
    public double getSalario(){
        return salario;
    }

    public void setIdade(int idade){
        this.idade = idade;
    }
    public int getIdade(){
        return idade;
    }

    public void setNumFilhos(int numFilhos){
        this.numFilhos = numFilhos;
    }
    public int getNumFilhos(){
        return numFilhos;
    }   


}
