package facens.POO.vetores2;

import java.util.*;

public class app {
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        habitante pessoa[] = new habitante[3];
        double salario;
        int idade, numFilhos;
    
        for(int i=0;i<pessoa.length;i++){
            System.out.println("Digite o seu salario: ");
            salario = in.nextDouble();
            System.out.println("Digite sua idade: ");
            idade = in.nextInt();
            System.out.println("Digite quantos filhos voce tem: ");
            numFilhos = in.nextInt();

            pessoa[i] = new habitante(salario, idade, numFilhos);
        }
    
        double somaSalario = 0;
        double maiorSalario = pessoa[0].getSalario();
        int somaNumFilhos = 0;

        for(int i=0;i<pessoa.length;i++){
            somaSalario = pessoa[i].getSalario();
            if (maiorSalario<pessoa[i].getSalario()){
                maiorSalario = pessoa[i].getSalario();
            }
        }

        for(int i=0;i<pessoa.length;i++){
            somaNumFilhos = pessoa[i].getNumFilhos();
        }

        System.out.println("A media dos salarios eh: "+ (somaSalario/pessoa.length));
        System.out.println("O maior salario eh: "+ maiorSalario);
        System.out.println("A media do numero de filhos eh: "+ (somaNumFilhos/pessoa.length));    
    }
}
