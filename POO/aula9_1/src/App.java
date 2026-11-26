import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        ArrayList<Funcionario> empresa = new ArrayList<>();
        Funcionario f1 = new Funcionario("Fernando", "123", 1000);
        empresa.add(f1);

        Funcionario g1 = new Gerente("Gabriel", "234", 2000, "Manutencao");
        empresa.add(g1);

        Funcionario v1 = new Vendedor("Rafael", "345", 1500, 300);
        empresa.add(v1);

        for(Funcionario i : empresa){
            i.imprimir();
            System.out.println("\nSalario liquido: "+i.calcSalarioLiq());
            System.out.println("___________________________________");
        }
    }
}
