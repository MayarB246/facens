import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        ArrayList<Pet> pets = new ArrayList<>();

        pets.add(new Pet("Thor", "Cao", 4));
        pets.add(new Pet("Mel", "Gato", 2));
        pets.add(new Pet("Pacoca", "Cao", 7));

        
        Tutor t1 = new Tutor("Ana Ribeiro", "XXXXXX");
        Tutor t2 = new Tutor ("Bruno Costa", "123456"); 
        Tutor t3 = new Tutor ("Carla Mendes", "abcdef");
        

        pets.get(0).cadastrarTutor(t1);
        pets.get(1).cadastrarTutor(t2);
        pets.get(1).cadastrarTutor(t3);
        pets.get(2).cadastrarTutor(t2);
        pets.get(2).trocarTutor(t3);

        pets.get(0).exibirFicha();
        pets.get(1).exibirFicha();
        pets.get(2).exibirFicha();
    }
}