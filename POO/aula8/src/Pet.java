import java.util.ArrayList;

public class Pet {
    private String nome;
    private String especie;
    private int idade;
    private Tutor tutor;
    public ArrayList<Tutor> tutores = new ArrayList<>();


    public Pet(String nome, String especie, int idade){
        this.nome = nome;
        this.especie = especie;
        this.idade = idade;
    
    }

    public void exibirFicha(){
        System.out.println("\nNome: "+ nome);
        System.out.println("Especie: "+ especie);
        System.out.println("Idade: "+ idade);

        for(int i =0; i < tutores.size(); i++) {
        System.out.println("\nNome: "+ tutores.get(i).getNome());
        System.out.println("Numero: "+ tutores.get(i).getTelefone());
        }
        System.out.println("---------------------------------");
    }

    public void trocarTutor(Tutor novoTutor){
        tutor = novoTutor;
    }

    public void cadastrarTutor(Tutor t) {
        tutores.add(t); 
    }

    
}