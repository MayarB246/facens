public class Gato extends Animal{
    private boolean precisaAreia;

    public Gato(String nome, int idade, boolean precisaAreia){
        super(nome, idade);
        this.precisaAreia = precisaAreia;
    }

    public boolean precisaAreiaGato(){
        return precisaAreia;
    }

}

