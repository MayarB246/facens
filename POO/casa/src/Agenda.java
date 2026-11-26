import java.util.*;

public class Agenda {
    Scanner in = new Scanner(System.in);
    ArrayList<Contato> contato = new ArrayList<>();

    public void addContato(String nome, String ender, String email, String num){
        contato.add(new Contato(nome, ender, email, num));
    }
    public void addContato(){
        Contato cont = new Contato();
        System.out.println("Digite o seu nome: ");
        cont.setNome(in.nextLine());
        System.out.println("Digite o seu endereco: ");
        cont.setEnder(in.nextLine());
        System.out.println("Digite o seu email: ");
        cont.setEmail(in.nextLine());
        System.out.println("Digite o seu numero: ");
        cont.setNum(in.nextLine());

        contato.add(cont);
    }

    public void procura(String nome){
        int i=0;
        for(Contato cont : contato){
            if(cont.getNome().equals(nome)){
                System.out.println("Indice : "+i);
                cont.mostra();
            }
            i++;
        }
    }

    public void excluir(int num){
        contato.remove(num);
    }

    public void modificar(int num){
        int x;
        System.out.println("Qual dado deseja modificar:\n1 - Nome\n2 - Endereco\n3 - E-mail\n4 - Numero");
        x = in.nextInt();
        in.nextLine();
        switch (x){
            case 1:
                System.out.println("Digite o novo nome: ");
                contato.get(num).setNome(in.nextLine());
                break;
            case 2:
                System.out.println("Digite o novo endereco: ");
                contato.get(num).setEnder(in.nextLine());
                break;
            case 3:
                System.out.println("Digite o novo E-mail: ");
                contato.get(num).setEmail(in.nextLine());
                break;
            case 4:
                System.out.println("Digite o novo numero: ");
                contato.get(num).setNum(in.nextLine());
                break;
            default:
                System.out.println("Opcao invalida!\n\n");
                break;
        }
    }

    public void mostraContatos(){
        int x=0;
        for(Contato i : contato){
            x++;
            System.out.println("\n\n-------------------------\n");
            System.out.println("Contato "+x+" :\n");
            System.out.println("\nNome : "+i.getNome()+"\nEndereco : "+i.getEnder()+"\nE-mail : "+i.getEmail()+"\nNumero : "+ i.getNum());
        }
    }

    public void listaCont(Contato cont){
        System.out.println("Nome: "+cont.getNome());
        System.out.println("\nEndereco: "+cont.getEnder());
        System.out.println("\nE-mail: "+cont.getEmail());
        System.out.println("\nNumero: "+cont.getNum());
        System.out.println("\n\n-------------------------\n");
    }
}