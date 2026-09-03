import java.util.*;
public class calcul{
    Scanner in = new Scanner(System.in);

    public int opcao(){
        int op;
        System.out.println("Digite: 1 para soma | 2 para subtracao | 3 para multiplicacoo | 4 para divisao");
        op = in.nextInt();
        return op;
    }
/* 
    public void leia(){
        System.out.println("Digite o valor do primeiro numero: ");
        this.a = in.nextInt();
        System.out.println("Digite o valor do segundo numero: ");
        this.b = in.nextInt();
    }
*/
    public int calcular(int op){
        int a, b;
        float r=0f;
        System.out.println("Digite o primeiro numero: ");
        a = in.nextInt();
        System.out.println("Digite o segundo numero: ");
        b = in.nextInt();
        
        switch (op) {
            case 1:
                r = (float)a + b;
                break;
            case 2:
                r = (float)a - b;
                break;
            case 3:
                r = (float)a * b;
                break;
            case 4:
                r = (float)a / b;
                break;
            default:
                break;
        }

        return (int)r;
    }

    public void finalizar(float res){
        System.out.println("O resultado da operacao e: "+ res);
    }
}