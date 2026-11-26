import java.util.ArrayList;

public class folha {
    private ArrayList<Funcionario> funcio = new ArrayList<>();

    public void adicionar(Funcionario f){
        if(f!=null){
            funcio.add(f);
        }
    }

    public double calcTotal(){
        double x=0;
        for(Funcionario f : funcio){
            x+=f.calcSalario();
        }
        return x;
    }

    public void listar(){
        for(Funcionario f : funcio){
            f.resumo();
        }
    }
}
