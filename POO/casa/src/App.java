import java.util.*;
public class App {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        Agenda agenda = new Agenda();

        int x , ind;
        System.out.println("\n\n-------------------------\n");
        System.out.println("Digite qual operacao deseja realizar:\n1 - Cadastrar novo contato\n2 - Buscar contato usando Nome\n3 - Excluir objeto no indice informado\n4 - Modificar objeto no indice informado\n5 - Listar contatos\n6 - Sair");
        x = in.nextInt();

        if(x!=6){

            do{
                in.nextLine();
                switch (x) {
                    case 1:
                        agenda.addContato();
                        break;
                    case 2:
                        System.out.println("Digite o nome a buscar: ");
                        agenda.procura(in.nextLine());
                        break;
                    case 3:
                        System.out.println("Digite o indice do contato: ");
                        ind = in.nextInt();
                        if(ind >= 0 && ind < agenda.contato.size())
                            agenda.excluir(ind);
                        else
                            System.out.println("Fora do limite do indice!");
                        break;
                    case 4:
                        System.out.println("Digite o indice do contato: ");
                        ind = in.nextInt();
                        if(ind >= 0 && ind < agenda.contato.size())
                            agenda.modificar(ind);
                        else
                            System.out.println("Fora do limite do indice!");
                        break;
                    case 5:
                        agenda.mostraContatos();
                        break;
                    default:
                        System.out.println("Opcao invalida!\n\n");
                        break;
                }
                System.out.println("\n\n-------------------------\n");
                System.out.println("Digite qual operacao deseja realizar:\n1 - Cadastrar novo contato\n2 - Buscar contato usando Nome\n3 - Excluir objeto no indice informado\n4 - Modificar objeto no indice informado\n5 - Listar contatos\n6 - Sair");
                x = in.nextInt();
            }while (x!=6);
        }
        else{
            System.out.println("Fora do limite do indice!");
        }

    }
}