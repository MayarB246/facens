public class Animal {
    private String nome;
    protected  int idade;

    public Animal(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }

    public void emitirSom(){
        System.out.println("Som generico!!!");
    }

    public String getNome(){
        return nome;
    }
    
    public int getIdade(){
        return idade;
    }
}
