import java.util.*;
public class App {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        Estoque est = new Estoque();

        int x=in.nextInt();
        switch (x) {
            case 1:
                Produto prd = new Produto();
                System.out.println("Digite o nome do produto: ");
                prd.setNome(in.nextLine());
                System.out.println("Digite o preco do produto: ");
                prd.setPreco(in.nextDouble());
                System.out.println("Digite a quantidade do produto: ");
                prd.setQntd(in.nextInt());
                if(est.adicionar(prd)){
                    System.out.println("Add com sucesso!");
                }
                else{
                    System.out.println("Invalido ou ja existente!");
                }
                break;
        
            case 2:
                //listar o produto
                est.buscar(in.nextLine());
                break;

            case 3:
                if(est.remover(in.nextLine())){
                    System.out.println("Removida com sucesso!");
                }
                else
                    System.out.println("Item não encontrado!");
                break;

            case 4:
                est.buscar(in.nextLine());
            default:
                break;
        }
    }
}
