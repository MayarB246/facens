import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        Cachorro c1 = new Cachorro("Rex", 3, false);

        // System.out.println("Nome: "+c1.getNome());
        // System.out.println("Idade: "+c1.getIdade());
        // System.out.println("Tem pulga?"+ c1.temPulgaCach());
        // c1.emitirSom();

        // System.out.println("--------------------------------");
        
        // c1.imprimir();

        ArrayList<Animal> petShop = new ArrayList<>();
        petShop.add(c1);
        Gato g1 = new Gato("Alice", 1, false);
        petShop.add(g1);
        
        for (Animal i : petShop){
            i.emitirSom();
            System.out.println("______________________________");
        }
        
    }
}
