package facens.POO.vetores;

import java.util.*;

public class app {
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        Scanner inStr = new Scanner(System.in);
        Vinho vinhos[] = new Vinho[3];
        String nome;
        String tipo;
        int ano;
        double preco;

        for(int i=0;i<vinhos.length;i++){
            System.out.println("Insira o nome do vinho "+ (i+1) + ": ");
            nome = inStr.nextLine();
            System.out.println("Insira o tipo do vinho "+ (i+1) + ": ");
            tipo = inStr.nextLine();
            System.out.println("Insira o Ano de fabricacao do vinho "+ (i+1) + ": ");
            ano = in.nextInt();
            System.out.println("Insira o preco do vinho "+ (i+1) + ": ");
            preco = in.nextDouble();

            vinhos[i] = new Vinho(nome, tipo, ano, preco);
        }

        Vinho vinhoCaro = vinhos[0];
        for(int i=0;i<vinhos.length;i++){
            if(vinhoCaro.getPreco()<=vinhos[i].getPreco()){
                vinhoCaro = vinhos[i];
            }
        }

        System.out.println("O vinho mais caro eh o: "+ vinhoCaro.getNome() + " com preco igual a " + vinhoCaro.getPreco());

    }
}
